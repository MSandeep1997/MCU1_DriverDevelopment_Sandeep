/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: 14-Feb-2021
 *      Author: sande
 */

// SPI clock configuration
#include"stm32f407xx_spi_driver.h"

/******************************************************************************************
 *
 * @fn             - SPI_PeriClockControl
 *
 * @Brief          - This function Enable or Disable the clock control for a given SPI
 *
 * @Param[in]      - Base address of the SPI peripheral
 * @Param[in]      - Enable or Disable
 * @Param[in]      -
 *
 * @Return         -
 *
 * @Note           -
 *
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if(pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if(pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}
	}
	else
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_DI();
		}
		else if(pSPIx == SPI2)
		{
			SPI2_PCLK_DI();
		}
		else if(pSPIx == SPI3)
		{
			SPI3_PCLK_DI();
		}
	}

}

/******************************************************************************************
 *
 * @fn             - SPI_Init
 *
 * @Brief          - This function Initialize a given SPI
 *
 * @Param[in]      - Handle Structure of the SPI
 * @Param[in]      -
 * @Param[in]      -
 *
 * @Return         -
 *
 * @Note           -
 *
 */

// SPI Initialization and Deinitialization

void SPI_Init(SPI_Handle_t *pSPIHandle)
{
	//Enable the Clock
	SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);

	uint32_t tempreg = 0;

	//1. Configure Device Mode
	tempreg |= pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR ;

	//2. Bus Configure
	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		//BIDI mode should be clear i.e unidirectional two bus communication
		tempreg &= ~(1 << SPI_CR1_BIDI);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
			{
		//BIDI mode should be set
		tempreg |= (1 << SPI_CR1_BIDI);
			}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		//BIDI mode should be Clear
		tempreg &= ~(1 << SPI_CR1_BIDI);
		//Rx Only Mode will be set
		tempreg |= (1 << SPI_CR1_RX);
	}
	//3.Sclk Speed Configuration
	tempreg |= pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;

	//4.Data-Bit Transfer Configuration
	tempreg |= pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF;

	//5.Configure CPOL
	tempreg |= pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL;

	//6. Configure CPHA
	tempreg |= pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA;

	tempreg |= pSPIHandle->SPIConfig.SPI_SSM << SPI_CR1_SSM;

	pSPIHandle->pSPIx->CR1 = tempreg;

}

/******************************************************************************************
 *
 * @fn             - SPI_DeInit
 *
 * @Brief          - This function Initialize a given SPI
 *
 * @Param[in]      - Structure containing all the Registers required to setup the SPI
 * @Param[in]      -
 * @Param[in]      -
 *
 * @Return         -
 *
 * @Note           -
 *
 */
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{
	if (pSPIx == SPI1)
	{
		SPI1_REG_RESET();
	}
	else if (pSPIx == SPI2)
	{
		SPI2_REG_RESET();
	}
	else if (pSPIx == SPI3)
	{
		SPI3_REG_RESET();
	}

}

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
	if (pSPIx->SR & FlagName)
	{
		return SPI_FLAG_SET;
	}
	else
	{
		return SPI_FLAG_RESET;
	}

}
/******************************************************************************************
 *
 * @fn             - SPI_SendData
 *
 * @Brief          - This function setup the SPI to send data
 *
 * @Param[in]      - Structure to modify the register of the SPI
 * @Param[in]      - pointer pointing Tx Buffer
 * @Param[in]      - Length of the data to be transmitted (8 Bit or 16 Bit at a time)
 *
 * @Return         -
 *
 * @Note           - This is a Blocking Call
 *
 */
// SPI send and receive data

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
	while (Len > 0)
	{
		//1. wait until TXE is SET
		while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG) == SPI_FLAG_RESET);

		//2. Check the DFF bit in CR1

		if (pSPIx->CR1 & (1 << SPI_CR1_DFF))
		{
			// 16 Bit data Format
			//1. load the data into the DR
			pSPIx->DR = *((uint16_t*)pTxBuffer);// type casted to uint16_t in order to transmit 2 byte of data and then dereference to load that data

			// decrement two times since 2 byte of data
			Len--;
			Len--;
			//increment the pointer in order to point the Next data. Incremented by two bytes that is why type casted first then increment
			(uint16_t*)pTxBuffer++;
		}
		else
		{
			// 8 Bit Data Format
			pSPIx->DR = *pTxBuffer;

			Len--;

			pTxBuffer++;
		}
	}

}

/******************************************************************************************
 *
 * @fn             - SPI_ReceiveData
 *
 * @Brief          - This function setup the SPI to receive data
 *
 * @Param[in]      - Structure to modify the register of the SPI
 * @Param[in]      - pointer pointing Rx Buffer
 * @Param[in]      - Length of the data to be received (8 Bit or 16 Bit at a time)
 *
 * @Return         -
 *
 * @Note           -
 *
 */
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{

}

/******************************************************************************************
 *
 * @fn             - SPI_IRQInterruptConfig
 *
 * @Brief          - This function Configure for Interrupt
 *
 * @Param[in]      - IRQ Number
 * @Param[in]      - Enable or Disable
 * @Param[in]      -
 *
 * @Return         -
 *
 * @Note           -
 *
 */
// SPI interrupt configuratiion and handling

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

}

/******************************************************************************************
 *
 * @fn             - SPI_IRQInterruptPriority
 *
 * @Brief          - This function Configure for Interrupt priority
 *
 * @Param[in]      - IRQ Number
 * @Param[in]      - IRQ Priority
 * @Param[in]      -
 *
 * @Return         -
 *
 * @Note           -
 *
 */
void SPI_IRQInterruptPriority(uint8_t IRQNumber, uint8_t IRQPriority)
{

}

/******************************************************************************************
 *
 * @fn             - SPI_IRQHandle
 *
 * @Brief          - This function is the Handler of the Interrupt when the pend bit will be clear
 *
 * @Param[in]      - SPI Handle structure
 * @Param[in]      -
 * @Param[in]      -
 *
 * @Return         -
 *
 * @Note           -
 *
 */
void SPI_IRQHandle(SPI_Handle_t *pSPIx)
{

}

void SPI_PeriConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		pSPIx->CR1 |= (1 << SPI_CR1_SPE);
	}
	else
	{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
	}
}


void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		pSPIx->CR1 |= (1 << SPI_CR1_SSI);
	}
	else
	{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SSI);
	}
}

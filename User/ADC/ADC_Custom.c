//
// Created by Penta on 2025/7/25.
//
#include <stdio.h>

#include "ADC_Custom.h"

#include "Serial.h"

uint32_t g_adc1_dma_data1[ADC_DATA_LENGTH];//Store the data from adc1
uint8_t g_adc1_dma_complete_flag = 0;//dma cplt flag, controlled in dma_conv_cplt_callback


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if(hadc->Instance==ADC1)
    {
        g_adc1_dma_complete_flag = 2;
    }
}


void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)
{
    Serial_printf("halfconv\r\n");
    if(hadc->Instance==ADC1)
    {
        g_adc1_dma_complete_flag = 1;
    }
}


void ADC_DMA_Output(void)
{
    //Serial_printf("ADCDMA\r\n");
    if(g_adc1_dma_complete_flag == 1)//part1 of the data
    {
        //Serial_printf("dma1\r\n");
        for(uint32_t itor_dma=0;itor_dma<1000;itor_dma++)
        {
            Serial_printf_t(huart_screen,"%ld\r\n",g_adc1_dma_data1[itor_dma]&0x0000ffff);//
        }
        g_adc1_dma_complete_flag = 0;
        memset(&g_adc1_dma_data1[0],0,ADC_DATA_LENGTH/2);//Clear the stored data
    }
    if(g_adc1_dma_complete_flag == 2)//part2
    {
        for(uint32_t itor_dma=1000;itor_dma<2000;itor_dma++)
        {
            Serial_printf_t(huart_screen,"%ld\r\n",g_adc1_dma_data1[itor_dma]&0x0000ffff);//
        }
        g_adc1_dma_complete_flag = 0;
        memset(&g_adc1_dma_data1[1000],0,ADC_DATA_LENGTH/2);//Clear the stored data
    }
}


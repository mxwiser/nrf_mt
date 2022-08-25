//
// Created by master on 2022/7/19.
//
#include "startup.h"
//#include "libary/at24c02/at24c02.h"
//#include "usbd_cdc_if.h"
//#include "usart.h"

#include "spi.h"
#include "libary/nrf24l01p.h"




//// data array to be sent
//uint8_t tx_data[NRF24L01P_PAYLOAD_LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7};
//uint8_t ack_rx_data[8];
//// for rx interrupt
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
//
//void create(void)
//{
//    nrf24l01p_tx_init(2500, _1Mbps);
//    while (1)
//    {
//        // change tx datas
//        for(int i= 0; i < 8; i++)
//            tx_data[i]++;
//        // transmit
//        nrf24l01p_tx_transmit(tx_data);
//        HAL_Delay(100);
//    }
//}
//
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//    if(GPIO_Pin == NRF24L01P_IRQ_PIN_NUMBER)
//        nrf24l01p_tx_irq(ack_rx_data); // clear interrupt flag
//        CDC_Transmit_FS(ack_rx_data,8);
//}
//




// data array to be read
uint8_t rx_data[NRF24L01P_PAYLOAD_LENGTH] = { 0, };
uint8_t ack_data[NRF24L01P_PAYLOAD_LENGTH] = { 0, };
// for tx interrupt
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

void create(void)
{
    nrf24l01p_rx_init(2500, _2Mbps);

    while (1)
    {
        // Nothing to do
        HAL_Delay(100);

    }
}
void myOnAckIRQ(){

}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == NRF24L01P_IRQ_PIN_NUMBER){
        nrf24l01p_rx_receive(rx_data,ack_data,myOnAckIRQ); // read data when data ready flag is set
    }
}
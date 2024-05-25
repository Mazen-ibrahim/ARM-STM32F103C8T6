/**********************************************
 ********** Author: Mazen Ibrahim *************
 ********** Date : 5/5/2024       *************
 ********** Target: STM32F103C8T6 *************
 ********** SoftWare: SPI         *************
 ********** Version: 1.0          *************
 **********************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_
#include "SPI_private.h"

/*************
 Options:
    1-FIRST_CAP
    2-SECOND_CAP

***************/

#define CLK_PHASE          FIRST_CAP


/*************
 Options:
    1-LOW_IDLE
    2-HIGH_IDLE

***************/

#define CLK_POLARITY       LOW_IDLE


/*************
 Options:
    1-SLAVE
    2-MASTER

***************/

#define SPI_SELCECTION     SLAVE


/*************
 Options:
    1-MSB
    2-LSB

***************/
#define SPI_FRAME          MSB


/*************
 Options:
    1-SSMD
    2-SSME

***************/
#define SPI_SLAVE_MANGE    SSMD


/*************
 Options:
    1-FULL_DUPLEX
    2-OUT_Disable

***************/
#define SPI_TYPE          FULL_DUPLEX


/*************
 Options:
    1- _8DATA_BIT
    2- _16DATA_BIT

***************/
#define SPI_DFF            _8DATA_BIT





#endif /* SPI_CONFIG_H_ */

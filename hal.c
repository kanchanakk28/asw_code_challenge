//
// Created by Kanchana
//

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "hal.h"
#include "i2c.h"

bool Set_OutputDataRateConfig( output_date_rate data_rate)
{  
    if ((rate > conf_0_625_hz) || (rate <=conf_80_hz ))
    {
    	uint8_t current_conf =0;
    
    	if (i2c_read(BUS_ADDRESS, CTRL_REG1, REG_SIZE, &current_conf))
    		return false;
    
    	current_conf = (current_conf & 0b11110001) | (data_rate << 1);
    
    	if(i2c_write(BUS_ADDRESS, CTRL_REG1, REG_SIZE, &current_conf))
    		return false;
    
    	printf("configured rate = %d\n", current_conf);
    
    		return true;
    }
    return false;
} 


bool Get_OutputDataRateConfig(output_date_rate *data_rate)
{  

    if ( data_rate != NULL )
    {
    unit8_t rate = 0;
    if (i2c_read(BUS_ADDRESS, CTRL_REG1, REG_SIZE, &rate))
    return false;
    
    *data_rate = (rate & 0b00001110) >> 1 ;
    
    printf("configured rate = %d\n", data_rate);
    
    return true;
    }
    return false;
} 


bool Set_InteruptPinConfig(bool enable)
{ 
    uint8_t current_config = 0;
    
    if (i2c_read(BUS_ADDRESS, INT_CFG, REG_SIZE, &current_config))
    return false;
    
    current_config = (current_config & 0b11111110) | enable ;
    
    if (i2c_write(self_ptr->device_id, INT_CFG, REG_SIZE &current_config))
    return false;
    
    return true;
}

bool Get_FullScaleConfig(full_scale_t *fullscale)
{  
    if (self_ptr == NULL){
    return false;
    }
    
    uint8_t buffer=0;
    if (i2c_read(self_ptr->device_id, CTRL_REG2, REG_SIZE, &buffer))
    return false;
    
    
    *fullscale = (full_scale_t) ((buffer&0b01100000)>>5);
    
    printf("Configured fullscale value = %d\n", *fullscale);
    
    return true;
}

bool Get_ReadAxisConfig(axis_t axis, uint16_t* data_ptr) 
{
    if (axis > axis_x || axis < axis_z){
    return false;
    }
    
    uint8_t data[2] = {0,0};
    
    if (i2c_read(BUS_ADDRESS, axis, AXIS_SIZE, buffer))
    return false;
    
    *data_ptr = (uint16_t)((data[1] << 8) | data[0]);
    
    printf("configured axisData = %d\n", *data_ptr);
    
    return true;
}

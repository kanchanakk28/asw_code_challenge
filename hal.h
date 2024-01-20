//
// Created by Kanchana
//

#define       DEFAULT_ADDRESS    0x3d   
#define       CTRL_REG1         0x20 
#define       CTRL_REG2         0x21
#define       INT_CFG           0x30
#define       AXIS_SIZE          2   
#define       REG_SIZE           1  

typedef enum _output_date_rate{
    conf_0_625_hz=0,
    conf_1_25_hz,
    conf_2_5_hz,
    conf_5_hz,
    conf_10_hz, 
    conf_20_hz,
    conf_40_hz,
    conf_80_hz
}output_date_rate;

typedef enum _full_scale_t{
    FS_4g=0, 
    FS_8g, 
    FS_12g,
    FS_16g
}full_scale_t;


#define  X_REG   0x28    
#define  Y_REG   0x2A    
#define  Z_REG   0x2C 

typedef enum _axis_t {
    axis_x = X_REG,
    axis_y = Y_REG,
    axis_z = Z_REG
}axis_t;

/*set the output data rate*/
bool Set_OutputDataRateConfig( output_date_rate data_rate);

/*Get the output data rate*/
bool Get_OutputDataRateConfig(output_date_rate *data_rate);

/*Enable or disable the interrupt pin*/
bool Set_InteruptPinConfig(bool enable);

/*Get the full-scale configuration*/
bool Get_FullScaleConfig(full_scale_t *fullscale);

/*Read the output data of a specified axis*/
bool Get_AxisConfig(axis_t axis, uint16_t* data_ptr) ;


#include <stdio.h>
#include <string.h>


enum {
    test_logic_reset = 0,
    run_test_idle,

    select_dr_scan,
    capture_dr,
    shift_dr,
    exit1_dr,
    pause_dr,
    exit2_dr,
    update_dr,

    select_ir_scan,
    capture_ir,
    shift_ir,
    exit1_ir,
    pause_ir,
    exit2_ir,
    update_ir,

    num_states
};

static int jtag_step(int state, int tms)
{
    static const int next_state[num_states][2] =
    {
        [test_logic_reset] = {run_test_idle, test_logic_reset},
        [run_test_idle] = {run_test_idle, select_dr_scan},

        [select_dr_scan] = {capture_dr, select_ir_scan},
        [capture_dr] = {shift_dr, exit1_dr},
        [shift_dr] = {shift_dr, exit1_dr},
        [exit1_dr] = {pause_dr, update_dr},
        [pause_dr] = {pause_dr, exit2_dr},
        [exit2_dr] = {shift_dr, update_dr},
        [update_dr] = {run_test_idle, select_dr_scan},

        [select_ir_scan] = {capture_ir, test_logic_reset},
        [capture_ir] = {shift_ir, exit1_ir},
        [shift_ir] = {shift_ir, exit1_ir},
        [exit1_ir] = {pause_ir, update_ir},
        [pause_ir] = {pause_ir, exit2_ir},
        [exit2_ir] = {shift_ir, update_ir},
        [update_ir] = {run_test_idle, select_dr_scan} };

    return next_state[state][tms];
}


int main()
{
    for(int j=0;j<10;j++)
	{
		printf("Jenkins Cmake Demo\n");	
	}
    

/**
	printf("%d",jtag_step(0,1));
	printf("\n");
	
	
    __int32 JTAG_IR_Arr[64] = {0};
    __int32 JTAG_DR_Arr[64] = {0};

    __int32 JTAG_IR = 0x0FF;
    __int32 JTAG_DATA = 0x0;
    char IR_TDO_Out[1024] = {0};
    char DR_TDO_Out[1024] = {0};

    char *USART_RxBuffer = "009_0ff,032_0";

    // ==================USART Var==============================
    char receive_buff[1024] = {0};
    char receive_buff_CDC[1024] = {0};
    int buffer_index = 0;
    int IR_Flag = 1;

    int i = 0;
    int IR_Cnt_Arr[3] = {0};
    int DR_Cnt_Arr[3] = {0};

    int IR_Cnt = 0;
    int DR_Cnt = 0;

    int IR_Index = 0;
    int DR_Index = 0;


    int USART2_REC_OK = 1;
    int USB_CDC_IT_FLAG = 0;
    int IR_DATA_Flag = 0;
    int DR_DATA_Flag = 0;

    
    // if( 1 == USB_CDC_IT_FLAG ) // 如果USb CDC 串口接收到数据，就下发给JTAG
    if (1 == USART2_REC_OK) // 如果串口接收到数据，就下发给JTAG
    {
        IR_DATA_Flag = 0;
        DR_DATA_Flag = 0;
        USART2_REC_OK = 0;
        USB_CDC_IT_FLAG = 0;
        IR_Cnt = 0;
        DR_Cnt = 0;
        IR_Flag = 1; // IR,DR

        IR_Cnt_Arr[0] = -1;
        IR_Cnt_Arr[1] = -1;
        IR_Cnt_Arr[2] = -1;

        DR_Cnt_Arr[0] = -1;
        DR_Cnt_Arr[1] = -1;
        DR_Cnt_Arr[2] = -1;
        buffer_index = 0;
        i = 0;

        printf("%s\r\n", USART_RxBuffer);

        while (buffer_index < 64)
        {
            // printf("%d,",USART_RxBuffer[buffer_index]);

            if (USART_RxBuffer[buffer_index] == '\x0a')
                break;

            if (USART_RxBuffer[buffer_index] == ',')
            {
                IR_Flag = 0;
                buffer_index++;
            }

            // Get IR DR length 9_0ff
            if (i < 3 && IR_Flag == 1 && (int)USART_RxBuffer[buffer_index] >= 48 && (int)USART_RxBuffer[buffer_index] <= 57)
                IR_Cnt_Arr[i++] = (int)USART_RxBuffer[buffer_index] - 48;

            if (i < 3 && IR_Flag == 0 && (int)USART_RxBuffer[buffer_index] >= 48 && (int)USART_RxBuffer[buffer_index] <= 57)
                DR_Cnt_Arr[i++] = (int)USART_RxBuffer[buffer_index] - 48;

            if (USART_RxBuffer[buffer_index] == '_' && IR_Flag == 1)
            {
                printf("\r\nIR %d,%d,%d\r\n", IR_Cnt_Arr[0], IR_Cnt_Arr[1], IR_Cnt_Arr[2]);

                IR_DATA_Flag = 1;

                IR_Cnt = IR_Cnt_Arr[0] * 100  + IR_Cnt_Arr[1] * 10 + IR_Cnt_Arr[2] * 1;

                i = 0;
                buffer_index++;
            }

            if (USART_RxBuffer[buffer_index] == '_' && IR_Flag == 0)
            {
                printf("\r\nDR %d,%d,%d\r\n", DR_Cnt_Arr[0], DR_Cnt_Arr[1], DR_Cnt_Arr[2]);
                DR_DATA_Flag = 1;

                DR_Cnt = DR_Cnt_Arr[0] * 100  + DR_Cnt_Arr[1] * 10 + DR_Cnt_Arr[2] * 1;

                i = 0;
                buffer_index++;
            }

            // Get IR DR Data
            if (IR_Flag && IR_DATA_Flag)
            {
                JTAG_IR_Arr[IR_Index++] = USART_RxBuffer[buffer_index] - 48;
            }
            else if((IR_Flag == 0 && DR_DATA_Flag))
            {
                JTAG_DR_Arr[DR_Index++] = USART_RxBuffer[buffer_index] - 48;
            }

            buffer_index++;
        }
        printf("%d=%s %d=%s\r\n", IR_Cnt, JTAG_IR_Arr, DR_Cnt, JTAG_IR_Arr);
    }
	*/

    return 0;
}


#include "bsp.h"

void Tc358Write(void)
{
	
	
	// Initialization to receive HDMI signal
	// Software Reset
	i2c1_uh2d_write16(0x0004,0x0004); // ConfCtl0
	i2c1_uh2d_write16(0x0002,0x3F01); // SysCtl
	i2c1_uh2d_write16(0x0002,0x0000); // SysCtl
	i2c1_uh2d_write16(0x0006,0x0008); // ConfCtl1
	// DSI-TX0 Transition Timing
	i2c1_uh2d_write32(0x0108,0x00000001); // DSI_TX_CLKEN
	i2c1_uh2d_write32(0x010C,0x00000001); // DSI_TX_CLKSEL
	i2c1_uh2d_write32(0x02A0,0x00000001); // MIPI_PLL_CONTROL
	i2c1_uh2d_write32(0x02AC,0x000090BD); // MIPI_PLL_CNF
	Waitx1ms(1);
	i2c1_uh2d_write32(0x02A0,0x00000003); // MIPI_PLL_CONTROL
	i2c1_uh2d_write32(0x0118,0x00000014); // LANE_ENABLE
	i2c1_uh2d_write32(0x0120,0x00001770); // LINE_INIT_COUNT
	i2c1_uh2d_write32(0x0124,0x00000000); // HSTX_TO_COUNT
	i2c1_uh2d_write32(0x0128,0x00000101); // FUNC_ENABLE
	i2c1_uh2d_write32(0x0130,0x00010000); // DSI_TATO_COUNT
	i2c1_uh2d_write32(0x0134,0x00005000); // DSI_PRESP_BTA_COUNT
	i2c1_uh2d_write32(0x0138,0x00010000); // DSI_PRESP_LPR_COUNT
	i2c1_uh2d_write32(0x013C,0x00010000); // DSI_PRESP_LPW_COUNT
	i2c1_uh2d_write32(0x0140,0x00010000); // DSI_PRESP_HSR_COUNT
	i2c1_uh2d_write32(0x0144,0x00010000); // DSI_PRESP_HSW_COUNT
	i2c1_uh2d_write32(0x0148,0x00001000); // DSI_PR_TO_COUNT
	i2c1_uh2d_write32(0x014C,0x00010000); // DSI_LRX-H_TO_COUNT
	i2c1_uh2d_write32(0x0150,0x00000160); // FUNC_MODE
	i2c1_uh2d_write32(0x0154,0x00000001); // DSI_RX_VC_ENABLE
	i2c1_uh2d_write32(0x0158,0x000000C8); // IND_TO_COUNT
	i2c1_uh2d_write32(0x0168,0x0000002A); // DSI_HSYNC_STOP_COUNT
	i2c1_uh2d_write32(0x0170,0x00000478); // APF_VDELAYCNT
	i2c1_uh2d_write32(0x017C,0x00000081); // DSI_TX_MODE
	i2c1_uh2d_write32(0x018C,0x00000001); // DSI_HSYNC_WIDTH
	i2c1_uh2d_write32(0x0190,0x00000104); // DSI_HBPR
	i2c1_uh2d_write32(0x01A4,0x00000000); // DSI_RX_STATE_INT_MASK
	i2c1_uh2d_write32(0x01C0,0x00000015); // DSI_LPRX_THRESH_COUNT
	i2c1_uh2d_write32(0x0214,0x00000000); // APP_SIDE_ERR_INT_MASK
	i2c1_uh2d_write32(0x021C,0x00000080); // DSI_RX_ERR_INT_MASK
	i2c1_uh2d_write32(0x0224,0x00000000); // DSI_LPTX_INT_MASK
	i2c1_uh2d_write32(0x0254,0x00000006); // LPTXTIMECNT
	i2c1_uh2d_write32(0x0258,0x00240204); // TCLK_HEADERCNT
	i2c1_uh2d_write32(0x025C,0x000D0008); // TCLK_TRAILCNT
	i2c1_uh2d_write32(0x0260,0x00140006); // THS_HEADERCNT
	i2c1_uh2d_write32(0x0264,0x00004268); // TWAKEUPCNT
	i2c1_uh2d_write32(0x0268,0x0000000F); // TCLK_POSTCNT
	i2c1_uh2d_write32(0x026C,0x000D0008); // THS_TRAILCNT
	i2c1_uh2d_write32(0x0270,0x00000020); // HSTXVREGCNT
	i2c1_uh2d_write32(0x0274,0x0000001F); // HSTXVREGEN
	i2c1_uh2d_write32(0x0278,0x00060005); // BTA_COUNT
	i2c1_uh2d_write32(0x027C,0x00000002); // DPHY_TX ADJUST
	i2c1_uh2d_write32(0x011C,0x00000001); // DSITX_START
	// DSI-TX1 Transition Timing
	i2c1_uh2d_write32(0x0308,0x00000001); // DSI_TX_CLKEN
	i2c1_uh2d_write32(0x030C,0x00000001); // DSI_TX_CLKSEL
	i2c1_uh2d_write32(0x04A0,0x00000001); // MIPI_PLL_CONTROL
	i2c1_uh2d_write32(0x04AC,0x000090BD); // MIPI_PLL_CNF
	Waitx1ms(1);
	i2c1_uh2d_write32(0x04A0,0x00000003); // MIPI_PLL_CONTROL
	i2c1_uh2d_write32(0x0318,0x00000014); // LANE_ENABLE
	i2c1_uh2d_write32(0x0320,0x00001770); // LINE_INIT_COUNT
	i2c1_uh2d_write32(0x0324,0x00000000); // HSTX_TO_COUNT
	i2c1_uh2d_write32(0x0328,0x00000101); // FUNC_ENABLE
	i2c1_uh2d_write32(0x0330,0x00010000); // DSI_TATO_COUNT
	i2c1_uh2d_write32(0x0334,0x00005000); // DSI_PRESP_BTA_COUNT
	i2c1_uh2d_write32(0x0338,0x00010000); // DSI_PRESP_LPR_COUNT
	i2c1_uh2d_write32(0x033C,0x00010000); // DSI_PRESP_LPW_COUNT
	i2c1_uh2d_write32(0x0340,0x00010000); // DSI_PRESP_HSR_COUNT
	i2c1_uh2d_write32(0x0344,0x00010000); // DSI_PRESP_HSW_COUNT
	i2c1_uh2d_write32(0x0348,0x00001000); // DSI_PR_TO_COUNT
	i2c1_uh2d_write32(0x034C,0x00010000); // DSI_LRX-H_TO_COUNT
	i2c1_uh2d_write32(0x0350,0x00000160); // FUNC_MODE
	i2c1_uh2d_write32(0x0354,0x00000001); // DSI_RX_VC_ENABLE
	i2c1_uh2d_write32(0x0358,0x000000C8); // IND_TO_COUNT
	i2c1_uh2d_write32(0x0368,0x0000002A); // DSI_HSYNC_STOP_COUNT
	i2c1_uh2d_write32(0x0370,0x00000478); // APF_VDELAYCNT
	i2c1_uh2d_write32(0x037C,0x00000081); // DSI_TX_MODE
	i2c1_uh2d_write32(0x038C,0x00000001); // DSI_HSYNC_WIDTH
	i2c1_uh2d_write32(0x0390,0x00000104); // DSI_HBPR
	i2c1_uh2d_write32(0x03A4,0x00000000); // DSI_RX_STATE_INT_MASK
	i2c1_uh2d_write32(0x03C0,0x00000015); // DSI_LPRX_THRESH_COUNT
	i2c1_uh2d_write32(0x0414,0x00000000); // APP_SIDE_ERR_INT_MASK
	i2c1_uh2d_write32(0x041C,0x00000080); // DSI_RX_ERR_INT_MASK
	i2c1_uh2d_write32(0x0424,0x00000000); // DSI_LPTX_INT_MASK
	i2c1_uh2d_write32(0x0454,0x00000006); // LPTXTIMECNT
	i2c1_uh2d_write32(0x0458,0x00240204); // TCLK_HEADERCNT
	i2c1_uh2d_write32(0x045C,0x000D0008); // TCLK_TRAILCNT
	i2c1_uh2d_write32(0x0460,0x00140006); // THS_HEADERCNT
	i2c1_uh2d_write32(0x0464,0x00004268); // TWAKEUPCNT
	i2c1_uh2d_write32(0x0468,0x0000000F); // TCLK_POSTCNT
	i2c1_uh2d_write32(0x046C,0x000D0008); // THS_TRAILCNT
	i2c1_uh2d_write32(0x0470,0x00000020); // HSTXVREGCNT
	i2c1_uh2d_write32(0x0474,0x0000001F); // HSTXVREGEN
	i2c1_uh2d_write32(0x0478,0x00060005); // BTA_COUNT
	i2c1_uh2d_write32(0x047C,0x00000002); // DPHY_TX ADJUST
	i2c1_uh2d_write32(0x031C,0x00000001); // DSITX_START
	// Command Transmission Before Video Start
	i2c1_uh2d_write16(0x0500,0x0004); // CMD_SEL
	i2c1_uh2d_write32(0x0110,0x00000016); // MODE_CONFIG
	i2c1_uh2d_write32(0x0310,0x00000016); // MODE_CONFIG
	// LCD Initialization
	// Soft Reset
	i2c1_uh2d_write16(0x0504,0x0005); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0001); // DCSCMD_Q
	Waitx1ms(5);
	// Set Pixel Format
	i2c1_uh2d_write16(0x0504,0x0015); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x773A); // DCSCMD_Q
	Waitx1us(200);
	// Set Column Address
	i2c1_uh2d_write16(0x0504,0x8039); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0005); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x002A); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0400); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x00FF); // DCSCMD_Q
	Waitx1us(200);
	// Set Page Address
	i2c1_uh2d_write16(0x0504,0x8039); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0005); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x002B); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0600); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x003F); // DCSCMD_Q
	Waitx1us(200);
	// Set Tear On
	i2c1_uh2d_write16(0x0504,0x0015); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0035); // DCSCMD_Q
	Waitx1us(200);
	// Set Tear Scanline
	i2c1_uh2d_write16(0x0504,0x8039); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0003); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0044); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0000); // DCSCMD_Q
	Waitx1us(200);
	// Write Display Brightness
	i2c1_uh2d_write16(0x0504,0x0015); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0xFF51); // DCSCMD_Q
	Waitx1us(200);
	// Write Control Display
	i2c1_uh2d_write16(0x0504,0x0015); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x2453); // DCSCMD_Q
	Waitx1us(200);
	// Adaptive Brightness Control
	i2c1_uh2d_write16(0x0504,0x0015); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0155); // DCSCMD_Q
	Waitx1us(200);
	// Exit Sleep
	i2c1_uh2d_write16(0x0504,0x0005); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0011); // DCSCMD_Q
	Waitx1ms(120);
	// MCAP
	i2c1_uh2d_write16(0x0504,0x0023); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x00B0); // DCSCMD_Q
	Waitx1us(200);
	// Backlight Control 4
	i2c1_uh2d_write16(0x0504,0x8029); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0014); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x7DCE); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x4840); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x6756); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x8878); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0xA798); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0xC3B5); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0xDED1); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0xF2E9); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0xFFFA); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0004); // DCSCMD_Q
	// Split Control
	i2c1_uh2d_write16(0x5000,0x0000); // STX0_CTL
	i2c1_uh2d_write16(0x500C,0x84E0); // STX0_FPX
	i2c1_uh2d_write16(0x5080,0x0000); // STX1_CTL
	// HDMI PHY
	i2c1_uh2d_write8(0x8410,0x03); // PHY CTL
	i2c1_uh2d_write8(0x8413,0x3F); // PHY_ENB
	i2c1_uh2d_write8(0x8420,0x07); // EQ_BYPS
	i2c1_uh2d_write8(0x84F0,0x31); // APLL_CTL
	i2c1_uh2d_write8(0x84F4,0x01); // DDCIO_CTL
	// HDMI Clock
	i2c1_uh2d_write16(0x8540,0x12C0); // SYS_FREQ0_1
	i2c1_uh2d_write8(0x8630,0x00); // LOCKDET_FREQ0
	i2c1_uh2d_write16(0x8631,0x0753); // LOCKDET_REF1_2
	i2c1_uh2d_write8(0x8670,0x02); // NCO_F0_MOD
	i2c1_uh2d_write16(0x8A0C,0x12C0); // CSC_SCLK0_1
	// HDMI Interrupt Mask, Clear
	i2c1_uh2d_write8(0x850B,0xFF); // MISC_INT
	i2c1_uh2d_write8(0x851B,0xFD); // MISC_INTM
	// Interrupt Control (TOP level)
	i2c1_uh2d_write16(0x0014,0x0FBF); // IntStatus
	i2c1_uh2d_write16(0x0016,0x0DBF); // IntMask
	// EDID
	i2c1_uh2d_write8(0x85E0,0x01); // EDID_MODE
	i2c1_uh2d_write16(0x85E3,0x0100); // EDID_LEN1_2
	// EDID Data
	i2c1_uh2d_write8(0x8C00,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C01,0xFF); // EDID_RAM
	i2c1_uh2d_write8(0x8C02,0xFF); // EDID_RAM
	i2c1_uh2d_write8(0x8C03,0xFF); // EDID_RAM
	i2c1_uh2d_write8(0x8C04,0xFF); // EDID_RAM
	i2c1_uh2d_write8(0x8C05,0xFF); // EDID_RAM
	i2c1_uh2d_write8(0x8C06,0xFF); // EDID_RAM
	i2c1_uh2d_write8(0x8C07,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C08,0x52); // EDID_RAM
	i2c1_uh2d_write8(0x8C09,0x62); // EDID_RAM
	i2c1_uh2d_write8(0x8C0A,0x88); // EDID_RAM
	i2c1_uh2d_write8(0x8C0B,0x88); // EDID_RAM
	i2c1_uh2d_write8(0x8C0C,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C0D,0x88); // EDID_RAM
	i2c1_uh2d_write8(0x8C0E,0x88); // EDID_RAM
	i2c1_uh2d_write8(0x8C0F,0x88); // EDID_RAM
	i2c1_uh2d_write8(0x8C10,0x1C); // EDID_RAM
	i2c1_uh2d_write8(0x8C11,0x15); // EDID_RAM
	i2c1_uh2d_write8(0x8C12,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C13,0x03); // EDID_RAM
	i2c1_uh2d_write8(0x8C14,0x80); // EDID_RAM
	i2c1_uh2d_write8(0x8C15,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C16,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C17,0x78); // EDID_RAM
	i2c1_uh2d_write8(0x8C18,0x0A); // EDID_RAM
	i2c1_uh2d_write8(0x8C19,0x0D); // EDID_RAM
	i2c1_uh2d_write8(0x8C1A,0xC9); // EDID_RAM
	i2c1_uh2d_write8(0x8C1B,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8C1C,0x57); // EDID_RAM
	i2c1_uh2d_write8(0x8C1D,0x47); // EDID_RAM
	i2c1_uh2d_write8(0x8C1E,0x98); // EDID_RAM
	i2c1_uh2d_write8(0x8C1F,0x27); // EDID_RAM
	i2c1_uh2d_write8(0x8C20,0x12); // EDID_RAM
	i2c1_uh2d_write8(0x8C21,0x48); // EDID_RAM
	i2c1_uh2d_write8(0x8C22,0x4C); // EDID_RAM
	i2c1_uh2d_write8(0x8C23,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C24,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C25,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C26,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C27,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C28,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C29,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C2A,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C2B,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C2C,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C2D,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C2E,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C2F,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C30,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C31,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C32,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C33,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C34,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C35,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C36,0xEC); // EDID_RAM
	i2c1_uh2d_write8(0x8C37,0x68); // EDID_RAM
	i2c1_uh2d_write8(0x8C38,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C39,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8C3A,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8C3B,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8C3C,0x2E); // EDID_RAM
	i2c1_uh2d_write8(0x8C3D,0x60); // EDID_RAM
	i2c1_uh2d_write8(0x8C3E,0x30); // EDID_RAM
	i2c1_uh2d_write8(0x8C3F,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8C40,0x36); // EDID_RAM
	i2c1_uh2d_write8(0x8C41,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C42,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C43,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8C44,0xA6); // EDID_RAM
	i2c1_uh2d_write8(0x8C45,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C46,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C47,0x1A); // EDID_RAM
	i2c1_uh2d_write8(0x8C48,0xEC); // EDID_RAM
	i2c1_uh2d_write8(0x8C49,0x68); // EDID_RAM
	i2c1_uh2d_write8(0x8C4A,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C4B,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8C4C,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8C4D,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8C4E,0x2E); // EDID_RAM
	i2c1_uh2d_write8(0x8C4F,0x60); // EDID_RAM
	i2c1_uh2d_write8(0x8C50,0x30); // EDID_RAM
	i2c1_uh2d_write8(0x8C51,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8C52,0x36); // EDID_RAM
	i2c1_uh2d_write8(0x8C53,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C54,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C55,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8C56,0xA6); // EDID_RAM
	i2c1_uh2d_write8(0x8C57,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C58,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C59,0x1A); // EDID_RAM
	i2c1_uh2d_write8(0x8C5A,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C5B,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C5C,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C5D,0xFC); // EDID_RAM
	i2c1_uh2d_write8(0x8C5E,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C5F,0x73); // EDID_RAM
	i2c1_uh2d_write8(0x8C60,0x73); // EDID_RAM
	i2c1_uh2d_write8(0x8C61,0x69); // EDID_RAM
	i2c1_uh2d_write8(0x8C62,0x63); // EDID_RAM
	i2c1_uh2d_write8(0x8C63,0x73); // EDID_RAM
	i2c1_uh2d_write8(0x8C64,0x73); // EDID_RAM
	i2c1_uh2d_write8(0x8C65,0x61); // EDID_RAM
	i2c1_uh2d_write8(0x8C66,0x2D); // EDID_RAM
	i2c1_uh2d_write8(0x8C67,0x55); // EDID_RAM
	i2c1_uh2d_write8(0x8C68,0x48); // EDID_RAM
	i2c1_uh2d_write8(0x8C69,0x32); // EDID_RAM
	i2c1_uh2d_write8(0x8C6A,0x44); // EDID_RAM
	i2c1_uh2d_write8(0x8C6B,0x0A); // EDID_RAM
	i2c1_uh2d_write8(0x8C6C,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C6D,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C6E,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C6F,0xFD); // EDID_RAM
	i2c1_uh2d_write8(0x8C70,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C71,0x14); // EDID_RAM
	i2c1_uh2d_write8(0x8C72,0x78); // EDID_RAM
	i2c1_uh2d_write8(0x8C73,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C74,0xFF); // EDID_RAM
	i2c1_uh2d_write8(0x8C75,0x1D); // EDID_RAM
	i2c1_uh2d_write8(0x8C76,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C77,0x0A); // EDID_RAM
	i2c1_uh2d_write8(0x8C78,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8C79,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8C7A,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8C7B,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8C7C,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8C7D,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8C7E,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C7F,0x6A); // EDID_RAM
	i2c1_uh2d_write8(0x8C80,0x02); // EDID_RAM
	i2c1_uh2d_write8(0x8C81,0x03); // EDID_RAM
	i2c1_uh2d_write8(0x8C82,0x1A); // EDID_RAM
	i2c1_uh2d_write8(0x8C83,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8C84,0x47); // EDID_RAM
	i2c1_uh2d_write8(0x8C85,0x4C); // EDID_RAM
	i2c1_uh2d_write8(0x8C86,0x4C); // EDID_RAM
	i2c1_uh2d_write8(0x8C87,0x4C); // EDID_RAM
	i2c1_uh2d_write8(0x8C88,0x4C); // EDID_RAM
	i2c1_uh2d_write8(0x8C89,0x4C); // EDID_RAM
	i2c1_uh2d_write8(0x8C8A,0x4C); // EDID_RAM
	i2c1_uh2d_write8(0x8C8B,0x4C); // EDID_RAM
	i2c1_uh2d_write8(0x8C8C,0x23); // EDID_RAM
	i2c1_uh2d_write8(0x8C8D,0x09); // EDID_RAM
	i2c1_uh2d_write8(0x8C8E,0x07); // EDID_RAM
	i2c1_uh2d_write8(0x8C8F,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C90,0x83); // EDID_RAM
	i2c1_uh2d_write8(0x8C91,0x01); // EDID_RAM
	i2c1_uh2d_write8(0x8C92,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C93,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C94,0x65); // EDID_RAM
	i2c1_uh2d_write8(0x8C95,0x03); // EDID_RAM
	i2c1_uh2d_write8(0x8C96,0x0C); // EDID_RAM
	i2c1_uh2d_write8(0x8C97,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C98,0x10); // EDID_RAM
	i2c1_uh2d_write8(0x8C99,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C9A,0xEC); // EDID_RAM
	i2c1_uh2d_write8(0x8C9B,0x68); // EDID_RAM
	i2c1_uh2d_write8(0x8C9C,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8C9D,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8C9E,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8C9F,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8CA0,0x2E); // EDID_RAM
	i2c1_uh2d_write8(0x8CA1,0x60); // EDID_RAM
	i2c1_uh2d_write8(0x8CA2,0x30); // EDID_RAM
	i2c1_uh2d_write8(0x8CA3,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8CA4,0x36); // EDID_RAM
	i2c1_uh2d_write8(0x8CA5,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CA6,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CA7,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8CA8,0xA6); // EDID_RAM
	i2c1_uh2d_write8(0x8CA9,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CAA,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CAB,0x1A); // EDID_RAM
	i2c1_uh2d_write8(0x8CAC,0xEC); // EDID_RAM
	i2c1_uh2d_write8(0x8CAD,0x68); // EDID_RAM
	i2c1_uh2d_write8(0x8CAE,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CAF,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8CB0,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8CB1,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8CB2,0x2E); // EDID_RAM
	i2c1_uh2d_write8(0x8CB3,0x60); // EDID_RAM
	i2c1_uh2d_write8(0x8CB4,0x30); // EDID_RAM
	i2c1_uh2d_write8(0x8CB5,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8CB6,0x36); // EDID_RAM
	i2c1_uh2d_write8(0x8CB7,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CB8,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CB9,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8CBA,0xA6); // EDID_RAM
	i2c1_uh2d_write8(0x8CBB,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CBC,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CBD,0x1A); // EDID_RAM
	i2c1_uh2d_write8(0x8CBE,0xEC); // EDID_RAM
	i2c1_uh2d_write8(0x8CBF,0x68); // EDID_RAM
	i2c1_uh2d_write8(0x8CC0,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CC1,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8CC2,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8CC3,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8CC4,0x2E); // EDID_RAM
	i2c1_uh2d_write8(0x8CC5,0x60); // EDID_RAM
	i2c1_uh2d_write8(0x8CC6,0x30); // EDID_RAM
	i2c1_uh2d_write8(0x8CC7,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8CC8,0x36); // EDID_RAM
	i2c1_uh2d_write8(0x8CC9,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CCA,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CCB,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8CCC,0xA6); // EDID_RAM
	i2c1_uh2d_write8(0x8CCD,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CCE,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CCF,0x1A); // EDID_RAM
	i2c1_uh2d_write8(0x8CD0,0xEC); // EDID_RAM
	i2c1_uh2d_write8(0x8CD1,0x68); // EDID_RAM
	i2c1_uh2d_write8(0x8CD2,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CD3,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8CD4,0xA0); // EDID_RAM
	i2c1_uh2d_write8(0x8CD5,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8CD6,0x2E); // EDID_RAM
	i2c1_uh2d_write8(0x8CD7,0x60); // EDID_RAM
	i2c1_uh2d_write8(0x8CD8,0x30); // EDID_RAM
	i2c1_uh2d_write8(0x8CD9,0x20); // EDID_RAM
	i2c1_uh2d_write8(0x8CDA,0x36); // EDID_RAM
	i2c1_uh2d_write8(0x8CDB,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CDC,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CDD,0x40); // EDID_RAM
	i2c1_uh2d_write8(0x8CDE,0xA6); // EDID_RAM
	i2c1_uh2d_write8(0x8CDF,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CE0,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CE1,0x1A); // EDID_RAM
	i2c1_uh2d_write8(0x8CE2,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CE3,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CE4,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CE5,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CE6,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CE7,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CE8,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CE9,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CEA,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CEB,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CEC,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CED,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CEE,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CEF,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CF0,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CF1,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CF2,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CF3,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CF4,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CF5,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CF6,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CF7,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CF8,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CF9,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CFA,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CFB,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CFC,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CFD,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CFE,0x00); // EDID_RAM
	i2c1_uh2d_write8(0x8CFF,0x6A); // EDID_RAM
	// HDCP Setting
	// Video Color Format Setting
	i2c1_uh2d_write8(0x8A02,0x42); // VOUT_SYNC0
	// HDMI SYSTEM
	i2c1_uh2d_write8(0x8543,0x02); // DDC_CTL
	i2c1_uh2d_write8(0x8544,0x10); // HPD_CTL
	// HDMI Audio Setting
	i2c1_uh2d_write8(0x8600,0x00); // AUD_Auto_Mute
	i2c1_uh2d_write8(0x8602,0xF3); // Auto_CMD0
	i2c1_uh2d_write8(0x8603,0x02); // Auto_CMD1
	i2c1_uh2d_write8(0x8604,0x0C); // Auto_CMD2
	i2c1_uh2d_write8(0x8606,0x05); // BUFINIT_START
	i2c1_uh2d_write8(0x8607,0x00); // FS_MUTE
	i2c1_uh2d_write8(0x8652,0x02); // SDO_MODE1
	i2c1_uh2d_write32(0x8671,0x020C49BA); // NCO_48F0A_D
	i2c1_uh2d_write32(0x8675,0x01E1B089); // NCO_44F0A_D
	i2c1_uh2d_write8(0x8680,0x00); // AUD_MODE
	// Let HDMI Source start access
	i2c1_uh2d_write8(0x854A,0x01); // INIT_END
	// HDMI Signal Detection
	// Wait until HDMI sync is established
	// By Interrupt   In Interrupt Service Routine.
	i2c1_uh2d_read8(0x8520); // SYS_STATUS
	// Sequence: Check bit7 of 8x8520
	i2c1_uh2d_write8(0x850B,0xFF); // MISC_INT
	i2c1_uh2d_write16(0x0014,0x0FBF); // IntStatus
	// By Polling
	i2c1_uh2d_read8(0x8520); // SYS_STATUS
	// Sequence: Check bit7 of 8x8520
	// Start Video TX
	i2c1_uh2d_write16(0x0004,0x0C37); // ConfCtl0
	i2c1_uh2d_write16(0x0006,0x0000); // ConfCtl1
	// Command Transmission After Video Start.
	i2c1_uh2d_write32(0x0110,0x00000006); // MODE_CONFIG
	i2c1_uh2d_write32(0x0310,0x00000006); // MODE_CONFIG
	Waitx1ms(1000);
	// MCAP
	i2c1_uh2d_write16(0x0504,0x0023); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x00B0); // DCSCMD_Q
	Waitx1us(200);
	// Interface Setting
	i2c1_uh2d_write16(0x0504,0x0023); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x14B3); // DCSCMD_Q
	Waitx1us(200);
	// MCAP
	i2c1_uh2d_write16(0x0504,0x0023); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x03B0); // DCSCMD_Q
	Waitx1us(200);
	// Set Display On
	i2c1_uh2d_write16(0x0504,0x0005); // DCSCMD_Q
	i2c1_uh2d_write16(0x0504,0x0029); // DCSCMD_Q
	Waitx1us(200);
	


}


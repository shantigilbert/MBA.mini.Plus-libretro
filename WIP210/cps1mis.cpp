// license:BSD-3-Clause
// copyright-holders:Robbbert
/*******************************************************************************************************************

        CPS-1 driver for hacks and bootlegs

Issues:

- knightsh
	the title screen is garbage.

- kodh
	title, problem with placement of the letters.

- sk2h1, sk2h2, sk2h3, sk2h22, sk2h31, sk2h32, sk2h33, sk2h34
	setup screen is blank.
	map doesn't show first time around prior to demo 1, and never before demo 3.

- sk2h22, sk2h31, sk2h32, sk2h33, sk2h34, sk2h35
	coin 3, start 3, 3rd player not working.

- wofjcn
	chinese language rom isn't working. Whatever is tried breaks stuff.


*******************************************************************************************************************/

WRITE16_MEMBER( cps_state::dinoh_sound_command_w )
{
	/* Pass the Sound Code to the Q-Sound Shared Ram */
	m_qsound_sharedram1[1] = data;
}

WRITE16_MEMBER( cps_state::daimakb_palctrl_w )
{
	m_cps_b_regs[0x30 / 2] = data;
}

WRITE16_MEMBER(cps_state::daimakb_layer_w)
{
	if (offset == 0x00)
		m_cps_a_regs[0x0e / 2] = data; /* scroll 1y */
	else
	if (offset == 0x01)
		m_cps_a_regs[0x0c / 2] = data - 0x40; /* scroll 1x */
	else
	if (offset == 0x02)
	{
		m_cps_a_regs[0x12 / 2] = data; /* scroll 2y */
		m_cps_a_regs[0x20 / 2] = data; /* row scroll start */
	}
	else
	if (offset == 0x03)
		m_cps_a_regs[0x10 / 2] = data - 0x40; /* scroll 2x */
	else
	if (offset == 0x04)
		m_cps_a_regs[0x16 / 2] = data; /* scroll 3y */
	else
	if (offset == 0x05)
		m_cps_a_regs[0x14 / 2] = data - 0x40; /* scroll 3x */
	else
	if (offset == 0x06)
	{
		switch (data)
		{
		case 0x0000:
			data = (1 << 12) | (2 << 8) | (3 << 6);
			break;
		case 0x0001:
			data = (1 << 12) | (3 << 6);
			break;
		case 0x0002:
			data = (3 << 12) | (1 << 6);
			break;
		case 0x0006:
			data = 0;
			break;
		default:
			data = 0;
			printf ("Unknown control word = %X\n",data);
		}
		m_cps_b_regs[0x26 / 2] = data;
	}
}



/**************************************************************************

	Address Maps

***************************************************************************/

void cps_state::daimakb_map(address_map &map) {
	map(0x000000,0x3fffff).rom();
	map(0x800000,0x800001).portr("IN1");  /* Player input ports */
	map(0x800006,0x800007).w(FUNC(cps_state::cps1_soundlatch_w));  /* Sound command */
	map(0x800018,0x80001f).r(FUNC(cps_state::cps1_hack_dsw_r));  /* System input ports / Dip Switches */
	map(0x800030,0x800037).w(FUNC(cps_state::cps1_coinctrl_w));
	map(0x800100,0x80013f).w(FUNC(cps_state::cps1_cps_a_w)).share("cps_a_regs");  /* CPS-A custom */
	map(0x800166,0x800171).nopw();  // not used
	map(0xe00000,0xe0003f).rw(FUNC(cps_state::cps1_cps_b_r),FUNC(cps_state::cps1_cps_b_w)).share("cps_b_regs");  // dummy region
	map(0x880000,0x880001).w(FUNC(cps_state::daimakb_palctrl_w));
	map(0x900000,0x92ffff).ram().w(FUNC(cps_state::cps1_gfxram_w)).share("gfxram");
	map(0x980000,0x98000d).w(FUNC(cps_state::daimakb_layer_w));
	map(0x990000,0x993fff).nopw();  // bootleg sprites, not needed
	map(0xff0000,0xffffff).ram().share(m_mainram);
}

void cps_state::sk2h35_map(address_map &map) {
/* unknown addresses (all write): 930008-930807. No 3rd player controls. NVRAM doesn't work */
	map(0x000000,0x3fffff).rom();
	map(0x800000,0x800001).portr("IN1");  /* Player input ports */
	map(0x800018,0x80001f).r(FUNC(cps_state::cps1_dsw_r));  /* System input ports / Dip Switches */
	map(0x80001c,0x80001d).portr("EEPROMIN").portw("EEPROMOUT");
	map(0x800030,0x800037).w(FUNC(cps_state::cps1_coinctrl_w));
	map(0x800100,0x80013f).w(FUNC(cps_state::cps1_cps_a_w)).share("cps_a_regs");  /* CPS-A custom */
	map(0x800140,0x80017f).rw(FUNC(cps_state::cps1_cps_b_r),FUNC(cps_state::cps1_cps_b_w)).share("cps_b_regs");  /* CPS-B custom */
	map(0x800180,0x800187).w(FUNC(cps_state::cps1_soundlatch_w));  /* Sound command */
	map(0x800188,0x80018f).w(FUNC(cps_state::cps1_soundlatch2_w));  /* Sound timer fade */
	map(0x900000,0x92ffff).ram().w(FUNC(cps_state::cps1_gfxram_w)).share("gfxram");
	map(0x930008,0x930807).nopw();
	map(0xf18000,0xf19fff).rw(FUNC(cps_state::qsound_sharedram1_r),FUNC(cps_state::qsound_sharedram1_w));  /* Q RAM */
	map(0xf1ce74,0xf1ce75).nopw();
	map(0xf1e000,0xf1ffff).rw(FUNC(cps_state::qsound_sharedram2_r),FUNC(cps_state::qsound_sharedram2_w));  /* Q RAM */
	map(0xff0000,0xffffff).ram().share(m_mainram);
}

void cps_state::cps1frog_map(address_map &map) {
	map(0x000000,0x3fffff).rom();
	map(0x800000,0x800001).portr("IN1");  /* Player input ports */
	map(0x800030,0x800031).w(FUNC(cps_state::cps1_coinctrl_w));
	map(0x800100,0x80013f).w(FUNC(cps_state::cps1_cps_a_w)).share("cps_a_regs");  /* Output ports */
	map(0x800140,0x80017f).rw(FUNC(cps_state::cps1_cps_b_r),FUNC(cps_state::cps1_cps_b_w)).share("cps_b_regs");
	map(0x800180,0x800187).w(FUNC(cps_state::cps1_soundlatch_w));  /* Sound command */
	map(0x800188,0x80018f).w(FUNC(cps_state::cps1_soundlatch2_w));  /* Sound timer fade */
	map(0x900000,0x92ffff).ram().w(FUNC(cps_state::cps1_gfxram_w)).share("gfxram");
	map(0xff0000,0xffffff).ram().share(m_mainram);
}

void cps_state::sk2h1q_map(address_map &map) {
	map(0x000000,0x3fffff).rom();
	map(0x800030,0x800031).w(FUNC(cps_state::cps1_coinctrl_w));
	map(0x800100,0x80013f).ram().share("cps_a_regs");  /* CPS-A custom */
	map(0x800140,0x80017f).rw(FUNC(cps_state::cps1_cps_b_r),FUNC(cps_state::cps1_cps_b_w)).share("cps_b_regs");
	map(0x880000,0x880001).portr("IN1");  /* Player input ports */
	map(0x880006,0x88000d).r(FUNC(cps_state::cps1_dsw_r));  /* System input ports / Dip Switches */
	map(0x88000e,0x88000f).nopw();
	map(0x880e78,0x880e79).r(FUNC(cps_state::cps1_in2_r));  /* Player 3 controls (later games) */
	map(0x890000,0x890001).nopw();
	map(0x8bfff6,0x8bfff9).nopr();  /* unknown */
	map(0x900000,0x92ffff).ram().w(FUNC(cps_state::cps1_gfxram_w)).share("gfxram");
	map(0xf18000,0xf19fff).rw(FUNC(cps_state::qsound_sharedram1_r),FUNC(cps_state::qsound_sharedram1_w));  /* Q RAM */
	map(0xf1c004,0xf1c005).w(FUNC(cps_state::cpsq_coinctrl2_w));  /* Coin control2 (later games) */
	map(0xf1c006,0xf1c007).portr("EEPROMIN").portw("EEPROMOUT");
	map(0xf1e000,0xf1ffff).rw(FUNC(cps_state::qsound_sharedram2_r),FUNC(cps_state::qsound_sharedram2_w));  /* Q RAM */
	map(0xff0000,0xffffff).ram().share(m_mainram);
}

void cps_state::sk2h3_map(address_map &map) {
	map(0x000000,0x3fffff).rom();
	map(0x800030,0x800031).w(FUNC(cps_state::cps1_coinctrl_w));
	map(0x800100,0x80013f).ram().share("cps_a_regs");  /* CPS-A custom */
	map(0x800140,0x80017f).rw(FUNC(cps_state::cps1_cps_b_r),FUNC(cps_state::cps1_cps_b_w)).share("cps_b_regs");
	map(0x880000,0x880001).portr("IN1");  /* Player input ports */
	map(0x880006,0x88000d).r(FUNC(cps_state::cps1_dsw_r));  /* System input ports / Dip Switches */
	map(0x88000e,0x88000f).w(FUNC(cps_state::cps1_soundlatch_w));
	map(0x880e78,0x880e79).r(FUNC(cps_state::cps1_in2_r));  /* Player 3 controls (later games) */
	map(0x890000,0x890001).nopw();
	map(0x8bfff6,0x8bfff9).nopr();  /* unknown */
	map(0x900000,0x92ffff).ram().w(FUNC(cps_state::cps1_gfxram_w)).share("gfxram");
	map(0xf1c004,0xf1c005).w(FUNC(cps_state::cpsq_coinctrl2_w));  /* Coin control2 (later games) */
	map(0xf1c006,0xf1c007).portr("EEPROMIN").portw("EEPROMOUT");
	map(0xff0000,0xffffff).ram().share(m_mainram);
}

void cps_state::sk2h31q_map(address_map &map) {
	map(0x000000,0x3fffff).rom();
	map(0x800030,0x800031).w(FUNC(cps_state::cps1_coinctrl_w));
	map(0x800100,0x80013f).w(FUNC(cps_state::cps1_cps_a_w)).share("cps_a_regs");  /* Output ports */
	map(0x800140,0x80017f).rw(FUNC(cps_state::cps1_cps_b_r),FUNC(cps_state::cps1_cps_b_w)).share("cps_b_regs");
	map(0x880000,0x880001).portr("IN1");  /* Player input ports */
	map(0x880006,0x880007).nopw();  // soundlatch on non-qsound hw
	map(0x880008,0x88000f).r(FUNC(cps_state::cps1_dsw_r));  /* System input ports / Dip Switches */
	map(0x880e7e,0x880e7f).r(FUNC(cps_state::cps1_in2_r));  /* Player 3 controls (later games) */
	map(0x890000,0x890001).nopw();
	map(0x8bfff6,0x8bfff9).nopr();  /* unknown */
	map(0x900000,0x92ffff).ram().w(FUNC(cps_state::cps1_gfxram_w)).share("gfxram");
	map(0xf18000,0xf19fff).rw(FUNC(cps_state::qsound_sharedram1_r),FUNC(cps_state::qsound_sharedram1_w));  /* Q RAM */
	map(0xf1c004,0xf1c005).w(FUNC(cps_state::cpsq_coinctrl2_w));  /* Coin control2 (later games) */
	map(0xf1c006,0xf1c007).portr("EEPROMIN").portw("EEPROMOUT");
	map(0xf1e000,0xf1ffff).rw(FUNC(cps_state::qsound_sharedram2_r),FUNC(cps_state::qsound_sharedram2_w));  /* Q RAM */
	map(0xff0000,0xffffff).ram().share(m_mainram);
}

void cps_state::sk2h31_map(address_map &map) {
	map(0x000000,0x3fffff).rom();
	map(0x800030,0x800031).w(FUNC(cps_state::cps1_coinctrl_w));
	map(0x800100,0x80013f).w(FUNC(cps_state::cps1_cps_a_w)).share("cps_a_regs");  /* Output ports */
	map(0x800140,0x80017f).rw(FUNC(cps_state::cps1_cps_b_r),FUNC(cps_state::cps1_cps_b_w)).share("cps_b_regs");
	map(0x880000,0x880001).portr("IN1");  /* Player input ports */
	map(0x880006,0x880007).w(FUNC(cps_state::cps1_soundlatch_w));
	map(0x880008,0x88000f).r(FUNC(cps_state::cps1_dsw_r));  /* System input ports / Dip Switches */
	map(0x880e7e,0x880e7f).r(FUNC(cps_state::cps1_in2_r));  /* Player 3 controls (later games) */
	map(0x890000,0x890001).nopw();
	map(0x8bfff6,0x8bfff9).nopr();  /* unknown */
	map(0x900000,0x92ffff).ram().w(FUNC(cps_state::cps1_gfxram_w)).share("gfxram");
	map(0xf1c004,0xf1c005).w(FUNC(cps_state::cpsq_coinctrl2_w));  /* Coin control2 (later games) */
	map(0xf1c006,0xf1c007).portr("EEPROMIN").portw("EEPROMOUT");
	map(0xff0000,0xffffff).ram().share(m_mainram);
}

void cps_state::wofsf2_map(address_map &map) {
	map(0x000000,0x3fffff).rom();
	map(0x800000,0x800007).portr("IN1");
	map(0x800018,0x80001f).r(FUNC(cps_state::cps1_hack_dsw_r));
	map(0x800030,0x800037).w(FUNC(cps_state::cps1_coinctrl_w));
	map(0x800100,0x80013f).w(FUNC(cps_state::cps1_cps_a_w)).share("cps_a_regs");  /* CPS-A custom */
	map(0x800140,0x80017f).rw(FUNC(cps_state::cps1_cps_b_r),FUNC(cps_state::cps1_cps_b_w)).share("cps_b_regs");
	map(0x800180,0x800187).w(FUNC(cps_state::cps1_soundlatch_w));  /* Sound command */
	map(0x900000,0x92ffff).ram().w(FUNC(cps_state::cps1_gfxram_w)).share("gfxram");
	map(0xf18000,0xf19fff).ram();
	map(0xf1c000,0xf1c001).r(FUNC(cps_state::cps1_in2_r));  /* Player 3 controls */
	map(0xf1c004,0xf1c005).w(FUNC(cps_state::cpsq_coinctrl2_w));  /* Coin control2 (later games) */
	map(0xf1c006,0xf1c007).portr("EEPROMIN").portw("EEPROMOUT");
	map(0xff0000,0xffffff).ram().share("mainram");
}

/********************************************************************

	Inputs and dips

*********************************************************************/

static INPUT_PORTS_START( dinohz )
	PORT_INCLUDE( dino )

	PORT_MODIFY("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_MODIFY("IN2")      /* Player 3 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
//	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START3 )
INPUT_PORTS_END

static INPUT_PORTS_START( knightsh )
	PORT_INCLUDE( knights )

	PORT_MODIFY("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_MODIFY("IN2")      /* Player 3 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
//	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START3 )
INPUT_PORTS_END

static INPUT_PORTS_START( kodh )
	PORT_INCLUDE( kod )

	PORT_MODIFY("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

static INPUT_PORTS_START( pnicku )
	PORT_INCLUDE( pnickj )
	PORT_MODIFY("DSWA")
	PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coinage ) )  PORT_DIPLOCATION("SW(A):1,2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( 5C_1C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) )

	PORT_DIPNAME( 0x10, 0x10, "Chuters" )           PORT_DIPLOCATION("SW(A):5")
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x10, "1" )

	PORT_MODIFY("DSWC")
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) ) PORT_DIPLOCATION("SW(C):3")
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END

static INPUT_PORTS_START( sk2h3 )
	PORT_START ("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
	PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWA")
	PORT_DIPNAME( 0x03, 0x00, "Play Mode" )
	PORT_DIPSETTING(    0x00, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x03, "Tournament" )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWB")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_4C ) )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWC")
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNKNOWN )

	PORT_START ("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("IN2")      /* Player 3 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START3 )

	PORT_START( "EEPROMIN" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, do_read)

	PORT_START( "EEPROMOUT" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, di_write)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, clk_write)
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, cs_write)
INPUT_PORTS_END

static INPUT_PORTS_START( sk2h21 )
	PORT_INCLUDE( wof )

	PORT_MODIFY("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_MODIFY("IN2")      /* Player 3 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
//	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START3 )
INPUT_PORTS_END


/***********************************************************
             INPUT PORTS, DIPs
***********************************************************/

static INPUT_PORTS_START( cps1frog )
	PORT_START ("IN0")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWA")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWB")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWC")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

static INPUT_PORTS_START( sk2h1 )
	PORT_START ("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
	PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWA")
	PORT_DIPNAME( 0x03, 0x00, "Play Mode" )
	PORT_DIPSETTING(    0x00, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x03, "Tournament" )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWB")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_4C ) )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWC")
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNKNOWN )

	PORT_START ("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("IN2")      /* Player 3 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START3 )

	PORT_START( "EEPROMIN" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, do_read)

	PORT_START( "EEPROMOUT" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, di_write)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, clk_write)
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, cs_write)
INPUT_PORTS_END

static INPUT_PORTS_START( sk2h31 )
	PORT_START ("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
	PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWA")	/* there are lots of other combinations, but this covers the useful ones */
	PORT_DIPNAME( 0xff, 0xff, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0xde, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0xff, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0xfe, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0xfd, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0xfc, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(    0x7f, DEF_STR( 1C_7C ) )
	PORT_DIPSETTING(    0xdf, DEF_STR( 1C_8C ) )

	PORT_START ("DSWB")      /* (not used, EEPROM) */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("DSWC")      /* (not used, EEPROM) */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START ("IN2")      /* Player 3 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START3 )

	PORT_START( "EEPROMIN" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, do_read)

	PORT_START( "EEPROMOUT" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, di_write)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, clk_write)
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, cs_write)
INPUT_PORTS_END

/********************************************************************
*
*  Machine Driver macro
*  ====================
*
*
********************************************************************/


void cps_state::wofsf2(machine_config &config)
{
	wofhfh(config);
	m_maincpu->set_addrmap(AS_PROGRAM, &cps_state::wofsf2_map);
}

void cps_state::daimakb(machine_config &config)
{
	cps1_10MHz(config);
	m_maincpu->set_addrmap(AS_PROGRAM, &cps_state::daimakb_map);
}

void cps_state::sk2h3(machine_config &config)
{
	wofhfh(config);
	m_maincpu->set_addrmap(AS_PROGRAM, &cps_state::sk2h3_map);
}

void cps_state::sk2h31(machine_config &config)
{
	wofhfh(config);
	m_maincpu->set_addrmap(AS_PROGRAM, &cps_state::sk2h31_map);
}

void cps_state::sk2h35(machine_config &config)
{
	qsound(config);
	m_maincpu->set_addrmap(AS_PROGRAM, &cps_state::sk2h35_map);
}

void cps_state::cps1frog(machine_config &config)
{
	/* basic machine hardware */
	M68000(config, m_maincpu, XTAL(10'000'000));    /* verified on pcb */
	m_maincpu->set_addrmap(AS_PROGRAM, &cps_state::cps1frog_map);
	m_maincpu->set_vblank_int("screen", FUNC(cps_state::cps1_interrupt));
	m_maincpu->set_addrmap(m68000_base_device::AS_CPU_SPACE, &cps_state::cpu_space_map);

	Z80(config, m_audiocpu, XTAL(3'579'545));  /* verified on pcb */
	m_audiocpu->set_addrmap(AS_PROGRAM, &cps_state::sub_map);

	MCFG_MACHINE_START_OVERRIDE(cps_state, cps1)

	/* video hardware */
	SCREEN(config, m_screen, SCREEN_TYPE_RASTER);
	m_screen->set_raw(8'000'000, 518, 64, 448, 259, 16, 240);
	m_screen->set_screen_update(FUNC(cps_state::screen_update_cps1));
	m_screen->screen_vblank().set(FUNC(cps_state::screen_vblank_cps1));
	m_screen->set_palette(m_palette);

	GFXDECODE(config, m_gfxdecode, m_palette, gfx_cps1);
	PALETTE(config, m_palette).set_entries(0xc00);

	MCFG_VIDEO_START_OVERRIDE(cps_state, cps1)

	/* sound hardware */
	SPEAKER(config, "mono").front_center();
	GENERIC_LATCH_8(config, m_soundlatch);
	GENERIC_LATCH_8(config, m_soundlatch2);
	ym2151_device &ym2151(YM2151(config, "2151", XTAL(3'579'545)));  /* verified on pcb */
	ym2151.irq_handler().set_inputline(m_audiocpu, 0);
	ym2151.add_route(0, "mono", 0.35);
	ym2151.add_route(1, "mono", 0.35);
	OKIM6295(config, m_oki, XTAL(16'000'000)/4/4, okim6295_device::PIN7_HIGH).add_route(ALL_OUTPUTS, "mono", 0.30);
}

void cps_state::sk2h1q(machine_config &config)
{
	cps1frog(config);

	/* basic machine hardware */
	m_maincpu->set_clock(XTAL(12'000'000));    /* verified on pcb */
	m_maincpu->set_addrmap(AS_PROGRAM, &cps_state::sk2h1q_map);

	Z80(config.replace(), m_audiocpu, XTAL(8'000'000));  /* verified on pcb */
	m_audiocpu->set_addrmap(AS_PROGRAM, &cps_state::qsound_sub_map);
	m_audiocpu->set_addrmap(AS_OPCODES, &cps_state::qsound_decrypted_opcodes_map);
	m_audiocpu->set_periodic_int(FUNC(cps_state::irq0_line_hold), attotime::from_hz(250)); // measured (cps2.cpp)

	MCFG_MACHINE_START_OVERRIDE(cps_state, qsound)

	EEPROM_93C46_16BIT(config, "eeprom");

	/* sound hardware */
	config.device_remove("mono");
	SPEAKER(config, "lspeaker").front_left();
	SPEAKER(config, "rspeaker").front_right();

	config.device_remove("2151");
	config.device_remove("oki");

	qsound_device &qsound(QSOUND(config, "qsound"));
	qsound.add_route(0, "lspeaker", 1.0);
	qsound.add_route(1, "rspeaker", 1.0);
}

void cps_state::sk2h31q(machine_config &config)
{
	sk2h1q(config);
	m_maincpu->set_addrmap(AS_PROGRAM, &cps_state::sk2h31q_map);
}

/***************************************************************************

	Driver initialisation

***************************************************************************/


void cps_state::init_dinoeh()
{
	m_maincpu->space(AS_PROGRAM).install_write_handler(0x800180, 0x800181, write16_delegate(FUNC(cps_state::dinoh_sound_command_w),this));
	kabuki_setup(dino_decode);
	init_cps1();
}

void cps_state::init_dinoh()
{
	/* Patch out Q-Sound test */
	uint16_t *rom = (uint16_t *)memregion("maincpu")->base();
	rom[0xaacf4/2] = 0x4e71;
	init_dinoeh();
}

void cps_state::init_dinoz()
{
	uint16_t *rom = (uint16_t *)memregion("maincpu")->base();
	rom[0xaaa82/2] = 0x4e71; // Patch out Q-Sound test
	rom[0x1cfb4/2] = 0x4e71; // patch out invalid instruction
	init_dinoeh();
}

void cps_state::init_dinohb()
{
	uint8_t *mem8 = memregion("maincpu")->base();
	// Fix draw scroll
//	mem8[0x006c2] = 0xC0;
//	mem8[0x006c3] = 0xFF;
	// Fix gfx
	mem8[0x472] = 0xFC;
	mem8[0x473] = 0x33;
	mem8[0x474] = 0x0;
	mem8[0x475] = 0x90;
	mem8[0x476] = 0x80;
	mem8[0x478] = 0x0;
	mem8[0x479] = 0x1;
	mem8[0x47A] = 0xFC;
	mem8[0x47B] = 0x33;
	mem8[0x47C] = 0x80;
	mem8[0x47D] = 0x90;
	mem8[0x47E] = 0x80;
	mem8[0x480] = 0x2;
	mem8[0x481] = 0x1;
	mem8[0x482] = 0xFC;
	mem8[0x483] = 0x33;
	mem8[0x484] = 0xC0;
	mem8[0x485] = 0x90;
	mem8[0x486] = 0x80;
	mem8[0x487] = 0x0;
	mem8[0x488] = 0x4;
	mem8[0x489] = 0x1;
	mem8[0x48A] = 0xFC;
	mem8[0x48B] = 0x33;
	mem8[0x48C] = 0x0;
	mem8[0x48D] = 0x91;
	mem8[0x48E] = 0x80;
	mem8[0x48F] = 0x0;
	mem8[0x490] = 0x6;
	mem8[0x491] = 0x1;
	mem8[0x006cc] = 0x80;
	mem8[0x006cd] = 0x00;
	mem8[0x006ce] = 0x0C;
	mem8[0x006cf] = 0x01;
	mem8[0x006de] = 0x80;
	mem8[0x006df] = 0x00;
	mem8[0x006e0] = 0x10;
	mem8[0x006e1] = 0x01;
	mem8[0x006f0] = 0x80;
	mem8[0x006f1] = 0x00;
	mem8[0x006f2] = 0x14;
	mem8[0x006f3] = 0x01;
	mem8[0x00704] = 0x80;
	mem8[0x00705] = 0x00;
	mem8[0x00706] = 0x0E;
	mem8[0x00707] = 0x01;
	mem8[0x00718] = 0x80;
	mem8[0x00719] = 0x00;
	mem8[0x0071a] = 0x12;
	mem8[0x0071b] = 0x01;
	mem8[0x0072c] = 0x80;
	mem8[0x0072d] = 0x00;
	mem8[0x0072e] = 0x16;
	mem8[0x0072f] = 0x01;
	// Fix screen transitions
	mem8[0x00b28] = 0x00;
	mem8[0x00b29] = 0x70;
	mem8[0x00b2a] = 0x00;
	mem8[0x00b2b] = 0x72;
	mem8[0x00b2c] = 0x3C;
	mem8[0x00b2d] = 0x34;
	mem8[0x00b32] = 0xC1;
	mem8[0x00b33] = 0x20;
	// Fix sound
	mem8[0x00666] = 0xF1;
	mem8[0x00667] = 0x00;
	mem8[0x00668] = 0x02;
	mem8[0x00669] = 0x80;
	mem8[0xaaa6c] = 0xD8;
	mem8[0xaaa6d] = 0x00;

	kabuki_setup(dino_decode);
	init_cps1();
}

void cps_state::init_punisherb()
{
	// note: bytes are swapped around compared to rom_fill.
	uint8_t *mem8 = memregion("maincpu")->base();
	// Use standard ports
	mem8[0xAB3] = 0x33;
	mem8[0xAB4] = 0x30;
	mem8[0xAB6] = 0x80;
	mem8[0xAB7] = 0x0;
	mem8[0xAB8] = 0x56;
	mem8[0xAB9] = 0x1;
	mem8[0xABA] = 0xED;
	mem8[0xABB] = 0x33;
	mem8[0xABC] = 0x32;
	mem8[0xABD] = 0xDB;
	mem8[0xABE] = 0x80;
	mem8[0xABF] = 0x0;
	mem8[0xAC0] = 0x48;
	mem8[0xAC1] = 0x1;
	mem8[0xAC2] = 0xED;
	mem8[0xAC3] = 0x33;
	mem8[0xAC4] = 0x34;
	mem8[0xAC5] = 0xDB;
	mem8[0xAC6] = 0x80;
	mem8[0xAC7] = 0x0;
	mem8[0xAC8] = 0x4A;
	mem8[0xAC9] = 0x1;
	mem8[0xACA] = 0xED;
	mem8[0xACB] = 0x33;
	mem8[0xACC] = 0x2E;
	mem8[0xACD] = 0xDB;
	mem8[0xACE] = 0x80;
	mem8[0xAD0] = 0x52;
	mem8[0xAD1] = 0x1;
	mem8[0xAD2] = 0xED;
	mem8[0xAD3] = 0x33;
	mem8[0xAD4] = 0x88;
	mem8[0xAD5] = 0xDB;
	mem8[0xAD6] = 0x80;
	mem8[0xAD7] = 0x0;
	mem8[0xAD8] = 0x0;
	mem8[0xAD9] = 0x1;
	mem8[0xADA] = 0xED;
	mem8[0xADB] = 0x33;
	mem8[0xADC] = 0x8A;
	mem8[0xADD] = 0xDB;
	mem8[0xADE] = 0x80;
	mem8[0xADF] = 0x0;
	mem8[0xAE0] = 0x2;
	mem8[0xAE1] = 0x1;
	mem8[0xAE2] = 0xED;
	mem8[0xAE3] = 0x33;
	mem8[0xAE4] = 0x8C;
	mem8[0xAE5] = 0xDB;
	mem8[0xAE6] = 0x80;
	mem8[0xAE7] = 0x0;
	mem8[0xAE8] = 0x4;
	mem8[0xAE9] = 0x1;
	mem8[0xAEA] = 0xED;
	mem8[0xAEB] = 0x33;
	mem8[0xAEC] = 0x8E;
	mem8[0xAED] = 0xDB;
	mem8[0xAEE] = 0x80;
	mem8[0xAEF] = 0x0;
	mem8[0xAF0] = 0x6;
	mem8[0xAF1] = 0x1;
	mem8[0xAF2] = 0xED;
	mem8[0xAF3] = 0x33;
	mem8[0xAF4] = 0x90;
	mem8[0xAF5] = 0xDB;
	mem8[0xAF6] = 0x80;
	mem8[0xAF7] = 0x0;
	mem8[0xAF8] = 0x8;
	mem8[0xAF9] = 0x1;
	mem8[0xAFA] = 0xED;
	mem8[0xAFB] = 0x50;
	mem8[0xAFC] = 0x49;
	mem8[0xAFD] = 0xDB;
	mem8[0xAFE] = 0xFC;
	mem8[0xAFF] = 0x33;
	mem8[0xB00] = 0x3F;
	mem8[0xB02] = 0x80;
	mem8[0xB03] = 0x0;
	mem8[0xB04] = 0x4C;
	mem8[0xB05] = 0x1;
	mem8[0xB06] = 0xFC;
	mem8[0xB07] = 0x33;
	mem8[0xB08] = 0x40;
	mem8[0xB09] = 0x91;
	mem8[0xB0A] = 0x80;
	mem8[0xB0C] = 0xA;
	mem8[0xB0D] = 0x1;
	mem8[0xBA8] = 0x80;
	mem8[0xBAA] = 0xC;
	mem8[0xBAB] = 0x1;
	mem8[0xBBA] = 0x80;
	mem8[0xBBC] = 0x10;
	mem8[0xBBD] = 0x1;
	mem8[0xBCC] = 0x80;
	mem8[0xBCE] = 0x14;
	mem8[0xBCF] = 0x1;
	mem8[0xBDA] = 0x80;
	mem8[0xBDC] = 0xE;
	mem8[0xBDD] = 0x1;
	mem8[0xBEE] = 0x80;
	mem8[0xBF0] = 0x12;
	mem8[0xBF1] = 0x1;
	mem8[0xC02] = 0x80;
	mem8[0xC04] = 0x16;
	mem8[0xC05] = 0x1;
	// Transitions
	mem8[0x42b5] = 0;
	// Q sound
	mem8[0x4DBC] = 0x0;
	mem8[0x4DBE] = 0x58;
	mem8[0x4DBF] = 0x0;
	mem8[0x4DC0] = 0xF9;
	mem8[0x4DC1] = 0x41;
	mem8[0x4DC2] = 0xF1;
	mem8[0x4DC3] = 0x0;
	mem8[0x4DC4] = 0x0;
	mem8[0x4DC5] = 0x80;
	mem8[0x4DC6] = 0x28;
	mem8[0x4DC7] = 0x4A;
	mem8[0x4DC8] = 0x1F;
	mem8[0x4DC9] = 0x0;
	mem8[0x4DCA] = 0x0;
	mem8[0x4DCB] = 0x6A;
	mem8[0x4DCC] = 0x4A;
	mem8[0x4DCD] = 0x0;
	mem8[0x4DCE] = 0xED;
	mem8[0x4DCF] = 0x49;
	mem8[0x4DD0] = 0x96;
	mem8[0x4DD1] = 0xE2;
	mem8[0x4DD2] = 0xF4;
	mem8[0x4DD3] = 0x49;
	mem8[0x4DD4] = 0x0;
	mem8[0x4DD5] = 0x0;
	mem8[0x4DD6] = 0x40;
	mem8[0x4DD7] = 0x6;
	mem8[0x4DD8] = 0x10;
	mem8[0x4DDA] = 0x40;
	mem8[0x4DDB] = 0x2;
	mem8[0x4DDC] = 0xFF;
	mem8[0x4DDD] = 0xF;
	mem8[0x4DDE] = 0x40;
	mem8[0x4DDF] = 0x3B;
	mem8[0x4DE0] = 0xE8;
	mem8[0x4DE1] = 0xDA;
	mem8[0x4DE2] = 0x5C;
	mem8[0x4DE3] = 0x11;
	mem8[0x4DE4] = 0x1;
	mem8[0x4DE6] = 0x5C;
	mem8[0x4DE7] = 0x11;
	mem8[0x4DE8] = 0x3;
	mem8[0x4DE9] = 0x0;
	mem8[0x4DEA] = 0x5C;
	mem8[0x4DEB] = 0x11;
	mem8[0x4DEC] = 0x7;
	mem8[0x4DED] = 0x0;
	mem8[0x4DEE] = 0x5C;
	mem8[0x4DEF] = 0x11;
	mem8[0x4DF0] = 0x9;
	mem8[0x4DF1] = 0x0;
	mem8[0x4DF2] = 0x1C;
	mem8[0x4DF3] = 0x30;
	mem8[0x4DF4] = 0x40;
	mem8[0x4DF5] = 0x11;
	mem8[0x4DF6] = 0xD;
	mem8[0x4DF7] = 0x0;
	mem8[0x4DF8] = 0x5C;
	mem8[0x4DF9] = 0x11;
	mem8[0x4DFA] = 0xF;
	mem8[0x4DFB] = 0x0;
	mem8[0x4DFC] = 0x5C;
	mem8[0x4DFD] = 0x11;
	mem8[0x4DFE] = 0x11;
	mem8[0x4E00] = 0x5C;
	mem8[0x4E01] = 0x11;
	mem8[0x4E02] = 0x17;
	mem8[0x4E04] = 0x5C;
	mem8[0x4E05] = 0x11;
	mem8[0x4E06] = 0x19;
	mem8[0x4E07] = 0x0;
	mem8[0x4E08] = 0x5C;
	mem8[0x4E09] = 0x11;
	mem8[0x4E0A] = 0x13;
	mem8[0x4E0B] = 0x0;
	mem8[0x4E0C] = 0x5C;
	mem8[0x4E0D] = 0x11;
	mem8[0x4E0E] = 0x15;
	mem8[0x4E0F] = 0x0;
	mem8[0x4E10] = 0x7C;
	mem8[0x4E11] = 0x11;
	mem8[0x4E12] = 0x0;
	mem8[0x4E14] = 0x1F;
	mem8[0x4E16] = 0x75;
	mem8[0x4E17] = 0x4E;
	// Sprites
	mem8[0x14CA0] = 0x90;
	mem8[0x14CA3] = 0x0;
	mem8[0x14CB0] = 0x90;
	mem8[0x14CB3] = 0x40;
	mem8[0x14F68] = 0xFC;
	mem8[0x14F69] = 0x28;
	mem8[0x14F6A] = 0x0;
	mem8[0x14F6D] = 0x1;

	kabuki_setup(punisher_decode);
	init_cps1();
}

void cps_state::init_sf2h9()
{
	/* Patch out protection check */
	uint16_t *rom = (uint16_t *)memregion("maincpu")->base();
	rom[0xc0670/2] = 0x4e71;
	init_cps1();
}

void cps_state::init_sf2h13()
{
	uint16_t *rom = (uint16_t *)memregion("maincpu")->base();

	// Fix scroll
	rom[0x1d22a/2] = 0x0120;
	// Fix bg layer
	rom[0x1d270/2] = 0x0166;
	// Fix gfx
	rom[0x1d470/2] = 0x0170;

	// Fix title gfx
	rom[0x21bec/2] = 0x0083;
	rom[0x21cf8/2] = 0x828e;
	rom[0x21cfa/2] = 0x829e;
	rom[0x21cfc/2] = 0x82ae;
	rom[0x21d06/2] = 0x827f;
	rom[0x21d08/2] = 0x828f;
	rom[0x21d0a/2] = 0x829f;
	rom[0x21d0c/2] = 0x82af;
	rom[0x21d16/2] = 0x827e;
	rom[0x21d18/2] = 0x82a0;
	rom[0x21d1a/2] = 0x822c;
	rom[0x21d1c/2] = 0x823c;
	rom[0x21d2a/2] = 0x822d;

	init_cps1();
}

void cps_state::init_wofb()
{
	uint8_t *mem8 = memregion("maincpu")->base();
	// Fix gfx
	mem8[0x506] = 0xE7;
	mem8[0x507] = 0x48;
	mem8[0x508] = 0xFE;
	mem8[0x509] = 0xFF;
	mem8[0x50A] = 0xF8;
	mem8[0x50B] = 0x4B;
	mem8[0x6ABC] = 0x6;
	mem8[0x6ABD] = 0x1;
	// Fix sound
	mem8[0x764E] = 0x71;
	mem8[0x7650] = 0x71;
	mem8[0x7651] = 0x4E;
	// Fix screen transitions
	mem8[0x5D236] = 0xFC;
	mem8[0x5D237] = 0x28;
	mem8[0x5D238] = 0x0;
	mem8[0x5D23B] = 0x1;

	kabuki_setup(wof_decode);
	init_cps1();
}

void cps_state::init_sk2h35()
{
	uint8_t *mem8 = memregion("maincpu")->base();
	// Patch Q sound protection? check
	mem8[0x5A1A] = 0x00;
	mem8[0x5A1B] = 0x67;
	mem8[0x5A1C] = 0x56;
	mem8[0x5A1D] = 0x00;
	mem8[0x5A1E] = 0x7C;
	mem8[0x5A1F] = 0x20;
	mem8[0x5A20] = 0xF1;
	mem8[0x5A21] = 0x00;
	mem8[0x5A22] = 0x00;
	mem8[0x5A23] = 0x80;
	mem8[0x5A24] = 0x28;
	mem8[0x5A25] = 0x4A;
	mem8[0x5A26] = 0x1F;
	mem8[0x5A27] = 0x00;
	mem8[0x5A28] = 0x00;
	mem8[0x5A29] = 0x6A;
	mem8[0x5A40] = 0x5C;
	mem8[0x5A41] = 0x11;
	mem8[0x5A42] = 0x01;
	mem8[0x5A43] = 0x00;
	mem8[0x5A44] = 0x5C;
	mem8[0x5A45] = 0x11;
	mem8[0x5A46] = 0x03;
	mem8[0x5A47] = 0x00;
	mem8[0x5A4A] = 0x07;
	mem8[0x5A4B] = 0x00;
	mem8[0x5A4C] = 0x5C;
	mem8[0x5A4D] = 0x11;
	mem8[0x5A4E] = 0x09;
	mem8[0x5A4F] = 0x00;
	mem8[0x5A50] = 0x5C;
	mem8[0x5A51] = 0x31;
	mem8[0x5A52] = 0x0C;
	mem8[0x5A53] = 0x00;
	mem8[0x5A54] = 0x5C;
	mem8[0x5A55] = 0x11;
	mem8[0x5A56] = 0x0F;
	mem8[0x5A57] = 0x00;
	mem8[0x5A58] = 0x5C;
	mem8[0x5A59] = 0x11;
	mem8[0x72A6] = 0x71;
	mem8[0x72A7] = 0x4E;
	mem8[0x72A8] = 0x71;
	mem8[0x72A9] = 0x4E;
	mem8[0x72AA] = 0x71;
	mem8[0x72AB] = 0x4E;
	mem8[0x72AC] = 0x71;
	mem8[0x72AD] = 0x4E;
	mem8[0x72AE] = 0x71;
	mem8[0x72AF] = 0x4E;
	mem8[0x72B0] = 0x71;
	mem8[0x72B1] = 0x4E;
	mem8[0x72B2] = 0x39;
	mem8[0x72B3] = 0x30;
	mem8[0x72B4] = 0xF1;
	mem8[0x72B5] = 0x00;
	mem8[0x72B6] = 0xFE;
	mem8[0x72B7] = 0x9F;
	mem8[0x72B8] = 0x00;
	mem8[0x72B9] = 0x0C;
	/* enable coin slots 1 and 2 */
	mem8[0x71bc] = 0x0c;
	kabuki_setup(wof_decode);
	init_cps1();
}

void cps_state::init_sk2h1q()
{
	uint8_t *mem8 = memregion("maincpu")->base();
	// Stage Order
	mem8[0x72a6] = 0x00;
	// Disable Sprite Recoding
	mem8[0x5d858] = 0x00;
	mem8[0x5d859] = 0x61;
	mem8[0x5d85a] = 0xe6;
	mem8[0x5d85b] = 0x01;
	mem8[0x5d890] = 0x6d;
	mem8[0x5d891] = 0x0c;
	mem8[0x5d892] = 0x00;
	mem8[0x5d893] = 0x90;
	mem8[0x5d894] = 0xd2;
	mem8[0x5d895] = 0xe3;
	mem8[0x5d8e8] = 0x90;
	mem8[0x5d8e9] = 0x00;
	mem8[0x5d8ea] = 0x00;
	mem8[0x5d8eb] = 0x00;
	mem8[0x5d8f8] = 0x90;
	mem8[0x5d8f9] = 0x00;
	mem8[0x5d8fa] = 0x00;
	mem8[0x5d8fb] = 0x40;
	// Patch protection? check
	mem8[0xf11ec] = 0x71;
	mem8[0xf11ed] = 0x4e;
	mem8[0xf11ee] = 0x71;
	mem8[0xf11ef] = 0x4e;
	// Patch Q sound protection? check
	mem8[0x5A0E] = 0x39;
	mem8[0x5A0F] = 0x30;
	mem8[0x5A10] = 0xF1;
	mem8[0x5A12] = 0xFE;
	mem8[0x5A13] = 0x9F;
	mem8[0x5A14] = 0x00;
	mem8[0x5A15] = 0x0C;
	mem8[0x5A16] = 0x77;
	mem8[0x5A17] = 0x00;
	mem8[0x5A18] = 0xF4;
	mem8[0x5A19] = 0x66;
	mem8[0x5A1A] = 0xF9;
	mem8[0x5A1B] = 0x4E;
	mem8[0x5A1C] = 0x00;
	mem8[0x5A1E] = 0xB2;
	mem8[0x5A1F] = 0x72;
	mem8[0x5A20] = 0x7C;
	mem8[0x5A21] = 0x20;
	mem8[0x5A22] = 0xF1;
	mem8[0x5A23] = 0x00;
	mem8[0x5A24] = 0x00;
	mem8[0x5A25] = 0x80;
	mem8[0x5A26] = 0x7C;
	mem8[0x5A27] = 0x11;
	mem8[0x5A29] = 0x00;
	mem8[0x5A2A] = 0x01;
	mem8[0x5A2C] = 0x7C;
	mem8[0x5A2D] = 0x11;
	mem8[0x5A2E] = 0x10;
	mem8[0x5A2F] = 0x00;
	mem8[0x5A30] = 0x0F;
	mem8[0x5A31] = 0x00;
	mem8[0x5A32] = 0x7C;
	mem8[0x5A33] = 0x11;
	mem8[0x5A34] = 0x00;
	mem8[0x5A35] = 0x00;
	mem8[0x5A36] = 0x07;
	mem8[0x5A38] = 0x7C;
	mem8[0x5A39] = 0x11;
	mem8[0x5A3A] = 0x00;
	mem8[0x5A3B] = 0x00;
	mem8[0x5A3C] = 0x09;
	mem8[0x5A3D] = 0x00;
	mem8[0x5A3E] = 0x7C;
	mem8[0x5A3F] = 0x11;
	mem8[0x5A40] = 0x00;
	mem8[0x5A41] = 0x00;
	mem8[0x5A42] = 0x0C;
	mem8[0x5A44] = 0x41;
	mem8[0x5A48] = 0x7C;
	mem8[0x5A4A] = 0x00;
	mem8[0x5A4C] = 0x11;
	mem8[0x5A4D] = 0x00;
	mem8[0x5A4E] = 0x7C;
	mem8[0x5A4F] = 0x11;
	mem8[0x5A50] = 0x00;
	mem8[0x5A51] = 0x00;
	mem8[0x5A52] = 0x17;
	mem8[0x5A54] = 0x7C;
	mem8[0x5A56] = 0x00;
	mem8[0x5A58] = 0x19;
	mem8[0x5A59] = 0x00;
	mem8[0x5A5A] = 0x7C;
	mem8[0x5A5B] = 0x11;
	mem8[0x5A5C] = 0x00;
	mem8[0x5A5D] = 0x00;
	mem8[0x5A5E] = 0x13;
	mem8[0x5A60] = 0x7C;
	mem8[0x5A62] = 0x00;
	mem8[0x5A64] = 0x15;
	mem8[0x5A65] = 0x00;
	mem8[0x5A66] = 0x7C;
	mem8[0x5A67] = 0x11;
	mem8[0x5A68] = 0x00;
	mem8[0x5A69] = 0x00;
	mem8[0x5A6A] = 0x1F;
	mem8[0x5A6C] = 0xF9;
	mem8[0x5A6D] = 0x4E;
	mem8[0x5A6E] = 0x05;
	mem8[0x5A70] = 0x2C;
	mem8[0x5A71] = 0xE8;
	mem8[0x729A] = 0xF9;
	mem8[0x729C] = 0x00;
	mem8[0x729D] = 0x00;
	mem8[0x729E] = 0x0E;
	mem8[0x729F] = 0x5A;
	mem8[0x5E826] = 0xF9;
	mem8[0x5E827] = 0x4E;
	mem8[0x5E828] = 0x00;
	mem8[0x5E82A] = 0x20;
	mem8[0x5E82B] = 0x5A;
	kabuki_setup(wof_decode);
	init_cps1();
}

void cps_state::init_sk2h1()
{
	uint8_t *mem8 = memregion("maincpu")->base();
	// Stage Order
	mem8[0x72a6] = 0x00;
	// Disable Sprite Recoding
	mem8[0x5d858] = 0x00;
	mem8[0x5d859] = 0x61;
	mem8[0x5d85a] = 0xe6;
	mem8[0x5d85b] = 0x01;
	mem8[0x5d890] = 0x6d;
	mem8[0x5d891] = 0x0c;
	mem8[0x5d892] = 0x00;
	mem8[0x5d893] = 0x90;
	mem8[0x5d894] = 0xd2;
	mem8[0x5d895] = 0xe3;
	mem8[0x5d8e8] = 0x90;
	mem8[0x5d8e9] = 0x00;
	mem8[0x5d8ea] = 0x00;
	mem8[0x5d8eb] = 0x00;
	mem8[0x5d8f8] = 0x90;
	mem8[0x5d8f9] = 0x00;
	mem8[0x5d8fa] = 0x00;
	mem8[0x5d8fb] = 0x40;
	// Patch protection? check
	mem8[0xf11ec] = 0x71;
	mem8[0xf11ed] = 0x4e;
	mem8[0xf11ee] = 0x71;
	mem8[0xf11ef] = 0x4e;
	init_cps1();
}

void cps_state::init_sk2h3()
{
	uint8_t *mem8 = memregion("maincpu")->base();
	// Disable Sprite Recoding
	mem8[0x5d858] = 0x00;
	mem8[0x5d859] = 0x61;
	mem8[0x5d85a] = 0xe6;
	mem8[0x5d85b] = 0x01;
	mem8[0x5d890] = 0x6d;
	mem8[0x5d891] = 0x0c;
	mem8[0x5d892] = 0x00;
	mem8[0x5d893] = 0x90;
	mem8[0x5d894] = 0xd2;
	mem8[0x5d895] = 0xe3;
	mem8[0x5d8e8] = 0x90;
	mem8[0x5d8eb] = 0x00;
	mem8[0x5d8f8] = 0x90;

	//Transitions
	//mem8[0x02449] = 0x07; // fixed by above code

	//Protections
	mem8[0x708da] = 0xff;
	mem8[0x708db] = 0xff;
	mem8[0x708dc] = 0xff;
	mem8[0x708dd] = 0xff;
	mem8[0xf11eb] = 0x60;

	//Start at stage 1
	mem8[0x072a6] = 0x00;

	init_cps1();
}

void cps_state::init_sk2h21()
{
	uint8_t *mem8 = memregion("maincpu")->base();
	// Patch Q sound protection? check
	mem8[0x0554] = 0xb4;
	mem8[0x0555] = 0x54;
	mem8[0x5A50] = 0x5c;
	mem8[0x5A51] = 0x31;
	mem8[0x5A52] = 0x0c;
	mem8[0x5A53] = 0x00;
	mem8[0x5A54] = 0x5c;
	mem8[0x5A55] = 0x11;
	mem8[0x5A56] = 0x0f;
	mem8[0x5A58] = 0x5c;
	mem8[0x5A59] = 0x11;
	mem8[0x5A5A] = 0x11;
	mem8[0x5A5B] = 0x00;
	kabuki_setup(wof_decode);
	init_cps1();
}

void cps_state::init_sk2h22()
{
	uint8_t *mem8 = memregion("maincpu")->base();
	// Protection
	mem8[0xE7AD0] = 0x71;
	mem8[0xE7AD1] = 0x4E;

	// Disable Sprite Recoding
	mem8[0x5de96] = 0x00;
	mem8[0x5de97] = 0x61;
	mem8[0x5de98] = 0xe6;
	mem8[0x5de99] = 0x01;
	mem8[0x5dece] = 0x6d;
	mem8[0x5decf] = 0x0c;
	mem8[0x5ded0] = 0x00;
	mem8[0x5ded1] = 0x90;
	mem8[0x5ded2] = 0xd2;
	mem8[0x5ded3] = 0xe3;
	mem8[0x5df26] = 0x90;
	mem8[0x5df29] = 0x00;
	mem8[0x5df36] = 0x90;

	init_cps1();
}

void cps_state::init_sk2h31()
{
	uint8_t *mem8 = memregion("maincpu")->base();
	// Disable Sprite Recoding
	mem8[0x5de96] = 0x00;
	mem8[0x5de97] = 0x61;
	mem8[0x5de98] = 0xe6;
	mem8[0x5de99] = 0x01;
	mem8[0x5dece] = 0x6d;
	mem8[0x5decf] = 0x0c;
	mem8[0x5ded0] = 0x00;
	mem8[0x5ded1] = 0x90;
	mem8[0x5ded2] = 0xd2;
	mem8[0x5ded3] = 0xe3;
	mem8[0x5df26] = 0x90;
	mem8[0x5df29] = 0x00;
	mem8[0x5df36] = 0x90;

	// Patch Q sound protection? check
	mem8[0x5A0E] = 0x39;
	mem8[0x5A0F] = 0x30;
	mem8[0x5A10] = 0xF1;
	mem8[0x5A12] = 0xFE;
	mem8[0x5A13] = 0x9F;
	mem8[0x5A14] = 0x00;
	mem8[0x5A15] = 0x0C;
	mem8[0x5A16] = 0x77;
	mem8[0x5A17] = 0x00;
	mem8[0x5A18] = 0xF4;
	mem8[0x5A19] = 0x66;
	mem8[0x5A1A] = 0xF9;
	mem8[0x5A1B] = 0x4E;
	mem8[0x5A1C] = 0x00;
	mem8[0x5A1E] = 0xBE;
	mem8[0x5A1F] = 0x72;
	mem8[0x5A20] = 0x7C;
	mem8[0x5A21] = 0x20;
	mem8[0x5A22] = 0xF1;
	mem8[0x5A23] = 0x00;
	mem8[0x5A24] = 0x00;
	mem8[0x5A25] = 0x80;
	mem8[0x5A26] = 0x7C;
	mem8[0x5A27] = 0x11;
	mem8[0x5A29] = 0x00;
	mem8[0x5A2A] = 0x01;
	mem8[0x5A2C] = 0x7C;
	mem8[0x5A2D] = 0x11;
	mem8[0x5A2E] = 0x10;
	mem8[0x5A2F] = 0x00;
	mem8[0x5A30] = 0x0F;
	mem8[0x5A31] = 0x00;
	mem8[0x5A32] = 0x7C;
	mem8[0x5A33] = 0x11;
	mem8[0x5A34] = 0x00;
	mem8[0x5A35] = 0x00;
	mem8[0x5A36] = 0x07;
	mem8[0x5A38] = 0x7C;
	mem8[0x5A39] = 0x11;
	mem8[0x5A3A] = 0x00;
	mem8[0x5A3B] = 0x00;
	mem8[0x5A3C] = 0x09;
	mem8[0x5A3D] = 0x00;
	mem8[0x5A3E] = 0x7C;
	mem8[0x5A3F] = 0x11;
	mem8[0x5A40] = 0x00;
	mem8[0x5A41] = 0x00;
	mem8[0x5A42] = 0x0C;
	mem8[0x5A44] = 0x41;
	mem8[0x5A48] = 0x7C;
	mem8[0x5A4A] = 0x00;
	mem8[0x5A4C] = 0x11;
	mem8[0x5A4D] = 0x00;
	mem8[0x5A4E] = 0x7C;
	mem8[0x5A4F] = 0x11;
	mem8[0x5A50] = 0x00;
	mem8[0x5A51] = 0x00;
	mem8[0x5A52] = 0x17;
	mem8[0x5A54] = 0x7C;
	mem8[0x5A56] = 0x00;
	mem8[0x5A58] = 0x19;
	mem8[0x5A59] = 0x00;
	mem8[0x5A5A] = 0x7C;
	mem8[0x5A5B] = 0x11;
	mem8[0x5A5C] = 0x00;
	mem8[0x5A5D] = 0x00;
	mem8[0x5A5E] = 0x13;
	mem8[0x5A60] = 0x7C;
	mem8[0x5A62] = 0x00;
	mem8[0x5A64] = 0x15;
	mem8[0x5A65] = 0x00;
	mem8[0x5A66] = 0x7C;
	mem8[0x5A67] = 0x11;
	mem8[0x5A68] = 0x00;
	mem8[0x5A69] = 0x00;
	mem8[0x5A6A] = 0x1F;
	mem8[0x5A6C] = 0xF9;
	mem8[0x5A6D] = 0x4E;
	mem8[0x5A6E] = 0x05;
	mem8[0x5A70] = 0x6A;
	mem8[0x5A71] = 0xEE;
	mem8[0x72A6] = 0xF9;
	mem8[0x72A8] = 0x00;
	mem8[0x72A9] = 0x00;
	mem8[0x72AA] = 0x0E;
	mem8[0x72AB] = 0x5A;
	mem8[0x5EE64] = 0xF9;
	mem8[0x5EE65] = 0x4E;
	mem8[0x5EE66] = 0x00;
	mem8[0x5EE68] = 0x20;
	mem8[0x5EE69] = 0x5A;
	kabuki_setup(wof_decode);
	init_cps1();
}

/**********************************************************************

	Roms

***********************************************************************/




ROM_START( cps1demo )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )
	ROM_LOAD16_BYTE( "cd30-36.bin",  0x00000, 0x20000, CRC(5eb617d6) SHA1(9d4656d2b29244eb2a01058f5b80752d94065a6e) )
	ROM_LOAD16_BYTE( "cd35-42.bin",  0x00001, 0x20000, CRC(1f1c0a62) SHA1(12d1950921fff6d52ae969a4c7357f4e7bc28d1e) )
	ROM_LOAD16_WORD_SWAP( "ff32-32m.bin", 0x80000, 0x80000, CRC(c747696e) SHA1(d3362dadded31ccb7eaf71ef282d698d18edd722) )

	ROM_REGION( 0x200000, "gfx", 0 )
	ROMX_LOAD( "cd05-05m.bin", 0x000000, 0x80000, CRC(35dc6153) SHA1(7b7747d4e6a78c0933b6ea96fa6027c2c2c50682) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "cd07-07m.bin", 0x000002, 0x80000, CRC(baf08a38) SHA1(82559384399c5dfb8979a2e91d585549357ebb52) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "cd01-01m.bin", 0x000004, 0x80000, CRC(3ad8e790) SHA1(a371edc81a48903d13ed8938dca450dab986b413) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "cd03-03m.bin", 0x000006, 0x80000, CRC(fb5186f3) SHA1(b20031c01b6be2a4987553c0ab19105714bf9299) , ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x18000, "audiocpu", 0 )
	ROM_LOAD( "ff_09.12b",   0x00000, 0x08000, CRC(b8367eb5) SHA1(ec3db29fdd6200e9a8f4f8073a7e34aef731354f) )
	ROM_CONTINUE(              0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki", 0 )
	ROM_LOAD( "ff_18.11c",  0x00000, 0x20000, CRC(375c66e7) SHA1(36189e23209ce4ae5d9cbabd1574540d0591e7b3) )
	ROM_LOAD( "ff_19.12c",  0x20000, 0x20000, CRC(1ef137f9) SHA1(974b5e72aa28b87ebfa7438efbdfeda769dedf5e) )

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "cps1demo.key",*/ // 0x00, 0x80, CRC(b0e5ee2d) SHA1(8189f48892fff7dc4fff4e765448e0ea2cfba4bc) )
ROM_END

ROM_START( cps1frog )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )
	ROM_LOAD16_BYTE( "frog30-36.bin",  0x00000, 0x20000, CRC(8eb8ddbe) SHA1(298c72b3eb6f2721f204cf80ec4a7c52dc8b23fd) )
	ROM_LOAD16_BYTE( "frog35-42.bin",  0x00001, 0x20000, CRC(acb5a988) SHA1(7264bb94f7bacef9bf03713d0a6d32e81ca1f8e2) )
	ROM_LOAD16_WORD_SWAP( "frog32-32m.bin", 0x80000, 0x80000, CRC(75660aac) SHA1(6a521e1d2a632c26e53b83d2cc4b0edecfc1e68c) )

	ROM_REGION( 0x200000, "gfx", 0 )
	ROMX_LOAD( "frog05-05m.bin", 0x000000, 0x80000, CRC(7bbc4b54) SHA1(5a40bd85ce71dc733071732a8306d648b3e6dd39) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "frog07-07m.bin", 0x000002, 0x80000, CRC(0beadd80) SHA1(f43d6ad936b8ffa242c17d8da26bf2e2a12d85a8) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "frog01-01m.bin", 0x000004, 0x80000, CRC(f84d02bb) SHA1(b89322ab65a3b3e8202c27af62de2b182a4ed2e9) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "frog03-03m.bin", 0x000006, 0x80000, CRC(d784a5b0) SHA1(8891bb8fc39f51db200c51e2a65961c351d655c2) , ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x18000, "audiocpu", 0 )
	ROM_LOAD( "frog09-09.bin",   0x00000, 0x08000, CRC(3ac7fb5c) SHA1(01057078b67dc82d80403533a3dca3deb95f166c) )
	ROM_CONTINUE(              0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki", 0 )
	ROM_LOAD( "frog18-18.bin",  0x00000, 0x20000, CRC(65d1ef07) SHA1(0bc2dbf5053430f659d64d1b287799bb5cc4db65) )
	ROM_LOAD( "frog19-19.bin",  0x20000, 0x20000, CRC(7ee8cdcd) SHA1(67dfd19f3eb3649d6f3f6631e44d0bd36b8d8d19) )

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "cps1frog.key",*/ // 0x00, 0x80, CRC(3adeff30) SHA1(5d242a4e5edcf47905fb50d767d41c2977bfd78b) )
ROM_END

ROM_START( cps1tests )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "cps1tests.bin", 0x000000, 0x80000, CRC(938c72fe) SHA1(0a48661d5638ed6b841f646ebb9f948a01b8e2d3) )
	ROM_LOAD16_WORD_SWAP( "s92_22b.7f",  0x080000, 0x80000, CRC(2bbe15ed) SHA1(a8e2edef62fa99c5ef701b28bfb6bc42f3af183d) )
	ROM_LOAD16_WORD_SWAP( "s92_21a.6f",  0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1) )

	ROM_REGION( 0x600000, "gfx", 0 )
	ROMX_LOAD( "s92-1m.3a",  0x000000, 0x80000, CRC(03b0d852) SHA1(f370f25c96ad2b94f8c53d6b7139100285a25bef) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-3m.5a",  0x000002, 0x80000, CRC(840289ec) SHA1(2fb42a242f60ba7e74009b5a90eb26e035ba1e82) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-2m.4a",  0x000004, 0x80000, CRC(cdb5f027) SHA1(4c7d944fef200fdfcaf57758b901b5511188ed2e) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-4m.6a",  0x000006, 0x80000, CRC(e2799472) SHA1(27d3796429338d82a8de246a0ea06dd487a87768) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-5m.7a",  0x200000, 0x80000, CRC(ba8a2761) SHA1(4b696d66c51611e43522bed752654314e76d33b6) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-7m.9a",  0x200002, 0x80000, CRC(e584bfb5) SHA1(ebdf1f5e2638eed3a65dda82b1ed9151a355f4c9) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-6m.8a",  0x200004, 0x80000, CRC(21e3f87d) SHA1(4a4961bb68c3a1ce15f9d393d9c03ecb2466cc29) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-8m.10a", 0x200006, 0x80000, CRC(befc47df) SHA1(520390420da3a0271ba90b0a933e65143265e5cf) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-10m.3c", 0x400000, 0x80000, CRC(960687d5) SHA1(2868c31121b1c7564e9767b9a19cdbf655c7ed1d) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-12m.5c", 0x400002, 0x80000, CRC(978ecd18) SHA1(648a59706b93c84b4206a968ecbdc3e834c476f6) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-11m.4c", 0x400004, 0x80000, CRC(d6ec9a0a) SHA1(ed6143f8737013b6ef1684e37c05e037e7a80dae) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-13m.6c", 0x400006, 0x80000, CRC(ed2c67f6) SHA1(0083c0ffaf6fe7659ff0cf822be4346cd6e61329) , ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x18000, "audiocpu", 0 )
	ROM_LOAD( "s92_09.11a",  0x00000, 0x08000, CRC(08f6b60e) SHA1(8258fcaca4ac419312531eec67079b97f471179c) )
	ROM_CONTINUE(            0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki", 0 )
	ROM_LOAD( "s92_18.11c",  0x00000, 0x20000, CRC(7f162009) SHA1(346bf42992b4c36c593e21901e22c87ae4a7d86d) )
	ROM_LOAD( "s92_19.12c",  0x20000, 0x20000, CRC(beade53f) SHA1(277c397dc12752719ec6b47d2224750bd1c07f79) )

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "sf2ce.key",*/ // 0x00, 0x80, CRC(35b37429) SHA1(b372cce106c0900554735c207fb333ac93554ec2) )
ROM_END

ROM_START( cps1testsa )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "cps1testsa.bin", 0x000000, 0x80000, CRC(8c24eb40) SHA1(0d9ebc078dd22e3b45eaf872d90eb973eb07aeeb) )
	ROM_LOAD16_WORD_SWAP( "s92_22b.7f",  0x080000, 0x80000, CRC(2bbe15ed) SHA1(a8e2edef62fa99c5ef701b28bfb6bc42f3af183d) )
	ROM_LOAD16_WORD_SWAP( "s92_21a.6f",  0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1) )

	ROM_REGION( 0x600000, "gfx", 0 )
	ROMX_LOAD( "s92-1m.3a",  0x000000, 0x80000, CRC(03b0d852) SHA1(f370f25c96ad2b94f8c53d6b7139100285a25bef) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-3m.5a",  0x000002, 0x80000, CRC(840289ec) SHA1(2fb42a242f60ba7e74009b5a90eb26e035ba1e82) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-2m.4a",  0x000004, 0x80000, CRC(cdb5f027) SHA1(4c7d944fef200fdfcaf57758b901b5511188ed2e) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-4m.6a",  0x000006, 0x80000, CRC(e2799472) SHA1(27d3796429338d82a8de246a0ea06dd487a87768) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-5m.7a",  0x200000, 0x80000, CRC(ba8a2761) SHA1(4b696d66c51611e43522bed752654314e76d33b6) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-7m.9a",  0x200002, 0x80000, CRC(e584bfb5) SHA1(ebdf1f5e2638eed3a65dda82b1ed9151a355f4c9) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-6m.8a",  0x200004, 0x80000, CRC(21e3f87d) SHA1(4a4961bb68c3a1ce15f9d393d9c03ecb2466cc29) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-8m.10a", 0x200006, 0x80000, CRC(befc47df) SHA1(520390420da3a0271ba90b0a933e65143265e5cf) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-10m.3c", 0x400000, 0x80000, CRC(960687d5) SHA1(2868c31121b1c7564e9767b9a19cdbf655c7ed1d) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-12m.5c", 0x400002, 0x80000, CRC(978ecd18) SHA1(648a59706b93c84b4206a968ecbdc3e834c476f6) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-11m.4c", 0x400004, 0x80000, CRC(d6ec9a0a) SHA1(ed6143f8737013b6ef1684e37c05e037e7a80dae) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "s92-13m.6c", 0x400006, 0x80000, CRC(ed2c67f6) SHA1(0083c0ffaf6fe7659ff0cf822be4346cd6e61329) , ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x18000, "audiocpu", 0 )
	ROM_LOAD( "s92_09.11a",  0x00000, 0x08000, CRC(08f6b60e) SHA1(8258fcaca4ac419312531eec67079b97f471179c) )
	ROM_CONTINUE(            0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki", 0 )
	ROM_LOAD( "s92_18.11c",  0x00000, 0x20000, CRC(7f162009) SHA1(346bf42992b4c36c593e21901e22c87ae4a7d86d) )
	ROM_LOAD( "s92_19.12c",  0x20000, 0x20000, CRC(beade53f) SHA1(277c397dc12752719ec6b47d2224750bd1c07f79) )

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "sf2ce.key",*/ // 0x00, 0x80, CRC(35b37429) SHA1(b372cce106c0900554735c207fb333ac93554ec2) )
ROM_END

ROM_START( cps1testm )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "cps1testm.bin", 0x000000, 0x80000, CRC(35a39adb) SHA1(dcb93102108a02f1f169833cfd355bd492cd9065) )
	ROM_LOAD16_WORD_SWAP( "rcmu_22b.7f", 0x080000, 0x80000, CRC(708268c4) SHA1(554e011cad285b95dd1b6aa19be61b2413662a3a) )
	ROM_LOAD16_WORD_SWAP( "rcmu_21a.6f", 0x100000, 0x80000, CRC(4376ea95) SHA1(7370ceffca513aa9f68a74f6869d561476589200) )

	ROM_REGION( 0x800000, "gfx", 0 )
	ROMX_LOAD( "rcm_01.3a",  0x000000, 0x80000, CRC(6ecdf13f) SHA1(2a8fe06bf5011e3f990f90d9224f91d8631ec0cc) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_02.4a",  0x000002, 0x80000, CRC(944d4f0f) SHA1(665dc9a537e9c9b565f6136f939ff5c2861f875f) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_03.5a",  0x000004, 0x80000, CRC(36f3073c) SHA1(457d68e63599d06a136e152a9ad60adac1c91edd) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_04.6a",  0x000006, 0x80000, CRC(54e622ff) SHA1(36f6297e3d410f041be5e582919478b0d52520ca) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_05.7a",  0x200000, 0x80000, CRC(5dd131fd) SHA1(1a7fc8cf38901245d40901996e946e7ad9c0e0c5) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_06.8a",  0x200002, 0x80000, CRC(f0faf813) SHA1(adff01c2ecc4c8ce6f8a50cbd07d8f8bb9f48168) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_07.9a",  0x200004, 0x80000, CRC(826de013) SHA1(47f36b1d92a487c43c8dadc8293b8e6f40649286) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_08.10a", 0x200006, 0x80000, CRC(fbff64cf) SHA1(f0cb531ef195dc1dcd224a208906a62fb5d199a1) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_10.3c",  0x400000, 0x80000, CRC(4dc8ada9) SHA1(776c2b3ef24c2b8f390c05a9c6728b14ceec696e) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_11.4c",  0x400002, 0x80000, CRC(f2b9ee06) SHA1(db315b00d1caed1a8c0f6e0ae726e8fa05b011fa) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_12.5c",  0x400004, 0x80000, CRC(fed5f203) SHA1(23db14490519b5e2d0bb92ffe6e14540d1999e4b) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_13.6c",  0x400006, 0x80000, CRC(5069d4a9) SHA1(b832b98be94371af52bd4bb911e18ec57430a7db) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_14.7c",  0x600000, 0x80000, CRC(303be3bd) SHA1(1e5c3fd71966ea9f457840c40582795b501c323e) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_15.8c",  0x600002, 0x80000, CRC(4f2d372f) SHA1(db6a94d1f92c1b96e404b38ebcb1eedbec3ae6cc) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_16.9c",  0x600004, 0x80000, CRC(93d97fde) SHA1(e4be5216f98ad08a9118d629d398be2bd54e2e2a) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_17.10c", 0x600006, 0x80000, CRC(92371042) SHA1(c55833cbaddcc986edd23c009a3e3c7ff09c2708) , ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x18000, "audiocpu", 0 )
	ROM_LOAD( "rcm_09.11a",  0x00000, 0x08000, CRC(22ac8f5f) SHA1(d1441d880f98034645cb4fcecd7bb746bde638af) )
	ROM_CONTINUE(            0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki", 0 )
	ROM_LOAD( "rcm_18.11c",  0x00000, 0x20000, CRC(80f1f8aa) SHA1(4a5b7b2a6941ad68da7472c63362c7bcd353fa54) )
	ROM_LOAD( "rcm_19.12c",  0x20000, 0x20000, CRC(f257dbe1) SHA1(967def6b6f93039dbc46373caabeb3301577be75) )

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "megaman.key",*/ // 0x00, 0x80, CRC(9c89eb62) SHA1(e67a3ed58f82875cff4861c14bd701b54dcc111f) )
ROM_END

ROM_START( cps1testma )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "cps1testma.bin", 0x000000, 0x80000, CRC(ca31eddc) SHA1(ee9841fc398de4d8dc083bfaf0d6e2b488fc8779) )
	ROM_LOAD16_WORD_SWAP( "rcmu_22b.7f", 0x080000, 0x80000, CRC(708268c4) SHA1(554e011cad285b95dd1b6aa19be61b2413662a3a) )
	ROM_LOAD16_WORD_SWAP( "rcmu_21a.6f", 0x100000, 0x80000, CRC(4376ea95) SHA1(7370ceffca513aa9f68a74f6869d561476589200) )

	ROM_REGION( 0x800000, "gfx", 0 )
	ROMX_LOAD( "rcm_01.3a",  0x000000, 0x80000, CRC(6ecdf13f) SHA1(2a8fe06bf5011e3f990f90d9224f91d8631ec0cc) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_02.4a",  0x000002, 0x80000, CRC(944d4f0f) SHA1(665dc9a537e9c9b565f6136f939ff5c2861f875f) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_03.5a",  0x000004, 0x80000, CRC(36f3073c) SHA1(457d68e63599d06a136e152a9ad60adac1c91edd) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_04.6a",  0x000006, 0x80000, CRC(54e622ff) SHA1(36f6297e3d410f041be5e582919478b0d52520ca) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_05.7a",  0x200000, 0x80000, CRC(5dd131fd) SHA1(1a7fc8cf38901245d40901996e946e7ad9c0e0c5) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_06.8a",  0x200002, 0x80000, CRC(f0faf813) SHA1(adff01c2ecc4c8ce6f8a50cbd07d8f8bb9f48168) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_07.9a",  0x200004, 0x80000, CRC(826de013) SHA1(47f36b1d92a487c43c8dadc8293b8e6f40649286) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_08.10a", 0x200006, 0x80000, CRC(fbff64cf) SHA1(f0cb531ef195dc1dcd224a208906a62fb5d199a1) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_10.3c",  0x400000, 0x80000, CRC(4dc8ada9) SHA1(776c2b3ef24c2b8f390c05a9c6728b14ceec696e) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_11.4c",  0x400002, 0x80000, CRC(f2b9ee06) SHA1(db315b00d1caed1a8c0f6e0ae726e8fa05b011fa) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_12.5c",  0x400004, 0x80000, CRC(fed5f203) SHA1(23db14490519b5e2d0bb92ffe6e14540d1999e4b) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_13.6c",  0x400006, 0x80000, CRC(5069d4a9) SHA1(b832b98be94371af52bd4bb911e18ec57430a7db) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_14.7c",  0x600000, 0x80000, CRC(303be3bd) SHA1(1e5c3fd71966ea9f457840c40582795b501c323e) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_15.8c",  0x600002, 0x80000, CRC(4f2d372f) SHA1(db6a94d1f92c1b96e404b38ebcb1eedbec3ae6cc) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_16.9c",  0x600004, 0x80000, CRC(93d97fde) SHA1(e4be5216f98ad08a9118d629d398be2bd54e2e2a) , ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "rcm_17.10c", 0x600006, 0x80000, CRC(92371042) SHA1(c55833cbaddcc986edd23c009a3e3c7ff09c2708) , ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x18000, "audiocpu", 0 )
	ROM_LOAD( "rcm_09.11a",  0x00000, 0x08000, CRC(22ac8f5f) SHA1(d1441d880f98034645cb4fcecd7bb746bde638af) )
	ROM_CONTINUE(            0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki", 0 )
	ROM_LOAD( "rcm_18.11c",  0x00000, 0x20000, CRC(80f1f8aa) SHA1(4a5b7b2a6941ad68da7472c63362c7bcd353fa54) )
	ROM_LOAD( "rcm_19.12c",  0x20000, 0x20000, CRC(f257dbe1) SHA1(967def6b6f93039dbc46373caabeb3301577be75) )

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "megaman.key",*/ // 0x00, 0x80, CRC(9c89eb62) SHA1(e67a3ed58f82875cff4861c14bd701b54dcc111f) )
ROM_END


ROM_START( daimakb )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )
	ROM_LOAD16_BYTE( "dmjb2.bin", 0x00000, 0x80000, CRC(7d5f9f84) SHA1(b334b3af610892ef4efe4764017659b8541a10c6) )
	ROM_LOAD16_BYTE( "dmjb1.bin", 0x00001, 0x80000, CRC(9b945cc4) SHA1(dfdfabfd8ef06cee6be27350f79c5db4c6ace611) )

	ROM_REGION( 0x300000, "gfx", 0 )
	ROMX_LOAD( "dm_02.4b",  0x000000, 0x20000, CRC(8b98dc48) SHA1(e827881e2ba5cccd907d1692a1945c1b75d46f12) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_01.4a",  0x000001, 0x20000, CRC(80896c33) SHA1(20ffc427c596828005e34cdd8e4efa0d332262e9) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_10.9b",  0x000002, 0x20000, CRC(c2e7d9ef) SHA1(52aae6cf373f8c7150833047be28b74dd5eb5af6) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_09.9a",  0x000003, 0x20000, CRC(c9c4afa5) SHA1(34571e3e49c86b87fa34eefbc5f9fe258aba5f1a) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_18.5e",  0x000004, 0x20000, CRC(1aa0db99) SHA1(69ac302b2f6f0b96f78cb57b0b4cdae464086262) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_17.5c",  0x000005, 0x20000, CRC(dc6ed8ad) SHA1(1ffc4a48a7ff9b542ab6f63a60bea3c1a7a6e63b) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_30.8h",  0x000006, 0x20000, CRC(d9d3f8bd) SHA1(6c6853a384f8d60ca46a0607fd47c76a83700fba) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_29.8f",  0x000007, 0x20000, CRC(49a48796) SHA1(76c18c684dba4aa91ee6caae0f38fe3e1cc50832) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_04.5b",  0x100000, 0x20000, CRC(a4f4f8f0) SHA1(edca0f61b40a18afe279f7007c233064130cfb4f) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_03.5a",  0x100001, 0x20000, CRC(b1033e62) SHA1(547fc281dd9e7a74ac86c3692508c7bde9b6167b) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_12.10b", 0x100002, 0x20000, CRC(10fdd76a) SHA1(aee774d6323292799dff7a30ef9559c92fe5507a) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_11.10a", 0x100003, 0x20000, CRC(9040cb04) SHA1(b32e9056fc20a5162868eade10f3ef5efc167a28) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_20.7e",  0x100004, 0x20000, CRC(281d0b3e) SHA1(70e1813de184ad0ec164145b7b843b5e387494e3) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_19.7c",  0x100005, 0x20000, CRC(2623b52f) SHA1(fc4200924452bfbff687934782398ed345dc0aa0) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_32.9h",  0x100006, 0x20000, CRC(99692344) SHA1(67dc70618568b7c0adcb00a612aaf5501f6c8c0f) , ROM_SKIP(7) )
	ROMX_LOAD( "dm_31.9f",  0x100007, 0x20000, CRC(54acb729) SHA1(d1fca43db36253fd19db4337c49272a6cadff597) , ROM_SKIP(7) )
	ROMX_LOAD( "09.4a",     0x200000, 0x10000, CRC(ae24bb19) SHA1(aa91c6ffe657b878e10e4e930457b530f7bb529b) , ROM_SKIP(7) )
	ROMX_LOAD( "18.7a",     0x200001, 0x10000, CRC(d34e271a) SHA1(55211fc2861dce32951f41624c9c99c09bf3b184) , ROM_SKIP(7) )
	ROMX_LOAD( "13.4e",     0x200002, 0x10000, CRC(3f70dd37) SHA1(9ecb4dec9d131e9fca15ded7d71986a9fcb62c19) , ROM_SKIP(7) )
	ROMX_LOAD( "22.7e",     0x200003, 0x10000, CRC(7e69e2e6) SHA1(4e0b4d2474beaa5c869c8f1a91893c79ac6e7f39) , ROM_SKIP(7) )
	ROMX_LOAD( "11.4c",     0x200004, 0x10000, CRC(37c9b6c6) SHA1(b2bb82537e335339846dbf9588cfacfdbdd75ee6) , ROM_SKIP(7) )
	ROMX_LOAD( "20.7c",     0x200005, 0x10000, CRC(2f1345b4) SHA1(14c450abcf9defa29c6f48e5ffd0b9d1e4a66a1d) , ROM_SKIP(7) )
	ROMX_LOAD( "15.4g",     0x200006, 0x10000, CRC(3c2a212a) SHA1(f8fa0e0e2d09ea37c54d1c2493752b4e97e3f534) , ROM_SKIP(7) )
	ROMX_LOAD( "24.7g",     0x200007, 0x10000, CRC(889aac05) SHA1(9301dcecee699e7f7672bb498122e1f4831ce536) , ROM_SKIP(7) )
	ROMX_LOAD( "10.4b",     0x280000, 0x10000, CRC(bcc0f28c) SHA1(02f587aa4ae71631f27b0e3aaf1829cdded1bdc2) , ROM_SKIP(7) )
	ROMX_LOAD( "19.7b",     0x280001, 0x10000, CRC(2a40166a) SHA1(dc4e75d7ed87ae5386d721a09113bba364740465) , ROM_SKIP(7) )
	ROMX_LOAD( "14.4f",     0x280002, 0x10000, CRC(20f85c03) SHA1(86385139a9b42270aade758bfe338525936f5671) , ROM_SKIP(7) )
	ROMX_LOAD( "23.7f",     0x280003, 0x10000, CRC(8426144b) SHA1(2dbf9625413b302fcdad5bef8733a9dfbfaead52) , ROM_SKIP(7) )
	ROMX_LOAD( "12.4d",     0x280004, 0x10000, CRC(da088d61) SHA1(67229eff2827a42af97a60ceb252e132e7f307bc) , ROM_SKIP(7) )
	ROMX_LOAD( "21.7d",     0x280005, 0x10000, CRC(17e11df0) SHA1(42fb15e9300b07fc5f4bc21744484869859b130c) , ROM_SKIP(7) )
	ROMX_LOAD( "16.4h",     0x280006, 0x10000, CRC(f187ba1c) SHA1(6d9441d04ecef2a9d9c7a2cc7781acd7904c2061) , ROM_SKIP(7) )
	ROMX_LOAD( "25.7h",     0x280007, 0x10000, CRC(29f79c78) SHA1(26000a58454a06c3016f99ebc3a79c52911a7070) , ROM_SKIP(7) )

	ROM_REGION( 0x18000, "audiocpu", 0 )
	ROM_LOAD( "26.10a",     0x00000, 0x08000, CRC(3692f6e5) SHA1(61b8438d60a39b4cf5062dff0a53228e8a4e4b5f) )
	ROM_CONTINUE(           0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki", ROMREGION_ERASEFF ) // to keep validation quiet

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "daimakb.key",*/ // 0x00, 0x80, CRC(c72cad61) SHA1(9036e06c84ff9189a83acd50a703fb6560ce5e98) )
ROM_END





ROM_START( pnicku )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )
	ROM_LOAD16_BYTE( "pnij_36.12f",  0x00000, 0x20000, CRC(2d4ffb2b) SHA1(6e49cf89a36834fd1de8b4b860fe66f3d7d67a84) )
	ROM_LOAD16_BYTE( "pnicku.42",    0x00001, 0x20000, CRC(22d20227) SHA1(a103c9b1f6134c529405bd258da9f601c1459c47) )

	ROM_REGION( 0x200000, "gfx", 0 )
	ROMX_LOAD( "pnij_09.4b",  0x000000, 0x20000, CRC(48177b0a) SHA1(eba5de6cd9bb0c4ad76a13bddc9cdeb2e4380122) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_01.4a",  0x000001, 0x20000, CRC(01a0f311) SHA1(9bcd8716f90ccd410543ffcdc5c2916077b8d4c3) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_13.9b",  0x000002, 0x20000, CRC(406451b0) SHA1(5a7a7fecba7de8b8cf4a284b2ae7adae901623f6) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_05.9a",  0x000003, 0x20000, CRC(8c515dc0) SHA1(aa1e13cf9e7cf0458bb5c4332b1ea73034f9a874) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_26.5e",  0x000004, 0x20000, CRC(e2af981e) SHA1(3c2b28b4a4d457aa94a760dfca0181a9f050c319) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_18.5c",  0x000005, 0x20000, CRC(f17a0e56) SHA1(7c89aca230f176e12f995892f9d1bce22c57fbdf) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_38.8h",  0x000006, 0x20000, CRC(eb75bd8c) SHA1(2129460e06eb64019fc5f7eab6334ff43229b995) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_32.8f",  0x000007, 0x20000, CRC(84560bef) SHA1(9e94ae434b50ecf82781080e11d0c4741e992d0d) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_10.5b",  0x100000, 0x20000, CRC(c2acc171) SHA1(7c86db3f2acca1252d403c5f12c871d0357fa109) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_02.5a",  0x100001, 0x20000, CRC(0e21fc33) SHA1(c4a29d45c4257c8871038d3c9b13140e874db0c1) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_14.10b", 0x100002, 0x20000, CRC(7fe59b19) SHA1(a273b8b8fbfd5d31d25479a9ede09ce35e1cc873) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_06.10a", 0x100003, 0x20000, CRC(79f4bfe3) SHA1(bc17cc1c8535e3d202588893713926b6c06f92fd) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_27.7e",  0x100004, 0x20000, CRC(83d5cb0e) SHA1(44c93fa5eedcafc8dc6d88ee827c6cadc9c671f0) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_19.7c",  0x100005, 0x20000, CRC(af08b230) SHA1(a3b5b3013012efa1860699648518f8d8031c5f30) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_39.9h",  0x100006, 0x20000, CRC(70fbe579) SHA1(b5b7ed5588ecd884b20dd50bfc5385a9af03c5d8) , ROM_SKIP(7) )
	ROMX_LOAD( "pnij_33.9f",  0x100007, 0x20000, CRC(3ed2c680) SHA1(0afe84d8d89f8d45afc79f6172337e622e29a8a2) , ROM_SKIP(7) )

	ROM_REGION( 0x18000, "audiocpu", 0 )
	ROM_LOAD( "pnij_17.13b",  0x00000, 0x08000, CRC(e86f787a) SHA1(de04cbe89c655faf04afe169bfd9913049ccc4a8) )
	ROM_CONTINUE(             0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki", 0 )
	ROM_LOAD( "pnij_24.12c",  0x00000, 0x20000, CRC(5092257d) SHA1(95dc9d10940653b2fb37baf5c1ed27145b02104e) )
	ROM_LOAD( "pnij_25.13c",  0x20000, 0x20000, CRC(22109aaa) SHA1(cf21e75674d81b2daae2083d02f9f4b6e52722c6) )

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "pnickj.key",*/ // 0x00, 0x80, CRC(38afadc4) SHA1(05b49635f99e7cb97a99b9666239d68154cb3641) )
ROM_END







/*************************************************************************************************************************/



// PSmame (c) gaston90 used with permission

 /****************************************************
         Proyecto Shadows Mame Build Plus
*****************************************************/


/********************
 Street Fighter Zero
**********************/

ROM_START( sfzchs01 )
	ROM_REGION( CODE_SIZE, "maincpu",0 )
	ROM_LOAD16_WORD_SWAP( "sfzch23s01",    0x000000, 0x80000, CRC(02a1a853) SHA1(d92b9e774844fdcc9d9946b3e892b021e672d876))
	ROM_LOAD16_WORD_SWAP( "sfza22",         0x080000, 0x80000, CRC(8d9b2480) SHA1(405305c1572908d00eab735f28676fbbadb4fac6))
	ROM_LOAD16_WORD_SWAP( "sfzch21",        0x100000, 0x80000, CRC(5435225d) SHA1(6b1156fd82d0710e244ede39faaae0847c598376))
	ROM_LOAD16_WORD_SWAP( "sfza20",         0x180000, 0x80000, CRC(806e8f38) SHA1(b6d6912aa8f2f590335d7ff9a8214648e7131ebb))

	ROM_REGION( 0x800000, "gfx", 0 )
	ROMX_LOAD( "sfz_01.3a",  0x000000, 0x80000, CRC(0dd53e62) SHA1(5f3bcf5ca0fd564d115fe5075a4163d3ee3226df), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_02.4a",  0x000002, 0x80000, CRC(94c31e3f) SHA1(2187b3d4977514f2ae486eb33ed76c86121d5745), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_03.5a",  0x000004, 0x80000, CRC(9584ac85) SHA1(bbd62d66b0f6909630e801ce5d6331d43f44d741), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_04.6a",  0x000006, 0x80000, CRC(b983624c) SHA1(841106bb9453e3dfb7869c4b0e9149cc610d515a), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_05.7a",  0x200000, 0x80000, CRC(2b47b645) SHA1(bc6426eff5df9417f32666586744626fa544f7b5), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_06.8a",  0x200002, 0x80000, CRC(74fd9fb1) SHA1(7945472591f3c06970e96611a0363ed8f3d52c36), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_07.9a",  0x200004, 0x80000, CRC(bb2c734d) SHA1(97a06935f86f31755d2ffdc5b56bef53944bdecd), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_08.10a", 0x200006, 0x80000, CRC(454f7868) SHA1(eecccba7542d893bc41676246a20aa4914b79bbc), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_10.3c",  0x400000, 0x80000, CRC(2a7d675e) SHA1(0144ba34a29fb08b41c780ce65bb06d25724e88f), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_11.4c",  0x400002, 0x80000, CRC(e35546c8) SHA1(7b08aa3413494d12c5c550263a5f00b64b98e6ab), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_12.5c",  0x400004, 0x80000, CRC(f122693a) SHA1(71ce901d8d30207e506b6a8d6a4e0fcf3a1b0eac), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_13.6c",  0x400006, 0x80000, CRC(7cf942c8) SHA1(a7109facb97a8a11ddf1b4e07de6ff3164d713a1), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_14.7c",  0x600000, 0x80000, CRC(09038c81) SHA1(3461d70902fbfb92ce40f804be6388276a01d153), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_15.8c",  0x600002, 0x80000, CRC(1aa17391) SHA1(b4d0f760a430b7fc4443b6c94da2659315c5b926), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_16.9c",  0x600004, 0x80000, CRC(19a5abd6) SHA1(73ba1de15c883fdc69fd7dccdb58d00ca512d4ea), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_17.10c", 0x600006, 0x80000, CRC(248b3b73) SHA1(95810a17b1caf6372b33ed3e4ee8a7e51482c70d), ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x8000, "stars", 0 )
	ROM_COPY( "gfx", 0x000000, 0x000000, 0x8000 )

	ROM_REGION( 0x18000, "audiocpu",0 )
	ROM_LOAD( "sfz_09.12a",  0x00000, 0x08000, CRC(c772628b) SHA1(ebc5b7c173caf1e151f733f23c1b20abec24e16d))
	ROM_CONTINUE(            0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki",0 )
	ROM_LOAD( "sfz_18.11c",  0x00000, 0x20000, CRC(61022b2d) SHA1(6369d0c1d08a30ee19b94e52ab1463a7784b9de5))
	ROM_LOAD( "sfz_19.12c",  0x20000, 0x20000, CRC(3b5886d5) SHA1(7e1b7d40ef77b5df628dd663d45a9a13c742cf58))

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "sfzch.key",*/ // 0x00, 0x80, CRC(8ac48367) SHA1(aeeab2c3436009d05dd9caa1b1929af4d7e607ae) )
ROM_END

ROM_START( sfzchs02 )
	ROM_REGION( CODE_SIZE, "maincpu",0 )
	ROM_LOAD16_WORD_SWAP( "sfzch23s02",    0x000000, 0x80000, CRC(9e5cd362) SHA1(cd1cf39e8e37038edc790e82bcd0dace90e406d1))
	ROM_LOAD16_WORD_SWAP( "sfza22",         0x080000, 0x80000, CRC(8d9b2480) SHA1(405305c1572908d00eab735f28676fbbadb4fac6))
	ROM_LOAD16_WORD_SWAP( "sfzch21",        0x100000, 0x80000, CRC(5435225d) SHA1(6b1156fd82d0710e244ede39faaae0847c598376))
	ROM_LOAD16_WORD_SWAP( "sfza20",         0x180000, 0x80000, CRC(806e8f38) SHA1(b6d6912aa8f2f590335d7ff9a8214648e7131ebb))

	ROM_REGION( 0x800000, "gfx", 0 )
	ROMX_LOAD( "sfz_01.3a",  0x000000, 0x80000, CRC(0dd53e62) SHA1(5f3bcf5ca0fd564d115fe5075a4163d3ee3226df), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_02.4a",  0x000002, 0x80000, CRC(94c31e3f) SHA1(2187b3d4977514f2ae486eb33ed76c86121d5745), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_03.5a",  0x000004, 0x80000, CRC(9584ac85) SHA1(bbd62d66b0f6909630e801ce5d6331d43f44d741), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_04.6a",  0x000006, 0x80000, CRC(b983624c) SHA1(841106bb9453e3dfb7869c4b0e9149cc610d515a), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_05.7a",  0x200000, 0x80000, CRC(2b47b645) SHA1(bc6426eff5df9417f32666586744626fa544f7b5), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_06.8a",  0x200002, 0x80000, CRC(74fd9fb1) SHA1(7945472591f3c06970e96611a0363ed8f3d52c36), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_07.9a",  0x200004, 0x80000, CRC(bb2c734d) SHA1(97a06935f86f31755d2ffdc5b56bef53944bdecd), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_08.10a", 0x200006, 0x80000, CRC(454f7868) SHA1(eecccba7542d893bc41676246a20aa4914b79bbc), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_10.3c",  0x400000, 0x80000, CRC(2a7d675e) SHA1(0144ba34a29fb08b41c780ce65bb06d25724e88f), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_11.4c",  0x400002, 0x80000, CRC(e35546c8) SHA1(7b08aa3413494d12c5c550263a5f00b64b98e6ab), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_12.5c",  0x400004, 0x80000, CRC(f122693a) SHA1(71ce901d8d30207e506b6a8d6a4e0fcf3a1b0eac), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_13.6c",  0x400006, 0x80000, CRC(7cf942c8) SHA1(a7109facb97a8a11ddf1b4e07de6ff3164d713a1), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_14.7c",  0x600000, 0x80000, CRC(09038c81) SHA1(3461d70902fbfb92ce40f804be6388276a01d153), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_15.8c",  0x600002, 0x80000, CRC(1aa17391) SHA1(b4d0f760a430b7fc4443b6c94da2659315c5b926), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_16.9c",  0x600004, 0x80000, CRC(19a5abd6) SHA1(73ba1de15c883fdc69fd7dccdb58d00ca512d4ea), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_17.10c", 0x600006, 0x80000, CRC(248b3b73) SHA1(95810a17b1caf6372b33ed3e4ee8a7e51482c70d), ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x8000, "stars", 0 )
	ROM_COPY( "gfx", 0x000000, 0x000000, 0x8000 )

	ROM_REGION( 0x18000, "audiocpu",0 )
	ROM_LOAD( "sfz_09.12a",  0x00000, 0x08000, CRC(c772628b) SHA1(ebc5b7c173caf1e151f733f23c1b20abec24e16d))
	ROM_CONTINUE(            0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki",0 )
	ROM_LOAD( "sfz_18.11c",  0x00000, 0x20000, CRC(61022b2d) SHA1(6369d0c1d08a30ee19b94e52ab1463a7784b9de5))
	ROM_LOAD( "sfz_19.12c",  0x20000, 0x20000, CRC(3b5886d5) SHA1(7e1b7d40ef77b5df628dd663d45a9a13c742cf58))

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "sfzch.key",*/ // 0x00, 0x80, CRC(8ac48367) SHA1(aeeab2c3436009d05dd9caa1b1929af4d7e607ae) )
ROM_END

ROM_START( sfzchs03 ) //sfzach
	ROM_REGION( CODE_SIZE, "maincpu",0 )
	ROM_LOAD16_WORD_SWAP( "sfzch23s03",    0x000000, 0x80000, CRC(2562108b) SHA1(b14ab732eb3d39f6fa590b6c75daf3965d7953e3))
	ROM_LOAD16_WORD_SWAP( "sfza22",         0x080000, 0x80000, CRC(8d9b2480) SHA1(405305c1572908d00eab735f28676fbbadb4fac6))
	ROM_LOAD16_WORD_SWAP( "sfzch21",        0x100000, 0x80000, CRC(5435225d) SHA1(6b1156fd82d0710e244ede39faaae0847c598376))
	ROM_LOAD16_WORD_SWAP( "sfza20",         0x180000, 0x80000, CRC(806e8f38) SHA1(b6d6912aa8f2f590335d7ff9a8214648e7131ebb))

	ROM_REGION( 0x800000, "gfx", 0 )
	ROMX_LOAD( "sfz_01.3a",  0x000000, 0x80000, CRC(0dd53e62) SHA1(5f3bcf5ca0fd564d115fe5075a4163d3ee3226df), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_02.4a",  0x000002, 0x80000, CRC(94c31e3f) SHA1(2187b3d4977514f2ae486eb33ed76c86121d5745), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_03.5a",  0x000004, 0x80000, CRC(9584ac85) SHA1(bbd62d66b0f6909630e801ce5d6331d43f44d741), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_04.6a",  0x000006, 0x80000, CRC(b983624c) SHA1(841106bb9453e3dfb7869c4b0e9149cc610d515a), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_05.7a",  0x200000, 0x80000, CRC(2b47b645) SHA1(bc6426eff5df9417f32666586744626fa544f7b5), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_06.8a",  0x200002, 0x80000, CRC(74fd9fb1) SHA1(7945472591f3c06970e96611a0363ed8f3d52c36), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_07.9a",  0x200004, 0x80000, CRC(bb2c734d) SHA1(97a06935f86f31755d2ffdc5b56bef53944bdecd), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_08.10a", 0x200006, 0x80000, CRC(454f7868) SHA1(eecccba7542d893bc41676246a20aa4914b79bbc), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_10.3c",  0x400000, 0x80000, CRC(2a7d675e) SHA1(0144ba34a29fb08b41c780ce65bb06d25724e88f), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_11.4c",  0x400002, 0x80000, CRC(e35546c8) SHA1(7b08aa3413494d12c5c550263a5f00b64b98e6ab), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_12.5c",  0x400004, 0x80000, CRC(f122693a) SHA1(71ce901d8d30207e506b6a8d6a4e0fcf3a1b0eac), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_13.6c",  0x400006, 0x80000, CRC(7cf942c8) SHA1(a7109facb97a8a11ddf1b4e07de6ff3164d713a1), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_14.7c",  0x600000, 0x80000, CRC(09038c81) SHA1(3461d70902fbfb92ce40f804be6388276a01d153), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_15.8c",  0x600002, 0x80000, CRC(1aa17391) SHA1(b4d0f760a430b7fc4443b6c94da2659315c5b926), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_16.9c",  0x600004, 0x80000, CRC(19a5abd6) SHA1(73ba1de15c883fdc69fd7dccdb58d00ca512d4ea), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_17.10c", 0x600006, 0x80000, CRC(248b3b73) SHA1(95810a17b1caf6372b33ed3e4ee8a7e51482c70d), ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x8000, "stars", 0 )
	ROM_COPY( "gfx", 0x000000, 0x000000, 0x8000 )

	ROM_REGION( 0x18000, "audiocpu",0 )
	ROM_LOAD( "sfz_09.12a",  0x00000, 0x08000, CRC(c772628b) SHA1(ebc5b7c173caf1e151f733f23c1b20abec24e16d))
	ROM_CONTINUE(            0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki",0 )
	ROM_LOAD( "sfz_18.11c",  0x00000, 0x20000, CRC(61022b2d) SHA1(6369d0c1d08a30ee19b94e52ab1463a7784b9de5))
	ROM_LOAD( "sfz_19.12c",  0x20000, 0x20000, CRC(3b5886d5) SHA1(7e1b7d40ef77b5df628dd663d45a9a13c742cf58))

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "sfzch.key",*/ // 0x00, 0x80, CRC(8ac48367) SHA1(aeeab2c3436009d05dd9caa1b1929af4d7e607ae) )
ROM_END

ROM_START( sfzchs04 ) //sfzech
	ROM_REGION( CODE_SIZE, "maincpu",0 )
	ROM_LOAD16_WORD_SWAP( "sfzch23s04",    0x000000, 0x80000, CRC(5ec7058f) SHA1(ef9133c9670e48d6244ac8d48c5c82bedee08874))
	ROM_LOAD16_WORD_SWAP( "sfza22",         0x080000, 0x80000, CRC(8d9b2480) SHA1(405305c1572908d00eab735f28676fbbadb4fac6))
	ROM_LOAD16_WORD_SWAP( "sfzch21",        0x100000, 0x80000, CRC(5435225d) SHA1(6b1156fd82d0710e244ede39faaae0847c598376))
	ROM_LOAD16_WORD_SWAP( "sfza20",         0x180000, 0x80000, CRC(806e8f38) SHA1(b6d6912aa8f2f590335d7ff9a8214648e7131ebb))

	ROM_REGION( 0x800000, "gfx", 0 )
	ROMX_LOAD( "sfz_01.3a",  0x000000, 0x80000, CRC(0dd53e62) SHA1(5f3bcf5ca0fd564d115fe5075a4163d3ee3226df), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_02.4a",  0x000002, 0x80000, CRC(94c31e3f) SHA1(2187b3d4977514f2ae486eb33ed76c86121d5745), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_03.5a",  0x000004, 0x80000, CRC(9584ac85) SHA1(bbd62d66b0f6909630e801ce5d6331d43f44d741), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_04.6a",  0x000006, 0x80000, CRC(b983624c) SHA1(841106bb9453e3dfb7869c4b0e9149cc610d515a), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_05.7a",  0x200000, 0x80000, CRC(2b47b645) SHA1(bc6426eff5df9417f32666586744626fa544f7b5), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_06.8a",  0x200002, 0x80000, CRC(74fd9fb1) SHA1(7945472591f3c06970e96611a0363ed8f3d52c36), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_07.9a",  0x200004, 0x80000, CRC(bb2c734d) SHA1(97a06935f86f31755d2ffdc5b56bef53944bdecd), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_08.10a", 0x200006, 0x80000, CRC(454f7868) SHA1(eecccba7542d893bc41676246a20aa4914b79bbc), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_10.3c",  0x400000, 0x80000, CRC(2a7d675e) SHA1(0144ba34a29fb08b41c780ce65bb06d25724e88f), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_11.4c",  0x400002, 0x80000, CRC(e35546c8) SHA1(7b08aa3413494d12c5c550263a5f00b64b98e6ab), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_12.5c",  0x400004, 0x80000, CRC(f122693a) SHA1(71ce901d8d30207e506b6a8d6a4e0fcf3a1b0eac), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_13.6c",  0x400006, 0x80000, CRC(7cf942c8) SHA1(a7109facb97a8a11ddf1b4e07de6ff3164d713a1), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_14.7c",  0x600000, 0x80000, CRC(09038c81) SHA1(3461d70902fbfb92ce40f804be6388276a01d153), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_15.8c",  0x600002, 0x80000, CRC(1aa17391) SHA1(b4d0f760a430b7fc4443b6c94da2659315c5b926), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_16.9c",  0x600004, 0x80000, CRC(19a5abd6) SHA1(73ba1de15c883fdc69fd7dccdb58d00ca512d4ea), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_17.10c", 0x600006, 0x80000, CRC(248b3b73) SHA1(95810a17b1caf6372b33ed3e4ee8a7e51482c70d), ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x8000, "stars", 0 )
	ROM_COPY( "gfx", 0x000000, 0x000000, 0x8000 )

	ROM_REGION( 0x18000, "audiocpu",0 )
	ROM_LOAD( "sfz_09.12a",  0x00000, 0x08000, CRC(c772628b) SHA1(ebc5b7c173caf1e151f733f23c1b20abec24e16d))
	ROM_CONTINUE(            0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki",0 )
	ROM_LOAD( "sfz_18.11c",  0x00000, 0x20000, CRC(61022b2d) SHA1(6369d0c1d08a30ee19b94e52ab1463a7784b9de5))
	ROM_LOAD( "sfz_19.12c",  0x20000, 0x20000, CRC(3b5886d5) SHA1(7e1b7d40ef77b5df628dd663d45a9a13c742cf58))

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "sfzch.key",*/ // 0x00, 0x80, CRC(8ac48367) SHA1(aeeab2c3436009d05dd9caa1b1929af4d7e607ae) )
ROM_END

ROM_START( sfzchs05 ) //sfzhch
	ROM_REGION( CODE_SIZE, "maincpu",0 )
	ROM_LOAD16_WORD_SWAP( "sfzch23s05",    0x000000, 0x80000, CRC(3683cce7) SHA1(103122b35cd14ac8aacc6d174799b1354f4a453d))
	ROM_LOAD16_WORD_SWAP( "sfza22",         0x080000, 0x80000, CRC(8d9b2480) SHA1(405305c1572908d00eab735f28676fbbadb4fac6))
	ROM_LOAD16_WORD_SWAP( "sfzch21",        0x100000, 0x80000, CRC(5435225d) SHA1(6b1156fd82d0710e244ede39faaae0847c598376))
	ROM_LOAD16_WORD_SWAP( "sfza20",         0x180000, 0x80000, CRC(806e8f38) SHA1(b6d6912aa8f2f590335d7ff9a8214648e7131ebb))

	ROM_REGION( 0x800000, "gfx", 0 )
	ROMX_LOAD( "sfz_01.3a",  0x000000, 0x80000, CRC(0dd53e62) SHA1(5f3bcf5ca0fd564d115fe5075a4163d3ee3226df), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_02.4a",  0x000002, 0x80000, CRC(94c31e3f) SHA1(2187b3d4977514f2ae486eb33ed76c86121d5745), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_03.5a",  0x000004, 0x80000, CRC(9584ac85) SHA1(bbd62d66b0f6909630e801ce5d6331d43f44d741), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_04.6a",  0x000006, 0x80000, CRC(b983624c) SHA1(841106bb9453e3dfb7869c4b0e9149cc610d515a), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_05.7a",  0x200000, 0x80000, CRC(2b47b645) SHA1(bc6426eff5df9417f32666586744626fa544f7b5), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_06.8a",  0x200002, 0x80000, CRC(74fd9fb1) SHA1(7945472591f3c06970e96611a0363ed8f3d52c36), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_07.9a",  0x200004, 0x80000, CRC(bb2c734d) SHA1(97a06935f86f31755d2ffdc5b56bef53944bdecd), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_08.10a", 0x200006, 0x80000, CRC(454f7868) SHA1(eecccba7542d893bc41676246a20aa4914b79bbc), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_10.3c",  0x400000, 0x80000, CRC(2a7d675e) SHA1(0144ba34a29fb08b41c780ce65bb06d25724e88f), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_11.4c",  0x400002, 0x80000, CRC(e35546c8) SHA1(7b08aa3413494d12c5c550263a5f00b64b98e6ab), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_12.5c",  0x400004, 0x80000, CRC(f122693a) SHA1(71ce901d8d30207e506b6a8d6a4e0fcf3a1b0eac), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_13.6c",  0x400006, 0x80000, CRC(7cf942c8) SHA1(a7109facb97a8a11ddf1b4e07de6ff3164d713a1), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_14.7c",  0x600000, 0x80000, CRC(09038c81) SHA1(3461d70902fbfb92ce40f804be6388276a01d153), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_15.8c",  0x600002, 0x80000, CRC(1aa17391) SHA1(b4d0f760a430b7fc4443b6c94da2659315c5b926), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_16.9c",  0x600004, 0x80000, CRC(19a5abd6) SHA1(73ba1de15c883fdc69fd7dccdb58d00ca512d4ea), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_17.10c", 0x600006, 0x80000, CRC(248b3b73) SHA1(95810a17b1caf6372b33ed3e4ee8a7e51482c70d), ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x8000, "stars", 0 )
	ROM_COPY( "gfx", 0x000000, 0x000000, 0x8000 )

	ROM_REGION( 0x18000, "audiocpu",0 )
	ROM_LOAD( "sfz_09.12a",  0x00000, 0x08000, CRC(c772628b) SHA1(ebc5b7c173caf1e151f733f23c1b20abec24e16d))
	ROM_CONTINUE(            0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki",0 )
	ROM_LOAD( "sfz_18.11c",  0x00000, 0x20000, CRC(61022b2d) SHA1(6369d0c1d08a30ee19b94e52ab1463a7784b9de5))
	ROM_LOAD( "sfz_19.12c",  0x20000, 0x20000, CRC(3b5886d5) SHA1(7e1b7d40ef77b5df628dd663d45a9a13c742cf58))

	/* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "sfzch.key",*/ // 0x00, 0x80, CRC(8ac48367) SHA1(aeeab2c3436009d05dd9caa1b1929af4d7e607ae) )
ROM_END

ROM_START( sfzchs06 ) //sfzbch
	ROM_REGION( CODE_SIZE, "maincpu",0 )
	ROM_LOAD16_WORD_SWAP( "sfzch23s06",    0x000000, 0x80000, CRC(4d26d9e3) SHA1(48b532e4656e77430fef5bda1d2e20ca543ff355))
	ROM_LOAD16_WORD_SWAP( "sfza22",         0x080000, 0x80000, CRC(8d9b2480) SHA1(405305c1572908d00eab735f28676fbbadb4fac6))
	ROM_LOAD16_WORD_SWAP( "sfzch21",        0x100000, 0x80000, CRC(5435225d) SHA1(6b1156fd82d0710e244ede39faaae0847c598376))
	ROM_LOAD16_WORD_SWAP( "sfza20",         0x180000, 0x80000, CRC(806e8f38) SHA1(b6d6912aa8f2f590335d7ff9a8214648e7131ebb))

	ROM_REGION( 0x800000, "gfx", 0 )
	ROMX_LOAD( "sfz_01.3a",  0x000000, 0x80000, CRC(0dd53e62) SHA1(5f3bcf5ca0fd564d115fe5075a4163d3ee3226df), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_02.4a",  0x000002, 0x80000, CRC(94c31e3f) SHA1(2187b3d4977514f2ae486eb33ed76c86121d5745), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_03.5a",  0x000004, 0x80000, CRC(9584ac85) SHA1(bbd62d66b0f6909630e801ce5d6331d43f44d741), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_04.6a",  0x000006, 0x80000, CRC(b983624c) SHA1(841106bb9453e3dfb7869c4b0e9149cc610d515a), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_05.7a",  0x200000, 0x80000, CRC(2b47b645) SHA1(bc6426eff5df9417f32666586744626fa544f7b5), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_06.8a",  0x200002, 0x80000, CRC(74fd9fb1) SHA1(7945472591f3c06970e96611a0363ed8f3d52c36), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_07.9a",  0x200004, 0x80000, CRC(bb2c734d) SHA1(97a06935f86f31755d2ffdc5b56bef53944bdecd), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_08.10a", 0x200006, 0x80000, CRC(454f7868) SHA1(eecccba7542d893bc41676246a20aa4914b79bbc), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_10.3c",  0x400000, 0x80000, CRC(2a7d675e) SHA1(0144ba34a29fb08b41c780ce65bb06d25724e88f), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_11.4c",  0x400002, 0x80000, CRC(e35546c8) SHA1(7b08aa3413494d12c5c550263a5f00b64b98e6ab), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_12.5c",  0x400004, 0x80000, CRC(f122693a) SHA1(71ce901d8d30207e506b6a8d6a4e0fcf3a1b0eac), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_13.6c",  0x400006, 0x80000, CRC(7cf942c8) SHA1(a7109facb97a8a11ddf1b4e07de6ff3164d713a1), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_14.7c",  0x600000, 0x80000, CRC(09038c81) SHA1(3461d70902fbfb92ce40f804be6388276a01d153), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_15.8c",  0x600002, 0x80000, CRC(1aa17391) SHA1(b4d0f760a430b7fc4443b6c94da2659315c5b926), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_16.9c",  0x600004, 0x80000, CRC(19a5abd6) SHA1(73ba1de15c883fdc69fd7dccdb58d00ca512d4ea), ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_17.10c", 0x600006, 0x80000, CRC(248b3b73) SHA1(95810a17b1caf6372b33ed3e4ee8a7e51482c70d), ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x8000, "stars", 0 )
	ROM_COPY( "gfx", 0x000000, 0x000000, 0x8000 )

	ROM_REGION( 0x18000, "audiocpu",0 )
	ROM_LOAD( "sfz_09.12a",  0x00000, 0x08000, CRC(c772628b) SHA1(ebc5b7c173caf1e151f733f23c1b20abec24e16d))
	ROM_CONTINUE(            0x10000, 0x08000 )

	ROM_REGION( 0x40000, "oki",0 )
	ROM_LOAD( "sfz_18.11c",  0x00000, 0x20000, CRC(61022b2d) SHA1(6369d0c1d08a30ee19b94e52ab1463a7784b9de5))
	ROM_LOAD( "sfz_19.12c",  0x20000, 0x20000, CRC(3b5886d5) SHA1(7e1b7d40ef77b5df628dd663d45a9a13c742cf58))

	/* /* ROM_REGION( 0x80, "control", 0 )
	ROM_LOAD ( "sfzch*/.key",*/ //// 0x00, 0x80, CRC(8ac48367) SHA1(aeeab2c3436009d05dd9caa1b1929af4d7e607ae) )
ROM_END


/***************************************************************************

        Driver Macros for HBMAME

***************************************************************************/

GAME( 2000, cps1demo,    0,        cps1frog,   cps1frog,  cps1,     ROT0,   "Charles Doty", "Demo - CPS1", GAME_SUPPORTS_SAVE ) // no sound
GAME( 2006, cps1frog,    0,        cps1frog,   cps1frog,  cps1,     ROT0,   "Rastersoft", "Frog Feast (CPS1)", GAME_SUPPORTS_SAVE )
GAME( 2012, cps1tests,   sf2ce,    cps1_12MHz, sf2, cps1,     ROT0,   "Cal2", "CPS1 Diagnostic (For sf2ce 2012-10-30)", GAME_SUPPORTS_SAVE )
GAME( 2012, cps1testsa,  sf2ce,    cps1_12MHz, sf2, cps1,     ROT0,   "Cal2", "CPS1 Diagnostic (For sf2ce 2012-10-29)", GAME_SUPPORTS_SAVE )
GAME( 2012, cps1testm,   megaman,  cps1_12MHz, megaman,   cps1,     ROT0,   "Cal2", "CPS1 Diagnostic (For megaman 2012-10-30)", GAME_SUPPORTS_SAVE )
GAME( 2012, cps1testma,  megaman,  cps1_12MHz, megaman,   cps1,     ROT0,   "Cal2", "CPS1 Diagnostic (For megaman 2012-10-29)", GAME_SUPPORTS_SAVE )

GAME( 1988, daimakb,     ghouls,   daimakb,    daimakai,  cps1,     ROT0,   "bootleg", "Dai Makai-Mura (Japan, bootleg)" , GAME_SUPPORTS_SAVE )

GAME( 1994, pnicku,      pnickj,   cps1_10MHz, pnicku,    cps1,     ROT0,   "Creamymami[EGCG]", "Pnickies (This Edition Is Just A Regional USA Version)", GAME_SUPPORTS_SAVE )

// Street Fighter Zero
GAME( 1995, sfzchs01,      sfzch,    cps1_12MHz, sfzch, cps1,     ROT0,   "Unknown", "Street Fighter Zero (CPS Changer - Street Fighter Alpha - Warriors' Dreams)", GAME_SUPPORTS_SAVE )
GAME( 2007, sfzchs02,      sfzch,    cps1_12MHz, sfzch, cps1,     ROT0,   "pipi899[EZ]", "Street Fighter Zero (Move Hack 2007-02-11)", GAME_SUPPORTS_SAVE )
GAME( 1995, sfzchs03,      sfzch,    cps1_12MHz, sfzch, cps1,     ROT0,   "Bootleg", "Street Fighter Zero (CPS Changer, Asia 950925)", GAME_SUPPORTS_SAVE )
GAME( 1995, sfzchs04,      sfzch,    cps1_12MHz, sfzch, cps1,     ROT0,   "Bootleg", "Street Fighter Zero (CPS Changer, Euro 950727)", GAME_SUPPORTS_SAVE )
GAME( 1995, sfzchs05,      sfzch,    cps1_12MHz, sfzch, cps1,     ROT0,   "Bootleg", "Street Fighter Zero (CPS Changer, Hispanic 950727)", GAME_SUPPORTS_SAVE )
GAME( 1995, sfzchs06,      sfzch,    cps1_12MHz, sfzch, cps1,     ROT0,   "Bootleg", "Street Fighter Zero (CPS Changer, Brazil 950727 hack)", GAME_SUPPORTS_SAVE )

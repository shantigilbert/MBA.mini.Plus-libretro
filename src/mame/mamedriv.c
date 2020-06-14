/******************************************************************************

    mamedriv.c

    Copyright Nicola Salmoria and the MAME Team.
    Visit http://mamedev.org for licensing and usage restrictions.

    The list of all available drivers. Drivers have to be included here to be
    recognized by the executable.

    To save some typing, we use a hack here. This file is recursively #included
    twice, with different definitions of the DRIVER() macro. The first one
    declares external references to the drivers; the second one builds an array
    storing all the drivers.

******************************************************************************/

#include "emu.h"

#ifndef DRIVER_RECURSIVE
#define DRIVER_RECURSIVE

/* step 1: declare all external references */
#define DRIVER(NAME)	GAME_EXTERN(NAME);
#include "mamedriv.c"

/* step 2: define the drivers[] array */
#undef DRIVER
#define DRIVER(NAME)	&GAME_NAME(NAME),

const game_driver *const drivers[] =
{
#include "mamedriv.c"
	0	/* end of array */
};

#else	/* DRIVER_RECURSIVE */

	/* *************** */
	/*  Part 1 - M92   */
	/* *************** */
	DRIVER( gunforce )		/* (c) 1991 Irem (World) */
	DRIVER( gunforceu )		/* (c) 1991 Irem America (US) */
	DRIVER( gunforcej )		/* (c) 1991 Irem (Japan) */
	DRIVER( bmaster )		/* (c) 1991 Irem */
	DRIVER( crossbld )		/* (c) 1991 Irem (Japan) */
	DRIVER( lethalth )		/* (c) 1991 Irem (World) */
	DRIVER( thndblst )		/* (c) 1991 Irem (Japan) */
	DRIVER( uccops )		/* (c) 1992 Irem (World) */
	DRIVER( uccopsu )		/* (c) 1992 Irem (US) */
	DRIVER( uccopsar )		/* (c) 1992 Irem (World) */
	DRIVER( uccopsj )		/* (c) 1992 Irem (Japan) */
	DRIVER( mysticri )		/* (c) 1992 Irem (World) */
	DRIVER( mysticrib )		/* bootleg? */
	DRIVER( gunhohki )		/* (c) 1992 Irem (Japan) */
	DRIVER( majtitl2 )		/* (c) 1992 Irem (World, set 1) */
	DRIVER( majtitl2j )		/* (c) 1992 Irem (Japan) */
	DRIVER( majtitl2a )		/* (c) 1992 Irem (World, set 1, alt sound CPU) */
	DRIVER( majtitl2b )		/* (c) 1992 Irem (World, set 2) */
	DRIVER( skingame )		/* (c) 1992 Irem America (US) */
	DRIVER( skingame2 )		/* (c) 1992 Irem America (US) */
	DRIVER( hook )			/* (c) 1992 Irem (World) */
	DRIVER( hooku )			/* (c) 1992 Irem America (US) */
	DRIVER( hookj )			/* (c) 1992 Irem (Japan) */
	DRIVER( ppan )			/* bootleg */
	DRIVER( rtypeleo )		/* (c) 1992 Irem (World) */
	DRIVER( rtypeleoj )		/* (c) 1992 Irem (Japan) */
	DRIVER( inthunt )		/* (c) 1993 Irem (World) */
	DRIVER( inthuntu )		/* (c) 1993 Irem (US) */
	DRIVER( kaiteids )		/* (c) 1993 Irem (Japan) */
	DRIVER( nbbatman )		/* (c) 1993 Irem (World) */
	DRIVER( nbbatmanu )		/* (c) 1992 Irem Americ (US) */
	DRIVER( leaguemn )		/* (c) 1993 Irem (Japan) */
	DRIVER( ssoldier )		/* (c) 1993 Irem America (US) */
	DRIVER( psoldier )		/* (c) 1993 Irem (Japan) */
	DRIVER( gunforc2 )		/* (c) 1994 Irem */
	DRIVER( geostorm )		/* (c) 1994 Irem (Japan) */
	DRIVER( dsoccr94j )		/* Dream Soccer'94 (Japan, M92 Hardware) */


	/* ************************** */
	/*  Part 2 - Capcom System 1  */
	/* ************************** */
	DRIVER( 1941 )			/* 27/02/1990 (c) 1990 (World) */
	DRIVER( 1941j )			/* 02/1990 (c) 1990 (Japan) */
	DRIVER( 1941u )			/* 27/02/1990 (c) 1990 (USA) */
	DRIVER(	1941r1 )		/* 02/1990 (c) 1990 (World) */
	DRIVER( 3wonders )		/* 20/05/1991 (c) 1991 (World) */
	DRIVER( 3wondersb )		/* bootleg set 2 */
	DRIVER( 3wondersh )		/* bootleg set 1 */
	DRIVER( 3wondersr1 )		/* 13/05/1991 (c) Three Wonders (World) */
	DRIVER( 3wondersu )		/* 20/05/1991 (c) 1991 (US)    */
	DRIVER( wonder3 )		/* 20/05/1991 (c) 1991 (Japan) */
	DRIVER( captcomm )		/* 02/12/1991 (c) 1991 (World) */
	DRIVER( captcommb )		/* bootleg */
	DRIVER( captcommb2 )		/* Captain Commando (bootleg with YM2151 + 2xMSM5205) */
	DRIVER( captcommj )		/* 02/12/1991 (c) 1991 (Japan) */
	DRIVER( captcommjr1 )		/* 28/09/1991 (c) 1991 (Japan) */
	DRIVER( captcommr1 )		/* 14/10/1991 (c) 1991 (World) */
	DRIVER( captcommu )		/* 28/09/1991 (c) 1991 (US)    */
	DRIVER( cawing )		/* 12/10/1990 (c) 1990 (World) */
	DRIVER( cawingr1 )		/* 09/10/1990 (c) 1990 (World) */
	DRIVER( cawingu )		/* 12/10/1990 (c) 1990 (US) */
	DRIVER( cawingj )		/* 12/10/1990 (c) 1990 (Japan) */
	DRIVER( cawingbl )		/* bootleg of cawing, with YM2203 x2 + MSM205 x2, set 1 */
	DRIVER( cawingb2 )		/* bootleg of cawing, with YM2203 x2 + MSM205 x2, set 2 */
	DRIVER( cworld2j )		/* 11/06/1992 (QUIZ 5) (c) 1992 (Japan) */
	DRIVER( cworld2ja )		/* 11/06/1992 (c) Adventure Quiz Capcom World 2 (Japan, B-Board 90629B-3, no battery) */
	DRIVER( cworld2jb )		/* 11/06/1992 (c) Adventure Quiz Capcom World 2 (Japan, B-Board 90629B-2) */
	DRIVER( dino )			/* 01/02/1993 (c) 1993 (World) (CPS1 + QSound) */
	DRIVER( dinou )			/* 01/02/1993 (c) 1993 (US) (CPS1 + QSound) */
	DRIVER( dinoj )			/* 01/02/1993 (c) 1993 (Japan) (CPS1 + QSound) */
	DRIVER( dinohunt )		/* bootleg */
	DRIVER( dinohc )		/* hack */
	DRIVER( dinoeh )		/* hack */
	DRIVER( dinoh )			/* hack */
	DRIVER( dinot )			/* bootleg set 1, 930223 Asia TW */
	DRIVER( dinotpic )		/* bootleg set 2 with PIC16c57, 930223 Asia TW */
	DRIVER( dinopic )		/* bootleg set 1 with PIC16c57 */
	DRIVER( dinopic2 )		/* bootleg set 2 with PIC16c57 */
	DRIVER( dinopic3 )		/* bootleg set 3 with PIC16c57 */
	DRIVER( dinopic4 )		/* bootleg set 4 with PIC16c57 */
	DRIVER( dynwar )		/* 04/1989 (c) 1989 (USA set 1) */
	DRIVER( dynwara )		/* 04/1989 (c) 1989 (USA set 2) */
	DRIVER( dynwarj )		/* 04/1989 (c) 1989 (Japan) */
	DRIVER( dynwarjr )		/* Tenchi wo Kurau (Japan Resale Ver.) */
	DRIVER( ffight )		/* 12/1989 (c) (World) */
	DRIVER( fcrash )		/* bootleg of Final Fight */
	DRIVER( ffighta )		/* Final Fight (World, set 2) */
	DRIVER( ffightbl )		/* Final Fight (bootleg) */
	DRIVER( ffightbla )		/* Final Fight (bootleg on Final Crash PCB) */
	DRIVER( ffightj )		/* 12/1989 (c) (Japan) */
	DRIVER( ffightj1 )		/* 12/1989 (c) (Japan) */
	DRIVER( ffightj2 )		/* 12/1989 (c) (Japan) */
	DRIVER( ffightj3 )		/* 13/06/1990 (c) Final Fight (Japan) */
	DRIVER( ffightjh )		/* 12/1989 (c) (Japan) */
	DRIVER( ffightu )		/* 12/1989 (c) (US)    */
	DRIVER( ffightu1 )		/* Final Fight (USA, set 2) */
	DRIVER( ffightu2 )		/* Final Fight (USA, set 3) */
	DRIVER( ffightua )		/* 12/1989 (c) (US)    */
	DRIVER( ffightub )		/* 12/1989 (c) (US)    */
	DRIVER( ffightuc )		/* 13/06/1990 (c) Final Fight (USA) */
	DRIVER( forgottn )		/* 07/1988 (c) 1988 (World, newer) */
	DRIVER( forgottna )		/* 07/1988 (c) 1988 (World) */
	DRIVER( forgottnu )		/* 07/1988 (c) 1988 (US, B-Board 88621B-2, rev C) */
	DRIVER( forgottnu1 )		/* 07/1988 (c) 1988 (US, B-Board 88621B-2, Rev C) */
	DRIVER( forgottnua )		/* 07/1988 (c) 1988 (US, B-Board 88621B-2, rev A) */
	DRIVER( forgottnuaa )		/* 07/1988 (c) 1988 (US, B-Board 88621B-2, rev AA) */
	DRIVER( lostwrld )		/* 07/1988 (c) 1988 (Japan) */
	DRIVER( lostwrldo )		/* 07/1988 (c) 1988 (Japan old ver.) */
	DRIVER( ganbare )		/* 11/04/2000 (c) Ganbare Marin-kun (Marine 2K0411, JPN) */
	DRIVER( ghouls )		/* 12/1988 (c) 1988 (World) */
	DRIVER( ghoulsu )		/* 12/1988 (c) 1988 (US) */
	DRIVER( daimakai )		/* 12/1988 (c) 1988 (Japan) */
	DRIVER( daimakair )		/* 12/1988 (c) 1988 (Japan) */
	DRIVER( daimakaib )		/* bootleg */
	DRIVER( knights )		/* 27/11/1991 (c) 1991 (World) */
	DRIVER( knightsb )		/* bootleg set 1 */
	DRIVER( knightsb2 )		/* Knights of the Round (bootleg set 2, World 911127) */
	DRIVER( knightsb3 )		/* Knights of the Round (bootleg set 3, Japan 911127) */
	DRIVER( knightsb4 )		/* bootleg set 4 */
	DRIVER( knightsh )		/* Knights of the Round (hack set 1) */
	DRIVER( knightsh2 )		/* Knights of the Round (hack set 2, 911127 etc) */
	DRIVER( knightsj )		/* 27/11/1991 (c) 1991 (Japan) */
	DRIVER( knightsja)		/* 27/11/1991 (c) Knights of the Round (Japan, B-Board 89625B-1) */
	DRIVER( knightsu )		/* 27/11/1991 (c) 1991 (US)    */
	DRIVER( kod )			/* 11/07/1991 (c) 1991 (World) */
	DRIVER( kodb )			/* bootleg */
	DRIVER( kodda )			/* bootleg */
	DRIVER( kodh )			/* hack */
	DRIVER( kodj )			/* 05/08/1991 (c) 1991 (Japan) */
	DRIVER( kodja )
	DRIVER( kodr1 )
	DRIVER( kodu )			/* 10/09/1991 (c) 1991 (US)    */
	DRIVER( mbombrd )		/* 06/12/1993 (c) 1993 (World) (CPS1 + QSound) */
	DRIVER( mbombrdj )		/* 06/12/1993 (c) 1993 (Japan) (CPS1 + QSound) */
	DRIVER( megaman )		/* 06/10/1995 (c) 1995 (Asia)  */
	DRIVER( megamana )
	DRIVER( rockmanj )		/* 22/09/1995 (c) 1995 (Japan) */
	DRIVER( mercs )			/* 02/03/1990 (c) 1990 (World) */
	DRIVER( mercsj )		/* 02/03/1990 (c) 1990 (Japan) */
	DRIVER( mercsu )		/* 02/03/1990 (c) 1990 (US)    */
	DRIVER( mercsur1 )		/* 02/03/1990 (c) 1990 (US)    */
	DRIVER( msword )		/* 25/07/1990 (c) 1990 (World) */
	DRIVER( mswordr1 )		/* 23/06/1990 (c) 1990 (World) */
	DRIVER( mswordu )		/* 25/07/1990 (c) 1990 (US)    */
	DRIVER( mswordj )		/* 23/06/1990 (c) 1990 (Japan) */
	DRIVER( mtwins )		/* 19/06/1990 (c) 1990 (World) */
	DRIVER( chikij )		/* 19/06/1990 (c) 1990 (Japan) */
	DRIVER( nemo )			/* 30/11/1990 (c) 1990 (World) */
	DRIVER( nemoj )			/* 20/11/1990 (c) 1990 (Japan) */
	DRIVER( nemor1 )		/* 09/11/1990 (c) Nemo (World) */
	DRIVER( pang3 )			/* 01/06/1995 (c) 1995 Mitchell (Euro) not listed on Capcom's site */
	DRIVER( pang3b )		/* bootleg set 1, based on Euro 950511 */
	DRIVER( pang3b2 )		/* bootleg set 2, based on Euro 950511 */
	DRIVER( pang3b3 )		/* bootleg set 3, based on Euro 950601 */
	DRIVER( pang3j )		/* 11/05/1995 (c) 1995 Mitchell (Japan) not listed on Capcom's site */
	DRIVER( pang3r1 )		/* 11/05/1995 (c) 1995 Mitchell (Euro) */
	DRIVER( pang3r1a )		/* 11/05/1995 (c) 1995 Mitchell (Euro, alt) */
	DRIVER( pnickj )		/* 08/06/1994 (c) 1994 Compile + Capcom license (Japan) not listed on Capcom's site */
	DRIVER( qtono2j )		/* 23/01/1995 (c) 1995 (Japan) */
	DRIVER( qad )			/* 01/07/1992 (c) 1992 (US)    */
	DRIVER( qadjr )			/* 21/09/1994 - Quiz & Dragons (Japan Resale Ver.) */
	DRIVER( punisher )		/* 22/04/1993 (c) 1993 (World) (CPS1 + QSound) */
	DRIVER( punisherb )		/* bootleg */
	DRIVER( punipic )		/* bootleg set 1 */
	DRIVER( punipic2 )		/* bootleg set 2 */
	DRIVER( punipic3 )		/* bootleg set 3 */
	DRIVER( punisherbz )		/* chinese bootleg */
	DRIVER( punisherh )		/* 22/04/1993 (c) The Punisher (Hispanic) */
	DRIVER( punisherj )		/* 22/04/1993 (c) 1993 (Japan) (CPS1 + QSound) */
	DRIVER( punisheru )		/* 22/04/1993 (c) 1993 (US)    (CPS1 + QSound) */
	DRIVER( sfzch )			/* 20/10/1995 (c) CPS Changer version - Street Fighter Zero(Japan) */
	DRIVER( wofch )			/* 31/10/1992 (c) CPS Changer version - Tenchi Wo Kurau II */
	DRIVER( wofchdx )		/* hackrom, bootleg, CPS Changer version -Sangokushi III Gaiden: Kakou-On's Revenge DX, based by wofch */
	DRIVER( slammast )		/* 13/07/1993 (c) 1993 (World) (CPS1 + QSound) */
	DRIVER( slammastu )		/* 13/07/1993 (c) 1993 (US)    (CPS1 + QSound) */
	DRIVER( mbomberj )		/* 13/07/1993 (c) 1993 (Japan) (CPS1 + QSound) */
	DRIVER( slampic )		/* bootleg with PIC16c57 */
	DRIVER( strider )		/* 03/1989 (c) 1989 (not explicitly stated but should be US) */
	DRIVER( striderua )		/* 03/1989 (c) 1989 (not explicitly stated but should be US) */
	DRIVER( striderj )		/* 03/1989 (c) 1989 */
	DRIVER( striderjr )		/* 03/1989 (c) 1989 */
	DRIVER( strideruc )		/* Strider (bootleg, buggy Street Fighter II conversion) */
	DRIVER( unsquad )		/* 08/1989 (c) 1989 */
	DRIVER( area88 )		/* 08/1989 (c) 1989 */
	DRIVER( area88r )		/* Area 88 (Japan Resale Ver.) */
	DRIVER( varth )			/* 14/07/1992 (c) 1992 (World) */
	DRIVER( varthb )		/* Varth: Operation Thunderstorm (bootleg) */
	DRIVER( varthj )		/* 14/07/1992 (c) 1992 (Japan) */
	DRIVER( varthjr )		/* 14/07/1992 (c) Varth: Operation Thunderstorm (Japan Resale Version) */
	DRIVER( varthr1 )		/* 12/06/1992 (c) 1992 (World) */
	DRIVER( varthu )		/* 12/06/1992 (c) 1992 (US) */
	DRIVER( willow )		/* 06/1989 (c) 1989 (Euro) */
	DRIVER( willowj )		/* 06/1989 (c) 1989 (Japan) */
	DRIVER( willowu )		/* 06/1989 (c) 1989 (USA) */
	DRIVER( willowuo )		/* 06/1989 (c) 1989 (USA old version) */
	DRIVER( wof )			/* 02/10/1992 (c) 1992 (World) (CPS1 + QSound) */
	DRIVER( wofr1 )
	DRIVER( wofa )			/* 05/10/1992 (c) 1992 (Asia)  (CPS1 + QSound) */
	DRIVER( wofu )			/* 31/10/1992 (c) 1992 (US) (CPS1 + QSound) */
	DRIVER( wofj )			/* 31/10/1992 (c) 1992 (Japan) (CPS1 + QSound) */
	DRIVER( wofhfh )		/* hackrom, Huo Feng Huang, Chinese bootleg */
	DRIVER( sgyxz )			/* bootleg of wof */
	DRIVER( wofh )
	DRIVER( wofha )
	DRIVER( wofah )
	DRIVER( wofaha )
	DRIVER( wofahb )
	DRIVER( wofjh )
	DRIVER( wofb )
	DRIVER( wofsjb )
	DRIVER( wof3js )
	DRIVER( wof3jsa )
	DRIVER( wofsj )
	DRIVER( wofsja )
	DRIVER( wof3sj )
	DRIVER( wof3sja )
	DRIVER( sf2hf )			/* 09/12/1992 (c) 1992 (World) */
	DRIVER( sf2hfj )		/* 09/12/1992 (c) 1992 (Japan) */
	DRIVER( sf2hfjb )		/* 09/12/1992 (c) 1992 (Japan) */
	DRIVER( sf2hfjb2 )		/* 09/12/1992 (c) 1992 (Japan) */
	DRIVER( sf2hfu )		/* 09/12/1992 (c) 1992 (US)    */
	DRIVER( sf2 )			/* 22/05/1991 (c) 1991 (World) */
	DRIVER( sf2b )
	DRIVER( sf2b2 )
	DRIVER( sf2b3 )
	DRIVER( sf2eb )			/* 14/02/1991 (c) 1991 (World) */
	DRIVER( sf2ebbl )		/* 14/02/1991 (c) 1991 (World, bootleg) */
	DRIVER( sf2ebbl2 )
	DRIVER( sf2ebbl3 )
	DRIVER( sf2ed )
	DRIVER( sf2ee )
	DRIVER( sf2j )			/* 10/12/1991 (c) 1991 (Japan) */
	DRIVER( sf2ja )			/* 14/02/1991 (c) 1991 (Japan) */
	DRIVER( sf2jc )			/* 06/03/1991 (c) 1991 (Japan) */
	DRIVER( sf2jf )
	DRIVER( sf2jh )
	DRIVER( sf2jl )
	DRIVER( sf2qp1 )		/* hack */
	DRIVER( sf2stt )
	DRIVER( sf2thndr )		/* hack */
	DRIVER( sf2ua )			/* 06/02/1991 (c) 1991 (US)    */
	DRIVER( sf2ub )			/* 14/02/1991 (c) 1991 (US)    */
	DRIVER( sf2uc )
	DRIVER( sf2ud )			/* 18/03/1991 (c) 1991 (US)    */
	DRIVER( sf2ue )			/* 28/02/1991 (c) 1991 (US)    */
	DRIVER( sf2uf )			/* 11/04/1991 (c) 1991 (US)    */
	DRIVER( sf2ug )
	DRIVER( sf2ui )			/* 22/05/1991 (c) 1991 (US)    */
	DRIVER( sf2uk )			/* 01/11/1991 (c) 1991 (US)    */
	DRIVER( sf2ce )			/* 13/03/1992 (c) 1992 (World) */
	DRIVER( sf2ceea )
	DRIVER( sf2ceua )		/* 13/03/1992 (c) 1992 (US)    */
	DRIVER( sf2ceub )		/* 13/05/1992 (c) 1992 (US)    */
	DRIVER( sf2ceuc )		/* 03/08/1992 (c) 1992 (US)    */
	DRIVER( sf2ceja )
	DRIVER( sf2cejb )
	DRIVER( sf2cejc )
	DRIVER( sf2bhh )
	DRIVER( sf2rb )			/* hack */
	DRIVER( sf2rb2 )		/* hack */
	DRIVER( sf2rb3 )		/* hack */
	DRIVER( sf2rb4 )
	DRIVER( sf2rb5 )
	DRIVER( sf2rb6 )
	DRIVER( sf2acc )		/* hack */
	DRIVER( sf2acca )
	DRIVER( sf2accp2 )		/* hack */
	DRIVER( sf2cebltw )
	DRIVER( sf2dkot2 )		/* hack */
	DRIVER( sf2koryu )		/* hack */
	DRIVER( sf2koryu2 )
	DRIVER( sf2koryu3 )
	DRIVER( sf2dongb )
	DRIVER( sf2v004 )		/* hack */
	DRIVER( sf2v0042 )
	DRIVER( sf2v0043 )
	DRIVER( sf2yyc )		/* hack */
	DRIVER( sf2yyc2 )
	DRIVER( sf2amf )		/* hackrom, SF2 Alpha Magic-F */
	DRIVER( sf2amf2 )
	DRIVER( sf2amf3 )
	DRIVER( sf2amf4 )
	DRIVER( sf2amf5 )
	DRIVER( sf2amf6 )
	DRIVER( sf2amf7 )
	DRIVER( sf2amf8 )
	DRIVER( sf2cejabl )
	DRIVER( sf2cejab2 )
	DRIVER( sf2red )		/* hack */
	DRIVER( sf2red2 )
	DRIVER( sf2mega )
	DRIVER( sf2mega2 )
	DRIVER( sf2sl73a )
	DRIVER( sf2tlona )
	DRIVER( sf2tlonb )
	DRIVER( sf2tlonc )
	DRIVER( sf2ceucbl )
	DRIVER( sf2ceeabl )
	DRIVER( sf2ceeab2 )
	DRIVER( sf2md )
	DRIVER( sf2mdt )		/* bootleg of SF2CE, set 1 */
	DRIVER( sf2mdta )		/* bootleg of SF2CE, set 2 */
	DRIVER( sf2mdtb )
	DRIVER( sf2ceuabl )
	DRIVER( sf2ceuab2 )
	DRIVER( sf2ceuab3 )
	DRIVER( sf2ceuab4 )
	DRIVER( sf2ceuab5 )
	DRIVER( sf2ceuab6 )
	DRIVER( sf2ceuab7 )
	DRIVER( cps1frog )		// Homebrew

	/* ************************** */
	/*  Part 3 - Capcom System 2  */
	/* ************************** */
	DRIVER( 1944 )			/* 20/06/2000 (c) 2000 Eighting/Raizing (US) */
	DRIVER( 1944j )			/* 20/06/2000 (c) 2000 Eighting/Raizing (Japan) */
	DRIVER( 1944d )			/* 20/06/2000 - 1944 - the loop master (USA Phoenix Edition)*/
	DRIVER( 1944ad )		/* 20/06/2000 - 1944 - the loop master (USA Phoenix Edition, alt) */
	DRIVER( 19xx )			/* 07/12/1995 (c) 1996 (US) */
	DRIVER( 19xxj )			/* 25/12/1995 (c) 1996 (Japan) */
	DRIVER( 19xxjr1 )		/* 25/12/1995 (c) 1996 (Japan) */
	DRIVER( 19xxa )			/* 04/01/1996 (c) 1996 (Asia) */
	DRIVER( 19xxh )			/* 18/12/1995 (c) 1996 (Hispanic) */
	DRIVER( 19xxb )			/* 18/12/1995 (c) 1996 (Brazil) */
	DRIVER( 19xxar1 )		/* 07/12/1995 (c) 1996 (Asia) */
	DRIVER( 19xxjr2 )		/* 07/12/1995 (c) 1996 (Japan) */
	DRIVER( 19xxd )			/* 07/12/1995 - 19XX - the war against destiny (USA Phoenix Edition) */
	DRIVER( armwar )		/* 24/10/1994 (c) 1994 (Euro) */
	DRIVER( armwarr1 )		/* 11/10/1994 (c) 1994 (Euro) */
	DRIVER( armwaru )		/* 24/10/1994 (c) 1994 (US) */
	DRIVER( armwaru1 )		/* 20/09/1994 (c) 1994 (US) */
	DRIVER( armwara )		/* 24/10/1994 (c) 1994 (Asia) */
	DRIVER( armwarar1 )		/* 20/09/1994 (c) 1994 (Asia) */
	DRIVER( armwar1d )		/* 11/10/1994 - Armored Warriors (Europe Phoenix Edition) */
	DRIVER( pgear )			/* 24/10/1994 (c) 1994 (Japan) */
	DRIVER( pgearr1 )		/* 16/09/1994 (c) 1994 (Japan) */
	DRIVER( avsp )			/* 20/05/1994 (c) 1994 (Euro) */
	DRIVER( avspu )			/* 20/05/1994 (c) 1994 (US) */
	DRIVER( avspj )			/* 20/05/1994 (c) 1994 (Japan) */
	DRIVER( avspa )			/* 20/05/1994 (c) 1994 (Asia) */
	DRIVER( avsph )			/* 20/05/1994 (c) 1994 (Hispanic) */
	DRIVER( avspd )			/* 20/05/1994 - Alien vs Predator (Euro Phoenix Edition) */
	DRIVER( batcir )		/* 19/03/1997 (c) 1997 (Euro) */
	DRIVER( batcirj )		/* 19/03/1997 (c) 1997 (Japan) */
	DRIVER( batcira )		/* 19/03/1997 (c) 1997 (Asia) */
	DRIVER( batcird )		/* 19/03/1997 - Battle Circuit (Euro Phoenix Edition) */
	DRIVER( choko )			/* 20/08/2001 (c) 2001 Mitchell (Japan) */
	DRIVER( csclub )		/* 17/10/1997 (c) 1997 (Euro) */
	DRIVER( csclub1 )		/* 22/07/1997 (c) 1997 (Euro) */
	DRIVER( csclubj )		/* 22/07/1997 (c) 1997 (Japan) */
	DRIVER( cscluba )		/* 22/07/1997 (c) 1997 (Asia) */
	DRIVER( csclubh )		/* 22/07/1997 (c) 1997 (Hispanic) */
	DRIVER( csclubjy )		/* 22/07/1997 (c) Capcom Sports Club, Japan, Yellow case */
	DRIVER( csclub1d )		/* Phoenix Edition, Capcom Sports Club, Euro */
	DRIVER( cybots )		/* 24/04/1995 (c) 1995 (Euro) */
	DRIVER( cybotsu )		/* 24/04/1995 (c) 1995 (US) */
	DRIVER( cybotsj )		/* 20/04/1995 (c) 1995 (Japan) */
	DRIVER( cybotsjd )		/* Decrypted bootleg, Cyberbots: Fullmetal Madness, Japan */
	DRIVER( cybotsud )		/* Phoenix Edition, Cyberbots: Fullmetal Madness, USA */
	DRIVER( ddsom )			/* 19/06/1996 (c) 1996 (Euro) */
	DRIVER( ddsomr1 )		/* 23/02/1996 (c) 1996 (Euro) */
	DRIVER( ddsomr2 )		/* 09/02/1996 (c) 1996 (Euro) */
	DRIVER( ddsomr3 )		/* 08/02/1996 (c) 1996 (Euro) */
	DRIVER( ddsomu )		/* 19/06/1996 (c) 1996 (US) */
	DRIVER( ddsomur1 )		/* 09/02/1996 (c) 1996 (US) */
	DRIVER( ddsomjr1 )		/* 06/02/1996 (c) 1996 (Japan) */
	DRIVER( ddsomj )		/* 19/06/1996 (c) 1996 (Japan) */
	DRIVER( ddsoma )		/* 19/06/1996 (c) 1996 (Asia) */
	DRIVER( ddsomh )		/* 23/02/1996 (c) 1996 (Hispanic) */
	DRIVER( ddsomb )		/* 23/02/1996 (c) 1996 (Brazil) */
	DRIVER( ddsomar1 )		/* 08/02/1996 (c) Dungeons & Dragons: Shadow over Mystara, Asia */
	DRIVER( ddsomud )		/* 19/06/1996 - Dungeons & Dragons - shadow over mystara (USA Phoenix Edition) */
	DRIVER( ddtod )			/* 12/04/1994 (c) 1993 (Euro) */
	DRIVER( ddtodr1 )		/* 13/01/1994 (c) 1993 (Euro) */
	DRIVER( ddtodu )		/* 25/01/1994 (c) 1993 (US) */
	DRIVER( ddtodur1 )		/* 13/01/1994 (c) 1993 (US) */
	DRIVER( ddtodj )		/* 12/04/1994 (c) 1993 (Japan) */
	DRIVER( ddtodjr1 )		/* 25/01/1994 (c) 1993 (Japan) */
	DRIVER( ddtodjr2 )		/* 13/01/1994 (c) 1993 (Japan) */
	DRIVER( ddtoda )		/* 12/04/1994 (c) 1993 (Asia) */
	DRIVER( ddtodh )		/* 12/04/1994 (c) 1993 (Hispanic) */
	DRIVER( ddtodhr1 )		/* 25/01/1994 (c) 1993 (Hispanic) */
	DRIVER( ddtodhr2 )		/* 13/01/1994 (c) 1993 (Hispanic) */
	DRIVER( ddtodar1 )		/* 13/01/1994 (c) 1993 (Asia) */
	DRIVER( ddtodd )		/* 12/04/1994 - Dungeons & Dragons - tower of doom (Euro Phoenix Edition) */
	DRIVER( dimahoo )		/* 21/01/2000 (c) 2000 Eighting/Raizing (US) */
	DRIVER( dimahoou )		/* 21/01/2000 (c) 2000 Eighting/Raizing (US) */
	DRIVER( dimahoud )		/* 21/01/2000 - Dimahoo (USA Phoenix Edition) */
	DRIVER( gmahou )		/* 21/01/2000 (c) 2000 Eighting/Raizing (Japan) */
	DRIVER( dstlk )			/* 05/07/1994 (c) 1994 (Euro) */
	DRIVER( dstlku )		/* 18/08/1994 (c) 1994 (US) */
	DRIVER( dstlkur1 )		/* 05/07/1994 (c) 1994 (US) */
	DRIVER( dstlka )		/* 05/07/1994 (c) 1994 (Asia) */
	DRIVER( dstlkh )		/* 18/08/1994 (c) 1994 (Hispanic) */
	DRIVER( dstlku1d )		/* 05/07/1994 - Darkstalkers - the night warriors (USA Phoenix Edition) */
	DRIVER( vampj )			/* 05/07/1994 (c) 1994 (Japan) */
	DRIVER( vampja )		/* 05/07/1994 (c) 1994 (Japan) */
	DRIVER( vampjr1 )		/* 30/06/1994 (c) 1994 (Japan) */
	DRIVER( ecofghtr )		/* 03/12/1993 (c) 1993 (World) */
	DRIVER( ecofghtru )		/* 15/02/1994 (c) 1993 (US) */
	DRIVER( ecofghtru1 )		/* 03/12/1993 (c) 1993 (US) */
	DRIVER( ecofghtra )		/* 03/12/1993 (c) 1993 (Asia) */
	DRIVER( ecofghtrh )		/* 03/12/1993 (c) 1993 (Hispanic) */
	DRIVER( uecology )		/* 03/12/1993 (c) 1993 (Japan) */
	DRIVER( ecofghtrd )		/* Phoenix Edition, Eco fighters, World */
	DRIVER( gigawing )		/* 22/02/1999 (c) 1999 Takumi (US) */
	DRIVER( gigawingj )		/* 23/02/1999 (c) 1999 Takumi (Japan) */
	DRIVER( gigawinga )		/* 22/02/1999 (c) 1999 Takumi (Asia) */
	DRIVER( gigawingh )		/* 22/02/1999 (c) 1999 Takumi (Hispanic) */
	DRIVER( gigawingb )		/* 22/02/1999 (c) 1999 Takumi (Brazil) */
	DRIVER( gigawingjd )		/* 23/02/1999 - Giga Wing (Japan Phoenix Edition) */
	DRIVER( gigawingd )		/* Phoenix Edition, Giga Wing, USA */
	DRIVER( hsf2 )			/* 02/02/2004 (c) 2004 Hyper Street Fighter 2 (USA) */
	DRIVER( hsf2j )			/* 22/12/2003 (c) 2003 Hyper Street Fighter 2 (Japan) */
	DRIVER( hsf2a )			/* 02/02/2004 (c) 2004 Hyper Street Fighter 2 (Asia) */
	DRIVER( hsf2d )			/* 02/02/2004 - Hyper Street Fighter II: The Anniversary Edition (Asia Phoenix Edition) */
	DRIVER( hsf2da )		/* Phoenix Edition, Hyper Street Fighter 2 (Asia 040202 alt) */
	DRIVER( jyangoku )		/* 27/05/1999 (c) 1999 (Japan) */
	/*	megaman: Mega Man - the power battle (the parent rom is based CPS1 hardware) */
	DRIVER( mmancp2ur1 )		/* 26/09/1995 (c) Mega Man: The Power Battle, USA, SAMPLE Version */
	DRIVER( mmancp2u )		/* 06/10/1995 (c) 1995 (Japan) */
	DRIVER( rmancp2j )		/* 22/09/1995 (c) 1995 (Japan) */
	DRIVER( megaman2 )		/* 08/07/1996 (c) 1996 (US) */
	DRIVER( megaman2a )		/* 08/07/1996 (c) 1996 (Asia) */
	DRIVER( rockman2j )		/* 08/07/1996 (c) 1996 (Japan) */
	DRIVER( megaman2h )		/* 12/07/1996 (c) 1996 (Hispanic) */
	DRIVER( gigaman2 )		/* bootleg */
	DRIVER( megamn2d )		/* 08/07/1996 - Mega Man 2 - the power fighters (USA Phoenix Edition) */
	DRIVER( mmatrix )		/* 12/04/2000 (c) 2000 Takumi (US) */
	DRIVER( mmatrixj )		/* 12/04/2000 (c) 2000 Takumi (Japan) */
	DRIVER( mmatrixd )		/* 12/04/2000 - Mars Matrix (USA Phoenix Edition) */
	DRIVER( mpang )			/* 10/10/2000 (c) 2000 Mitchell (Euro) */
	DRIVER( mpangr1 )		/* 25/09/2000 (c) 2000 Mitchell (Euro) */
	DRIVER( mpangu )		/* 10/10/2000 (c) 2000 Mitchell (US) */
	DRIVER( mpangj )		/* 11/10/2000 (c) 2000 Mitchell (Japan) */
	DRIVER( mpangjd )		/* Phoenix Edition, Mighty! Pang, Japan */
	DRIVER( msh )			/* 24/10/1995 (c) 1995 (Euro) */
	DRIVER( mshu )			/* 24/10/1995 (c) 1995 (US) */
	DRIVER( mshj )			/* 17/11/1995 (c) 1995 (Japan) */
	DRIVER( mshjr1 )		/* 24/10/1995 (c) 1995 (Japan) */
	DRIVER( msha )			/* 24/10/1995 (c) 1995 (Asia) */
	DRIVER( mshh )			/* 17/11/1995 (c) 1996 (Hispanic) */
	DRIVER( mshb )			/* 17/11/1995 (c) 1996 (Brazil) */
	DRIVER( mshud )			/* 24/10/1995 - Marvel Super Heroes (USA Phoenix Edition) */
	DRIVER( mshvsf )		/* 25/06/1997 (c) 1997 (Euro) */
	DRIVER( mshvsfu )		/* 27/08/1997 (c) 1997 (US) */
	DRIVER( mshvsfu1 )		/* 25/06/1997 (c) 1997 (US) */
	DRIVER( mshvsfj )		/* 07/07/1997 (c) 1997 (Japan) */
	DRIVER( mshvsfj1 )		/* 02/07/1997 (c) 1997 (Japan) */
	DRIVER( mshvsfj2 )		/* 25/06/1997 (c) 1997 (Japan) */
	DRIVER( mshvsfh )		/* 25/06/1997 (c) 1997 (Hispanic) */
	DRIVER( mshvsfa )		/* 25/06/1997 (c) 1997 (Asia) */
	DRIVER( mshvsfa1 )		/* 20/06/1997 (c) 1997 (Asia) */
	DRIVER( mshvsfb )		/* 27/08/1997 (c) 1997 (Brazil) */
	DRIVER( mshvsfb1 )		/* 25/06/1997 (c) 1997 (Brazil) */
	DRIVER( mshvsfu1d )		/* Phoenix Edition, Marvel Super Heroes Vs. Street Fighter, USA */
	DRIVER( mvsc )			/* 23/01/1998 (c) 1998 (Euro) */
	DRIVER( mvscr1 )		/* 12/01/1998 (c) 1998 (Euro) */
	DRIVER( mvscu )			/* 23/01/1998 (c) 1998 (US) */
	DRIVER( mvscur1 )		/* 23/01/1998 (c) 1998 (US) */
	DRIVER( mvscj )			/* 23/01/1998 (c) 1998 (Japan) */
	DRIVER( mvscjr1 )		/* 12/01/1998 (c) 1998 (Japan) */
	DRIVER( mvsca )			/* 23/01/1998 (c) 1998 (Asia) */
	DRIVER( mvscar1 )		/* 12/01/1998 (c) 1998 (Asia) */
	DRIVER( mvsch )			/* 23/01/1998 (c) 1998 (Hispanic) */
	DRIVER( mvscb )			/* 23/01/1998 (c) 1998 (Brazil) */
	DRIVER( mvscjsing )		/* 23/01/1998 (c) Marvel Vs. Capcom: Clash of Super Heroes, Japan, Single PCB version */
	DRIVER( mvscud )		/* 23/01/1998 - Marvel vs Capcom - clash of super heroes (USA Phoenix Edition) */
	DRIVER( nwarr )			/* 16/03/1995 (c) 1995 (Euro) */
	DRIVER( nwarru )		/* 06/04/1995 (c) 1995 (US) */
	DRIVER( nwarrh )		/* 03/04/1995 (c) 1995 (Hispanic) */
	DRIVER( nwarrb )		/* 03/04/1995 (c) 1995 (Brazil) */
	DRIVER( nwarra )		/* 02/03/1995 (c) 1995 (Asia) */
	DRIVER( nwarrud )		/* 06/04/1995 - Night Warriors - darkstalkers' revenge (USA Phoenix Edition) */
	DRIVER( vhuntj )		/* 02/03/1995 (c) 1995 (Japan) */
	DRIVER( vhuntjr1 )		/* 07/03/1995 (c) 1995 (Japan) */
	DRIVER( vhuntjr2 )		/* 02/03/1995 (c) 1995 (Japan) */
	DRIVER( vhuntjr1s )		/* 07/03/1995 (c) Vampire Hunter: Darkstalkers's Revenge, Japan stop version */
	DRIVER( progear )		/* 17/01/2001 (c) 2001 Cave (US) */
	DRIVER( progearj )		/* 17/01/2001 (c) 2001 Cave (Japan) */
	DRIVER( progeara )		/* 17/01/2001 (c) 2001 Cave (Asia) */
	DRIVER( progearjd )		/* 17/01/2001 - Progear No Arashi (Japan Phoenix Edition) */
	DRIVER( progearjbl )		/* Phoenix Edition, Progear no Arashi, Japan */
	DRIVER( progearud )		/* Phoenix Edition, Progear, USA */
	DRIVER( halfway )		/* Halfway To Hell: Progear Red Label (2016-1-17 Red label ver) */
	DRIVER( pzloop2 )		/* 02/03/2001 (c) 2001 Mitchell (Euro) */
	DRIVER( pzloop2j )		/* 26/02/2001 (c) 2001 Mitchell (Japan) */
	DRIVER( pzloop2jr1 )		/* 05/02/2001 (c) 2001 Mitchell (Japan) */
	DRIVER( qndream )		/* 26/06/1996 (c) 1996 (Japan) */
	DRIVER( ringdest )		/* 02/09/1994 (c) 1994 (Euro) */
	DRIVER( ringdesta )		/* 31/08/1994 (c) Ring of Destruction: Slammasters II, Asia */
	DRIVER( ringdesth )		/* 02/09/1994 (c) Ring of Destruction: Slammasters II, Hispanic */
	DRIVER( ringdstd )		/* 02/09/1994 - Ring of Destruction - slammasters II (Euro Phoenix Edition) */
	DRIVER( smbomb )		/* 31/08/1994 (c) 1994 (Japan) */
	DRIVER( smbombr1 )		/* 08/08/1994 (c) 1994 (Japan) */
	DRIVER( sfz2al )		/* 26/08/1996 (c) 1996 (Asia) */
	DRIVER( sfz2alj )		/* 05/08/1996 (c) 1996 (Japan) */
	DRIVER( sfz2alh )		/* 13/08/1996 (c) 1996 (Hispanic) */
	DRIVER( sfz2alb )		/* 13/08/1996 (c) 1996 (Brazil) */
	DRIVER( sfz2ald )		/* 26/08/1996 - Street Fighter Zero 2 Alpha (Asia Phoenix Edition) */
	DRIVER( sfa2 )			/* 06/03/1996 (c) 1996 (Euro) */
	DRIVER( sfa2u )			/* 30/04/1996 (c) 1996 (US) */
	DRIVER( sfa2ur1 )		/* 06/03/1996 (c) 1996 (US) */
	DRIVER( sfz2j )			/* 30/04/1996 (c) 1996 (Japan) */
	DRIVER( sfz2a )			/* 27/02/1996 (c) 1996 (Asia) */
	DRIVER( sfz2b )			/* 31/05/1996 (c) 1996 (Brazil) */
	DRIVER( sfz2br1 )		/* 04/03/1996 (c) 1996 (Brazil) */
	DRIVER( sfz2h )			/* 04/03/1996 (c) 1996 (Hispanic) */
	DRIVER( sfz2n )			/* 29/02/1996 (c) 1996 (Oceania) */
	DRIVER( sfz2jr1 )		/* 27/02/1996 (c) 1996 (Japan) */
	DRIVER( sfz2ad )		/* 27/02/1996 - Street Fighter Zero 2 (Asia Phoenix Edition) */
	DRIVER( sfz2jd )		/* Phoenix Edition, Street Fighter Zero 2, Japan */
	DRIVER( sfa3 )			/* 04/09/1998 (c) 1998 (US) */
	DRIVER( sfa3u )			/* 04/09/1998 (c) 1998 (US) */
	DRIVER( sfa3ur1 )		/* 29/06/1998 (c) 1998 (US) */
	DRIVER( sfa3h )			/* 04/09/1998 (c) 1998 (Hispanic) */
	DRIVER( sfa3b )			/* 29/06/1998 (c) 1998 (Brazil) */
	DRIVER( sfz3j )			/* 04/09/1998 (c) 1998 (Japan) */
	DRIVER( sfz3jr1 )		/* 27/07/1998 (c) 1998 (Japan) */
	DRIVER( sfz3jr2 )		/* 29/06/1998 (c) 1998 (Japan) */
	DRIVER( sfz3a )			/* 04/09/1998 (c) 1998 (Asia) */
	DRIVER( sfz3ar1 )		/* 01/07/1998 (c) 1998 (Asia) */
	DRIVER( sfa3us )		/* 16/06/1998 (c) Street Fighter Alpha 3, USA, Sample Version */
	DRIVER( sfa3hr1 )		/* 29/06/1998 (c) 1998 (Hispanic) */
	DRIVER( sfa3ud )		/* 04/09/1998 - Street Fighter Alpha 3 (USA Phoenix Edition) */
	DRIVER( sfz3jr2d )		/* Phoenix Edition, Street Fighter Zero 3, Japan */
	DRIVER( sfa )			/* 27/07/1995 (c) 1995 (Euro) */
	DRIVER( sfar1 )			/* 18/07/1995 (c) 1995 (Euro) */
	DRIVER( sfar2 )			/* 27/06/1995 (c) 1995 (Euro) */
	DRIVER( sfar3 )			/* 05/06/1995 (c) 1995 (Euro) */
	DRIVER( sfau )			/* 27/06/1995 (c) 1995 (US) */
	DRIVER( sfza )			/* 27/06/1995 (c) 1995 (Asia) */
	DRIVER( sfzj )			/* 27/07/1995 (c) 1995 (Japan) */
	DRIVER( sfzjr1 )		/* 27/06/1995 (c) 1995 (Japan) */
	DRIVER( sfzjr2 )		/* 05/06/1995 (c) 1995 (Japan) */
	DRIVER( sfzh )			/* 18/07/1995 (c) 1995 (Hispanic) */
	DRIVER( sfzhr1 )		/* 27/06/1995 (c) 1995 (Hispanic) */
	DRIVER( sfzb )			/* 09/11/1995 (c) 1995 (Brazil) */
	DRIVER( sfzbr1 )		/* 27/07/1995 (c) 1995 (Brazil) */
	DRIVER( sfzar1 )		/* 05/06/1995 (c) 1995 (Asia) */
	DRIVER( sfad )			/* 27/07/1995 - Street Fighter Alpha - warriors' dreams (Euro Phoenix Edition) */
	DRIVER( sfaud )			/* Phoenix Edition, Street Fighter Alpha: Warrior's Dream, USA */
	DRIVER( sgemf )			/* 04/09/1997 (c) 1997 (US) */
	DRIVER( pfghtj )		/* 04/09/1997 (c) 1997 (Japan) */
	DRIVER( sgemfa )		/* 04/09/1997 (c) 1997 (Asia) */
	DRIVER( sgemfh )		/* 04/09/1997 (c) 1997 (Hispanic) */
	DRIVER( sgemfd )		/* 04/09/1997 - Super Gem Fighter Mini Mix (USA Phoenix Edition) */
	DRIVER( spf2t )			/* 29/05/1996 (c) 1996 (Euro) */
	DRIVER( spf2xj )		/* 31/05/1996 (c) 1996 (Japan) */
	DRIVER( spf2ta )		/* 29/05/1996 (c) 1996 (Asia) */
	DRIVER( spf2th )		/* 31/05/1996 (c) 1996 (Hispanic) */
	DRIVER( spf2tu )		/* 20/06/1996 (c) 1996 (US) */
	DRIVER( spf2xjd )		/* 31/05/1996 - Super Puzzle Fighter 2 X (Japan Phoenix Edition) */
	DRIVER( spf2td )		/* Phoenix Edition, Super Puzzle Fighter II Turbo (USA 960620) */
	DRIVER( ssf2 )			/* 11/09/1993 (c) 1993 (World) */
	DRIVER( ssf2u )			/* 11/09/1993 (c) 1993 (US) */
	DRIVER( ssf2a )			/* 05/10/1993 (c) 1993 (Asia) */
	DRIVER( ssf2ar1 )		/* 14/09/1993 (c) 1993 (Asia) */
	DRIVER( ssf2j )			/* 05/10/1993 (c) 1993 (Japan) */
	DRIVER( ssf2jr1 )		/* 11/09/1993 (c) 1993 (Japan) */
	DRIVER( ssf2jr2 )		/* 10/09/1993 (c) 1993 (Japan) */
	DRIVER( ssf2h )			/* 11/09/1993 (c) 1993 (Hispanic) */
	DRIVER( ssf2r1 )		/* Super Street Fighter II - the new challengers (1993.09.11) */
	DRIVER( ssf2tb )		/* 11/19/1993 (c) 1993 (World) */
	DRIVER( ssf2tbr1 )		/* 11/09/1993 (c) 1993 (World) */
	DRIVER( ssf2tbj )		/* 11/09/1993 (c) 1993 (Japan) */
	DRIVER( ssf2tbh )		/* 05/10/1993 (c) Super Street Fighter II: The Tournament Battle, Hispanic */
	DRIVER( ssf2tbd )		/* 19/11/1993 - Super Street Fighter II - the tournament battle (ETC Phoenix Edition) */
	DRIVER( ssf2ud )		/* 11/09/1993 - Super Street Fighter II - the new challengers (USA Phoenix Edition) */
	DRIVER( ssf2d )			/* Phoenix Edition, Super Street Fighter II: the new challengers, Etc */
	DRIVER( ssf2t )			/* 23/02/1994 (c) 1994 (World) */
	DRIVER( ssf2tu )		/* 23/03/1994 (c) 1994 (US) */
	DRIVER( ssf2tur1 )		/* 23/02/1994 (c) 1994 (US) */
	DRIVER( ssf2ta )		/* 23/02/1994 (c) 1994 (Asia) */
	DRIVER( ssf2xj )		/* 23/02/1994 (c) 1994 (Japan) */
	DRIVER( ssf2th )		/* 23/02/1994 (c) Super Street Fighter II Turbo, Hispanic */
	DRIVER( ssf2xjr )		/* 23/02/1994 (c) 1994 (Japan rent version) */
	DRIVER( ssf2tad )		/* Phoenix Edition, Super Street Fighter II Turbo, Asia */
	DRIVER( ssf2td )		/* Phoenix Edition, Super Street Fighter II Turbo, Etc */
	DRIVER( ssf2xjd )		/* 23/02/1994 - Super Street Fighter II X - grand master challenge (Japan Phoenix Edition) */
	DRIVER( vhunt2 )		/* 29/09/1997 (c) 1997 (Japan) */
	DRIVER( vhunt2r1 )		/* 13/09/1997 (c) 1997 (Japan) */
	DRIVER( vhunt2d )		/* Phoenix Edition, Vampire Hunter 2: Darkstalkers Revenge, Japan */
	DRIVER( vsav )			/* 19/05/1997 (c) 1997 (Euro) */
	DRIVER( vsavu )			/* 19/05/1997 (c) 1997 (US) */
	DRIVER( vsavj )			/* 19/05/1997 (c) 1997 (Japan) */
	DRIVER( vsava )			/* 19/05/1997 (c) 1997 (Asia) */
	DRIVER( vsavh )			/* 19/05/1997 (c) 1997 (Hispanic) */
	DRIVER( vsavd )			/* 19/05/1997 - Vampire Savior - the lord of vampire (Euro Phoenix Edition) */
	DRIVER( vsav2 )			/* 13/09/1997 (c) 1997 (Japan) */
	DRIVER( vsav2d )		/* Phoenix Edition, Vampire Savior 2: The Lord of Vampire, Japan */
	DRIVER( xmcota )		/* 31/03/1995 (c) 1994 (Euro) */
	DRIVER( xmcotau )		/* 05/01/1995 (c) 1994 (US) */
	DRIVER( xmcotah )		/* 31/03/1995 (c) 1994 (Hispanic) */
	DRIVER( xmcotahr1 )		/* 05/01/1995 (c) 1994 (Hispanic) */
	DRIVER( xmcotaj )		/* 05/01/1995 (c) 1994 (Japan) */
	DRIVER( xmcotaj1 )		/* 22/12/1994 (c) 1994 (Japan) */
	DRIVER( xmcotaj2 )		/* 19/12/1994 (c) 1994 (Japan) */
	DRIVER( xmcotaj3 )		/* 17/12/1994 (c) 1994 (Japan) */
	DRIVER( xmcotaa )		/* 05/01/1995 (c) 1994 (Asia) */
	DRIVER( xmcotajr )		/* 08/12/1994 (c) 1994 (Japan Rent) */
	DRIVER( xmcotar1 )		/* 05/01/1995 (c) 1994 (Euro) */
	DRIVER( xmcotaar1 )		/* 17/12/1994 (c) 1994 (Asia) */
	DRIVER( xmcotar1d )		/* 05/01/1995 - X-Men - children of the atom (Euro Phoenix Edition) */
	DRIVER( xmvsf )			/* 04/10/1996 (c) 1996 (Euro) */
	DRIVER( xmvsfr1 )		/* 10/09/1996 (c) 1996 (Euro) */
	DRIVER( xmvsfu )		/* 23/10/1996 (c) 1996 (US) */
	DRIVER( xmvsfur1 )		/* 04/10/1996 (c) 1996 (US) */
	DRIVER( xmvsfj )		/* 04/10/1996 (c) 1996 (Japan) */
	DRIVER( xmvsfjr1 )		/* 10/09/1996 (c) 1996 (Japan) */
	DRIVER( xmvsfjr2 )		/* 09/09/1996 (c) 1996 (Japan) */
	DRIVER( xmvsfa )		/* 23/10/1996 (c) 1996 (Asia) */
	DRIVER( xmvsfar1 )		/* 04/10/1996 (c) 1996 (Asia) */
	DRIVER( xmvsfar2 )		/* 19/09/1996 (c) 1996 (Asia) */
	DRIVER( xmvsfh )		/* 04/10/1996 (c) 1996 (Hispanic) */
	DRIVER( xmvsfb )		/* 23/10/1996 (c) 1996 (Brazil) */
	DRIVER( xmvsfar3 )		/* 10/09/1996 (c) 1996 (Asia) */
	DRIVER( xmvsfur2 )		/* 10/09/1996 (c) 1996 (US) */
	DRIVER( xmvsfu1d )		/* 04/10/1996 - X-Men vs Street Fighter (USA Phoenix Edition) */


	/* ****************** */
	/*  Part 4 - Neo Geo  */
	/* ****************** */
	DRIVER( neogeo )		/* dummy entry for the dummy bios driver */
	//
	DRIVER( nam1975 )		/* 0001 (c) 1990 SNK */
	DRIVER( bstars )		/* 0002 (c) 1990 SNK */
	DRIVER( bstarsh )		/* 0002 (c) 1990 SNK */
	DRIVER( tpgolf )		/* 0003 (c) 1990 SNK */
	DRIVER( mahretsu )		/* 0004 (c) 1990 SNK */
	DRIVER( maglord )		/* 0005 (c) 1990 Alpha Denshi Co. */
	DRIVER( maglordh )		/* 0005 (c) 1990 Alpha Denshi Co. */
	DRIVER( ridhero )		/* 0006 (c) 1990 SNK */
	DRIVER( ridheroh )		/* 0006 (c) 1990 SNK */
	DRIVER( alpham2 )		/* 0007 (c) 1991 SNK */
					/* 0008 Sunshine (prototype) 1990 SNK */
	DRIVER( ncombat )		/* 0009 (c) 1990 Alpha Denshi Co. */
	DRIVER( ncombath )		/* 0009 (c) 1990 Alpha Denshi Co. */
	DRIVER( cyberlip )		/* 0010 (c) 1990 SNK */
	DRIVER( superspy )		/* 0011 (c) 1990 SNK */
					/* 0012 */
					/* 0013 */
	DRIVER( mutnat )		/* 0014 (c) 1992 SNK */
					/* 0015 */
	DRIVER( kotm )			/* 0016 (c) 1991 SNK */
	DRIVER( kotmh )			/* 0016 (c) 1991 SNK */
	DRIVER( sengoku )		/* 0017 (c) 1991 SNK */
	DRIVER( sengokuh )		/* Sengoku (US) (NGH-017) */
	DRIVER( burningf )		/* 0018 (c) 1991 SNK */
	DRIVER( burningfh )		/* 0018 (c) 1991 SNK */
	DRIVER( lbowling )		/* 0019 (c) 1990 SNK */
	DRIVER( gpilots )		/* 0020 (c) 1991 SNK */
	DRIVER( gpilotsh )		/* 0020 (c) 1991 SNK */
	DRIVER( joyjoy )		/* 0021 (c) 1990 SNK */
	DRIVER( bjourney )		/* 0022 (c) 1990 Alpha Denshi Co. */
	DRIVER( quizdais )		/* 0023 (c) 1991 SNK */
	DRIVER( quizdaisk )		/* 0123 (c) 1991 SNK */
	DRIVER( lresort )		/* 0024 (c) 1992 SNK */
	DRIVER( eightman )		/* 0025 (c) 1991 SNK / Pallas */
					/* 0026 Fun Fun Brothers (prototype) 1991 Alpha */
	DRIVER( minasan )		/* 0027 (c) 1990 Monolith Corp. */
					/* 0028 Dunk Star (prototype) Sammy */
	DRIVER( legendos )		/* 0029 (c) 1991 SNK */
	DRIVER( 2020bb )		/* 0030 (c) 1991 SNK / Pallas */
	DRIVER( 2020bba )		/* 0030 (c) 1991 SNK / Pallas */
	DRIVER( 2020bbh )		/* 0030 (c) 1991 SNK / Pallas */
	DRIVER( socbrawl )		/* 0031 (c) 1991 SNK */
	DRIVER( socbrawlh )		/* 0031 (c) 1991 SNK */
	DRIVER( roboarmy )		/* 0032 (c) 1991 SNK */
	DRIVER( fatfury1 )		/* 0033 (c) 1991 SNK */
	DRIVER( fbfrenzy )		/* 0034 (c) 1992 SNK */
					/* 0035 Mystic Wand (prototype) 1991 Alpha */
	DRIVER( bakatono )		/* 0036 (c) 1991 Monolith Corp. */
	DRIVER( crsword )		/* 0037 (c) 1991 Alpha Denshi Co. */
	DRIVER( trally )		/* 0038 (c) 1991 Alpha Denshi Co. */
	DRIVER( kotm2 )			/* 0039 (c) 1992 SNK */
	DRIVER( sengoku2 )		/* 0040 (c) 1993 SNK */
	DRIVER( bstars2 )		/* 0041 (c) 1992 SNK */
	DRIVER( quizdai2 )		/* 0042 (c) 1992 SNK */
	DRIVER( 3countb )		/* 0043 (c) 1993 SNK */
	DRIVER( aof )			/* 0044 (c) 1992 SNK */
	DRIVER( samsho )		/* 0045 (c) 1993 SNK */
	DRIVER( samshoh )		/* 0045 (c) 1993 SNK */
	DRIVER( tophuntr )		/* 0046 (c) 1994 SNK */
	DRIVER( tophuntrh )		/* 0046 (c) 1994 SNK */
	DRIVER( fatfury2 )		/* 0047 (c) 1992 SNK */
	DRIVER( janshin )		/* 0048 (c) 1994 Aicom */
	DRIVER( androdun )		/* 0049 (c) 1992 Visco */
	DRIVER( ncommand )		/* 0050 (c) 1992 Alpha Denshi Co. */
	DRIVER( viewpoin )		/* 0051 (c) 1992 Sammy */
	DRIVER( ssideki )		/* 0052 (c) 1992 SNK */
	DRIVER( wh1 )			/* 0053 (c) 1992 Alpha Denshi Co. */
	DRIVER( wh1h )			/* 0053 (c) 1992 Alpha Denshi Co. */
	DRIVER( wh1ha )			/* 0053 (c) 1992 Alpha Denshi Co. */
					/* 0054 Crossed Swords 2  (CD only? not confirmed, MVS might exist) */
	DRIVER( kof94 )			/* 0055 (c) 1994 SNK */
	DRIVER( aof2 )			/* 0056 (c) 1994 SNK */
	DRIVER( aof2a )			/* 0056 (c) 1994 SNK */
	DRIVER( wh2 )			/* 0057 (c) 1993 ADK */
	DRIVER( fatfursp )		/* 0058 (c) 1993 SNK */
	DRIVER( fatfurspa )		/* 0058 (c) 1993 SNK */
	DRIVER( savagere )		/* 0059 (c) 1995 SNK */
	DRIVER( fightfev )		/* 0060 (c) 1994 Viccom */
	DRIVER( fightfeva )		/* 0060 (c) 1994 Viccom */
	DRIVER( ssideki2 )		/* 0061 (c) 1994 SNK */
	DRIVER( spinmast )		/* 0062 (c) 1993 Data East Corporation */
	DRIVER( samsho2 )		/* 0063 (c) 1994 SNK */
	DRIVER( samsho2k )		/* 0063 (c) 1994 SNK (Korean hack) */
	DRIVER( wh2j )			/* 0064 (c) 1994 ADK / SNK */
	DRIVER( wjammers )		/* 0065 (c) 1994 Data East Corporation */
	DRIVER( karnovr )		/* 0066 (c) 1994 Data East Corporation */
	DRIVER( gururin )		/* 0067 (c) 1994 Face */
	DRIVER( pspikes2 )		/* 0068 (c) 1994 Video System Co. */
					/* Super Volley '94 was once released in Mar.1994, and recalled. Then released as Power Spikes 2 (with some tweaks). */
	DRIVER( fatfury3 )		/* 0069 (c) 1995 SNK */
	DRIVER( zupapa )		/* 0070 Zupapa - released in 2001, 1994 prototype probably exists */
					/* 0071 Bang Bang Busters (prototype) 1994 Visco */
					/* 0072 Last Odyssey Pinball Fantasia (prototype) 1995 Monolith */
	DRIVER( panicbom )		/* 0073 (c) 1994 Eighting / Hudson */
	DRIVER( aodk )			/* 0074 (c) 1994 ADK / SNK */
	DRIVER( sonicwi2 )		/* 0075 (c) 1994 Video System Co. */
	DRIVER( zedblade )		/* 0076 (c) 1994 NMK */
					/* 0077 The Warlocks of the Fates (prototype) 1995 Astec */
	DRIVER( galaxyfg )		/* 0078 (c) 1995 Sunsoft */
	DRIVER( strhoop )		/* 0079 (c) 1994 Data East Corporation */
	DRIVER( quizkof )		/* 0080 (c) 1995 Saurus */
	DRIVER( quizkofk )		/* 0080 (c) 1995 Saurus */
	DRIVER( ssideki3 )		/* 0081 (c) 1995 SNK */
	DRIVER( doubledr )		/* 0082 (c) 1995 Technos */
	DRIVER( pbobblen )		/* 0083 (c) 1994 Taito */
	DRIVER( pbobblenb )		/* bootleg */
	DRIVER( kof95 )			/* 0084 (c) 1995 SNK */
	DRIVER( kof95h )		/* 0084 (c) 1995 SNK */
					/* 0085 Shinsetsu Samurai Spirits Bushidoretsuden / Samurai Shodown RPG (CD only) */
	DRIVER( tws96 )			/* 0086 (c) 1996 Tecmo */
	DRIVER( samsho3 )		/* 0087 (c) 1995 SNK */
	DRIVER( samsho3h )		/* 0087 (c) 1995 SNK */
	DRIVER( fswords )		/* 0187 Korean hack of samsho3 */
	DRIVER( stakwin )		/* 0088 (c) 1995 Saurus */
	DRIVER( pulstar )		/* 0089 (c) 1995 Aicom */
	DRIVER( whp )			/* 0090 (c) 1995 ADK / SNK */
					/* 0091 */
	DRIVER( kabukikl )		/* 0092 (c) 1995 Hudson */
	DRIVER( neobombe )		/* 0093 (c) 1997 Hudson */
	DRIVER( gowcaizr )		/* 0094 (c) 1995 Technos */
	DRIVER( rbff1 )			/* 0095 (c) 1995 SNK */
	DRIVER( rbff1a )		/* 0095 (c) 1995 SNK */
	DRIVER( aof3 )			/* 0096 (c) 1996 SNK */
	DRIVER( aof3k )			/* 0196 Censored Korean release of aof3 */
	DRIVER( sonicwi3 )		/* 0097 (c) 1995 Video System Co. */
					/* 0098 Idol Mahjong - final romance 2 (CD only? not confirmed, MVS might exist) */
					/* 0099 Neo Pool Masters */
	DRIVER( turfmast )		/* 0200 (c) 1996 Nazca */
	DRIVER( mslug )			/* 0201 (c) 1996 Nazca */
	DRIVER( puzzledp )		/* 0202 (c) 1995 Taito (Visco license) */
	DRIVER( mosyougi )		/* 0203 (c) 1995 ADK / SNK */
					/* 0204 QP (prototype) */
					/* 0205 Neo-Geo CD Special (CD only) */
	DRIVER( marukodq )		/* 0206 (c) 1995 Takara */
	DRIVER( neomrdo )		/* 0207 (c) 1996 Visco */
	DRIVER( sdodgeb )		/* 0208 (c) 1996 Technos */
	DRIVER( goalx3 )		/* 0209 (c) 1995 Visco */
					/* 0210 Karate Ninja Sho (prototype) 1995 Yumekobo */
					/* 0211 Oshidashi Zintrick (CD only? not confirmed, MVS might exist) 1996 SNK/ADK */
	DRIVER( zintrckb )		/* 0211 hack - this is not a genuine MVS proto, its a bootleg made from the CD version */
	DRIVER( overtop )		/* 0212 (c) 1996 ADK */
	DRIVER( neodrift )		/* 0213 (c) 1996 Visco */
	DRIVER( kof96 )			/* 0214 (c) 1996 SNK */
	DRIVER( kof96h )		/* 0214 (c) 1996 SNK */
	DRIVER( ssideki4 )		/* 0215 (c) 1996 SNK */
	DRIVER( kizuna )		/* 0216 (c) 1996 SNK */
					/*  Fu-un Super Tag Battle Special Version (4-player battle available) exists */
	DRIVER( ninjamas )		/* 0217 (c) 1996 ADK / SNK */
	DRIVER( ragnagrd )		/* 0218 (c) 1996 Saurus */
	DRIVER( pgoal )			/* 0219 (c) 1996 Saurus */
					/* 0220 (c) 1996 Saurus - Choutetsu Brikin'ger - Iron clad (undumped protoype) */
	DRIVER( magdrop2 )		/* 0221 (c) 1996 Data East Corporation */
	DRIVER( samsho4 )		/* 0222 (c) 1996 SNK */
	DRIVER( samsho4k )		/* Censored Korean release of samsho4 */
	DRIVER( rbffspec )		/* 0223 (c) 1996 SNK */
	DRIVER( rbffspeck )		/* 0124 (c) 1996 SNK */
	DRIVER( twinspri )		/* 0224 (c) 1996 ADK */
	DRIVER( wakuwak7 )		/* 0225 (c) 1996 Sunsoft */
					/* 0226 Pair Pair Wars (prototype) 1996 Sunsoft? */
	DRIVER( stakwin2 )		/* 0227 (c) 1996 Saurus */
	DRIVER( ghostlop )		/* 0228 GhostLop (prototype) 1996? Data East */
					/* 0229 King of Fighters '96 CD Collection (CD only) */
	DRIVER( breakers )		/* 0230 (c) 1996 Visco */
	DRIVER( miexchng )		/* 0231 (c) 1997 Face */
	DRIVER( kof97 )			/* 0232 (c) 1997 SNK */
	DRIVER( kof97h )		/* 0232 (c) 1997 SNK */
	DRIVER( kof97pls )		/* bootleg of kof97 */
	DRIVER( kog )			/* bootleg of kof97 */
	DRIVER( kogplus )		/* King of Giadiator (bootleg of kof97) */
	DRIVER( magdrop3 )		/* 0233 (c) 1997 Data East Corporation */
	DRIVER( lastblad )		/* 0234 (c) 1997 SNK */
	DRIVER( lastbladh )		/* 0234 (c) 1997 SNK */
	DRIVER( lastsold )		/* 0196 Censored Korean release of lastblad */
	DRIVER( puzzldpr )		/* 0235 (c) 1997 Taito (Visco license) */
	DRIVER( irrmaze )		/* 0236 (c) 1997 SNK / Saurus */
	DRIVER( popbounc )		/* 0237 (c) 1997 Video System Co. */
	DRIVER( shocktro )		/* 0238 (c) 1997 Saurus */
	DRIVER( shocktroa )		/* 0238 (c) 1997 Saurus */
	DRIVER( blazstar )		/* 0239 (c) 1998 Yumekobo */
	DRIVER( rbff2 )			/* 0240 (c) 1998 SNK */
	DRIVER( rbff2h )		/* 0240 (c) 1998 SNK */
	DRIVER( rbff2k )		/* 0140 Censored Korean release of rbff2 */
	DRIVER( mslug2 )		/* 0241 (c) 1998 SNK */
	DRIVER( kof98 )			/* 0242 (c) 1998 SNK */
	DRIVER( kof98k )		/* 0242 (c) 1998 SNK */
	DRIVER( kof98ka )		/* 0242 (c) 1998 SNK */
	DRIVER( kof98h )		/* 0242 (c) 1998 SNK */
	DRIVER( lastbld2 )		/* 0243 (c) 1998 SNK */
	DRIVER( neocup98 )		/* 0244 (c) 1998 SNK */
	DRIVER( breakrev )		/* 0245 (c) 1998 Visco */
	DRIVER( shocktr2 )		/* 0246 (c) 1998 Saurus */
	DRIVER( lans2004 )		/* bootleg of shocktr2 */
	DRIVER( flipshot )		/* 0247 (c) 1998 Visco */
	DRIVER( pbobbl2n )		/* 0248 (c) 1999 Taito (SNK license) */
	DRIVER( ctomaday )		/* 0249 (c) 1999 Visco */
	DRIVER( mslugx )		/* 0250 (c) 1999 SNK */
	DRIVER( kof99 )			/* 0251 (c) 1999 SNK */
	DRIVER( kof99e )		/* 0251 (c) 1999 SNK */
	DRIVER( kof99k )		/* 0152 (c) 1999 SNK */
	DRIVER( kof99p )		/* 0251 (c) 1999 SNK */
	DRIVER( ganryu )		/* 0252 (c) 1999 Visco */
	DRIVER( garou )			/* 0253 (c) 1999 SNK */
	DRIVER( garoup )		/* 0253 (c) 1999 SNK */
	DRIVER( garoubl )		/* bootleg */
	DRIVER( s1945p )		/* 0254 (c) 1999 Psikyo */
	DRIVER( preisle2 )		/* 0255 (c) 1999 Yumekobo */
	DRIVER( mslug3 )		/* 0256 (c) 2000 SNK */
	DRIVER( mslug3h )		/* 0256 (c) 2000 SNK */
	DRIVER( mslug3b6 )		/* bootleg */
	DRIVER( kof2000 )		/* 0257 (c) 2000 SNK */
	DRIVER( kof2000n )		/* 0257 (c) 2000 SNK */
					/* 0258 SNK vs. Capcom? */
	DRIVER( bangbead )		/* 0259 (c) 2000 Visco */
	DRIVER( nitd )			/* 0260 (c) 2000 Eleven / Gavaking */
	DRIVER( nitdbl )		/* bootleg */
	DRIVER( sengoku3 )		/* 0261 (c) 2001 Noise Factory / SNK */
	DRIVER( kof2001 )		/* 0262 (c) 2001 Eolith / SNK */
	DRIVER( kof2001h )		/* 0262 (c) 2001 Eolith / SNK */
	DRIVER( cthd2003 )		/* bootleg of kof2001 */
	DRIVER( ct2k3sp )		/* bootleg of kof2001 */
	DRIVER( ct2k3sa )		/* bootleg of kof2001 */
	DRIVER( mslug4 )		/* 0263 (c) 2002 Mega Enterprise */
	DRIVER( mslug4h )		/* 0263 (c) 2002 Mega Enterprise */
	DRIVER( ms4plus )		/* bootleg */
	DRIVER( rotd )			/* 0264 (c) 2002 Evoga */
	DRIVER( kof2002 )		/* 0265 (c) 2002 Eolith / Playmore */
	DRIVER( kof2002b )		/* bootleg */
	DRIVER( kf2k2pls )		/* bootleg */
	DRIVER( kf2k2pla )		/* bootleg */
	DRIVER( kf2k2mp )		/* bootleg */
	DRIVER( kf2k2mp2 )		/* bootleg */
	DRIVER( kof10th )		/* bootleg of kof2002 */
	DRIVER( kf2k5uni )		/* bootleg of kof2002 */
	DRIVER( kf10thep )		/* bootleg of kof2002 */
	DRIVER( kof2k4se )		/* bootleg of kof2002 */
	DRIVER( matrim )		/* 0266 (c) 2002 Atlus */
	DRIVER( matrimbl )		/* bootleg */
	DRIVER( pnyaa )			/* 0267 (c) 2003 Aiky / Taito */
	DRIVER( ms5pcb )		/* 0268 (c) 2003 Playmore */
	DRIVER( mslug5 )		/* 0268 (c) 2003 Playmore */
	DRIVER( mslug5h )		/* 0268 (c) 2003 Playmore */
	DRIVER( ms5plus )		/* bootleg */
	DRIVER( svcpcb )		/* 0269 (c) 2003 Playmore / Capcom - JAMMA PCB */
	DRIVER( svcpcba )		/* 0269 (c) 2003 Playmore / Capcom - JAMMA PCB */
	DRIVER( svc )			/* 0269 (c) 2003 Playmore / Capcom */
	DRIVER( svcboot )		/* bootleg */
	DRIVER( svcplus )		/* bootleg */
	DRIVER( svcplusa )		/* bootleg */
	DRIVER( svcsplus )		/* bootleg */
	DRIVER( samsho5 )		/* 0270 (c) 2003 Playmore */
	DRIVER( samsho5h )		/* 0270 (c) 2003 Playmore */
	DRIVER( samsho5b )		/* bootleg */
	DRIVER( kf2k3pcb )		/* 0271 (c) 2003 Playmore - JAMMA PCB */
	DRIVER( kof2003 )		/* 0271 (c) 2003 Playmore */
	DRIVER( kof2003h )		/* 0271 (c) 2003 Playmore */
	DRIVER( kf2k3bl )		/* bootleg */
	DRIVER( kf2k3bla )		/* bootleg */
	DRIVER( kf2k3pl )		/* bootleg */
	DRIVER( kf2k3upl )		/* bootleg */
	DRIVER( samsh5sp )		/* 0272 (c) 2004 Playmore */
	DRIVER( samsh5sph )		/* 0272 (c) 2004 Playmore */
	/* The BrezzaSoft games don't have proper ID codes */
	DRIVER( jockeygp )
	DRIVER( vliner )
	DRIVER( vlinero )
	/* Nor does Digger Man */
	DRIVER( diggerma )		/* No Game ID (unlicensed), (c) 2000 Kyle Hodgetts, prototype */
	/* Neo Print */
	DRIVER( 98best44 )
/*	DRIVER( crswd2bl )	*/	/* Crossed Sword 2, bootleg of NGCD version */
	DRIVER( 3countba )		/* 3 Count Bout / Fire Suplex (NGM-043) */
	DRIVER( fatfury2a )		/* Fatal Fury 2 / Garou Densetsu 2 - arata-naru tatakai (NGM-047) */
	DRIVER( fatfury3a )		/* Fatal Fury 3 - Road to the Final Victory / Garou Densetsu 3 - arata-naru tatakai (NGM-069) (NGH-069) (alternate set) */
	DRIVER( alpham2p )		/* Alpha Mission 2 /ASO 2 (prototype) */
	DRIVER( b2b )			/* Bang Bang Busters (NCI release) */
	DRIVER( bangbedp )		/* Bang Bead (prototype) */
	DRIVER( burningfp )		/* Burning Fight (prototype) */
	DRIVER( jockeygpa )		/* Jockey Grand Prix (set 2) */
	DRIVER( garouh )		/* Garou - Mark of the Wolves (NGM-2530 ~ NGH-2530) */
	DRIVER( ironclad )		/* Choutetsu Brikin'ger - Iron clad (prototype) */
	DRIVER( ironclado )		/* bootleg, Choutetsu Brikin'ger - Iron clad (prototype) */
	DRIVER( fr2ch )			/* Idol Mahjong - final romance 2 (bootleg of NGCD) */
	DRIVER( kof2000ps2 )		/* The King of Fighters 2000 (Playstation 2 ver.) */
	DRIVER( kf2k1pls )		/* The King of Fighters 2001 Plus (bootleg set 1) */
	DRIVER( kf2k1pa )		/* The King of Fighters 2001 Plus (bootleg set 2) */
	DRIVER( cthd2k3a )		/* Crouching Tiger Hidden Dragon 2003 (bootleg of The King of Fighters 2001) (alternate set) */
	DRIVER( kf2k2plb )		/* The King of Fighters 2002 Plus (bootleg of kof2002) */
	DRIVER( kf2k2plc )		/* The King of Fighters 2002 Super (bootleg of kof2002) */
	DRIVER( kf2k2ps2 )		/* The King of Fighters 2002 (Playstation 2 ver.) */
	DRIVER( kf2k4pls )		/* The King of Fighters Special Edition 2004 Plus (bootleg of kof2002) */
	DRIVER( kof95a )		/* The king of Fighters' 95 (NGM-084) (alternate board) */
	DRIVER( kof96a )		/* The king of Fighters' 96 (NGM-214) (alternate board) */
	DRIVER( kof96ae )		/* The King of Fighters' 96 Anniversary Edition (bootleg of kof96) */
	DRIVER( kof96ae20 )		/* The King of Fighters' 96 Anniversary Edition 2.0 (bootleg of kof96) */
	DRIVER( kof96cn )		/* The King of Fighters' 96 Chinese Edition v1.0 (bootleg of kof96) */
	DRIVER( kof96ep )		/* The King of Fighters' 96 (bootleg of kof96) */
	DRIVER( kof97k )		/* The King of Fighters' 97 (Korean release) */
	DRIVER( kof97cn )		/* The King of Fighters' 97 10th Anniversary Chinese Edition (bootleg of kof97) */
	DRIVER( kof97oro )		/* The King of Fighters' 97 Oroshi Plus 2003 set 2 (bootleg of kof97) */
	DRIVER( kof97pla )		/* The King of Fighters' 97 Oroshi Plus 2003 set 1 (bootleg of kof97) */
	DRIVER( kof97xt )		/* The King of Fighters' 97 - Final Battle (bootleg, hack) */
	DRIVER( kof98a )		/* The King of Fighters' 98 (NGM-2420, alternate board) */
	DRIVER( kof99h )		/* The King of Fighters' 99 (NGH-2510) */
	DRIVER( kof99ae )		/* The King of Fighters' 99 15th Anniversary Edition, bootleg */
	DRIVER( kotm2p )		/* King of the Monsters 2 - The Next Thing (prototype) */
	DRIVER( lresortp )		/* Last Resort (prototype) */
	DRIVER( mslug2t )		/* Metal Slug 2 turbo (hack) */
	DRIVER( roboarma )		/* Robo Army (NGM-032 ~ NGH-032) */
	DRIVER( samshoa )		/* Samurai Shodown / Samurai Spirits (NGM-045, alternate board) */
	DRIVER( samsho2k2 )		/* Saulabi Spirits / Jin Saulabi Tu Hon (Korean release of Samsho2) */
	DRIVER( wh2ja )			/* World Heroes 2 Jet (ADM-007) */
	DRIVER( sengoku3s )		/* Sengoku 3 / Sengoku Densho 2001 , FCHT hack */
	DRIVER( lhcdb )			/* Last Hope (bootleg of CD version) */
	DRIVER( totcarib )		/* Treasure of the Caribbean */
	DRIVER( samsho5x )		/* Samurai Shodown V / Samurai Spirits Zero (XBOX version, hack) */
	DRIVER( mslug5b )		/* Metal Slug 5 (bootleg) */
	DRIVER( samsh5spho )		/* Samurai Shodown V Special / Samurai Spirits Zero Special (NGH-2720) (1st release, censored) */
	DRIVER( zintrkcd )		/* Zintrick / Oshidashi Zentrix (NGCD Conversion) */
	DRIVER( lastblada )		/* The Last Blade / Bakumatsu Roman - Gekka no Kenshi (NGM-2340, alternate board) */
	DRIVER( unkneo )		/* unkneo (Dragon's Heaven), development board */
					//
	DRIVER( kof98ae )		/* (NOT_WORKING) The King of Fighters' 98 Anniversary Edition, EGHT hack  !!Note: It's very unstable. the graphics are flawed. these are said to be related to MAME's M68K CPU drivers. */
	DRIVER( kof98ae2016 )		/* (NOT_WORKING) hackrom */
	DRIVER( kof98cb )		/* (NOT_WORKING) hackrom */

	
	/* *************************************** */
	/*  Part 5 - M92 HACKS FROM HBMAME 0.210  */
	/* ************************************* */	  
	//20190516
	DRIVER( hooks01 )		/* Hook (1V4 2016-06-25) */
	DRIVER( hooks02 )		/* Hook (Zinc Children's Edition Update 2018-05-15) */
	DRIVER( hooks03 )		/* Hook (Zinc Children's Edition Update 2018-05-02) */
	DRIVER( hooks04 )		/* Hook (X2 Edition 2018-05-05) */
	DRIVER( hooks05 )		/* Hook (Can Be Substituted For Character) */
	DRIVER( hooks06 )		/* Hook (Unrivalled Version 2016-08-18) */
	DRIVER( hookus01 )		/* Hook (plus) */
	DRIVER( hookus02 )		/* Hook (Iron hook unparalleled 2016-07-31) */
	DRIVER( hookxr )		/* Hook (Zinc Children's Edition Update 2018-09-14) */
	DRIVER( nbbatmans01 )		/* Ninja Baseball Bat Man (X2 Edition 2018-05-05) */
	DRIVER( nbbatmans02 )		/* Ninja Baseball Bat Man (1V4 2017-03-15) */
	DRIVER( nbbatmanus01 )		/* Ninja Baseball Bat Man (Unknown Hack 2013-06-04) */
	DRIVER( nbbatmanus02 )		/* Ninja Baseball Bat Man (New Starter Edition Update 2016-10-16) */
	DRIVER( nbbatmanus03 )		/* Ninja Baseball Bat Man (Musou version 2019-02-23) */
	DRIVER( nbbatmanus04 )		/* Ninja Baseball Bat Man (Characters Changeable 2016-12-03) */
	DRIVER( nbbatmanus05 )		/* Ninja Baseball Bat Man (Musou Edition 2019-03-08) */


	/* *************************************** */
	/*  Part 6 - CPS2 HACKS FROM HBMAME 0.211  */
	/* *************************************** */		
	// 20190516
	DRIVER( 1944da )		/* 1944: The Loop Master (USA 000620 Phoenix Edition) (bootleg alt) */
	// REQUIRE KEY STUFF  //DRIVER( 1944fp )		/* 1944: The Loop Master (Fire Power Plus 2011-12-31) */  
	DRIVER( 1944s01 )		/* 1944: The Loop Master (Strongest Fire Power) */
	DRIVER( 19xxjrs01 )		/* 19XX: The War Against Destiny (Translation Chinese) */
	DRIVER( 19xxs01 )		/* 19XX: The War Against Destiny (Ex Super Version) */
	DRIVER( avspud )		/* Alien vs. Predator (USA 940520 Phoenix edition) */
	DRIVER( avspus01 )		/* Alien vs. Predator (1 Vs 3 Plus 2017-12-30) */
	DRIVER( avspus02 )		/* Alien vs. Predator (Enhanced Edition 2018-02-26) */
	DRIVER( csclubs01 )		/* Capcom Sports Club (Time Increases) */
	DRIVER( cybotsjs01 )		/* Cyberbots: Fullmetal Madness (Get Maximum Power On A Valid Attack Or Being Attacked) */
	DRIVER( ddsoma4ppdec )		/* Dungeons & Dragons: Shadow over Mystara (Plus) */
	DRIVER( ddsomavs )		/* Dungeons & Dragons: Shadow over Mystara (Lock four person mode 2009-06-29) */
	DRIVER( ddsomchs )		/* Dungeons & Dragons: Shadow over Mystara (Translation Chinese) */
	DRIVER( ddsomhp )		/* Dungeons & Dragons: Shadow over Mystara (Strengthen The Physical Model 2009-06-15) */
	DRIVER( ddsomjfs )		/* Dungeons & Dragons: Shadow over Mystara (Change the Final Strike condition 2009-07-17) */
	DRIVER( ddsomjs01 )		/* Dungeons & Dragons: Shadow over Mystara (Translation Chinese 2017-04-26) */
	//DRIVER( ddsomuds01 )		/* Dungeons & Dragons: Shadow over Mystara (Diablo Mystery 2016-07-14) */
	DRIVER( ddsomuds02 )		/* Dungeons & Dragons: Shadow over Mystara (USA 960619 Phoenix Edition	Plus) (bootleg) */
	DRIVER( ddtodpdec )		/* Dungeons & Dragons: Tower of Doom (Plus) */
	DRIVER( gigawings01 )		/* Giga Wing (Ex Super Version V1) */
	//DRIVER( halfway )		/* Halfway to Hell - Progear Red Label (2016-01-17 Red label ver) */
	DRIVER( hsf2js00 )		/* Hyper Street Fighter II: The Anniversary Edition (3x Time) */
	DRIVER( hsf2js01 )		/* Hyper Street Fighter II: The Anniversary Edition (Choose Hidden Characters Easier) */
	DRIVER( hsf2js02 )		/* Hyper Street Fighter II: The Anniversary Edition (Enabled Hidden Characters In Normal Mode) */
	DRIVER( hsf2js03 )		/* Hyper Street Fighter II: The Anniversary Edition (Simplify The Move) */
	DRIVER( hsf2js04 )		/* Hyper Street Fighter II: The Anniversary Edition (Gouki Edition) */
	DRIVER( hsf2js05 )		/* Hyper Street Fighter II: The Anniversary Edition (Can Choice Same Character) */
	DRIVER( hsf2js06 )		/* Hyper Street Fighter II: The Anniversary Edition (Changed Character ｖ2) */
	DRIVER( hsf2js07 )		/* Hyper Street Fighter II: The Anniversary Edition (Easy Move v2) */
	DRIVER( hsf2js08 )		/* Hyper Street Fighter II: The Anniversary Edition (Choose Hidden Character) */
	DRIVER( hsf2js09 )		/* Hyper Street Fighter II: The Anniversary Edition (Hit Anywhere) */
	DRIVER( hsf2js10 )		/* Hyper Street Fighter II: The Anniversary Edition (Level Plus) */
	DRIVER( hsf2js11 )		/* Hyper Street Fighter II: The Anniversary Edition (Always Have Super Move) */
	DRIVER( hsf2js12 )		/* Hyper Street Fighter II: The Anniversary Edition (Real Gouki) */
	DRIVER( hsf2js13 )		/* Hyper Street Fighter II: The Anniversary Edition (Special Move For Zangief) */
	DRIVER( hsf2js14 )		/* Hyper Street Fighter II: The Anniversary Edition (30% Blood) */
	//DRIVER( mpangjd )		/* Mighty! Pang (Japan 001011 Phoenix Edition) */
	DRIVER( mshjphp )		/* Marvel Super Heroes (Get maximum power on a valid attack or being attacked) */
	DRIVER( mshs01 )		/* Marvel Super Heroes (Rise Again 2014-12-24) */
	DRIVER( mshs02 )		/* Marvel Super Heroes (Unknown Hack 2015-12-04) */
	DRIVER( mshvsemb )		/* Marvel Super Heroes Vs. Street Fighter (Easy Moves 2009-04-23) */
	DRIVER( mshvsfjh )		/* Marvel Super Heroes Vs. Street Fighter (Enable Hidden Characters) */
	DRIVER( mshvsfjphp )		/* Marvel Super Heroes Vs. Street Fighter (Get maximum power on a valid attack or being attacked) */
	DRIVER( mshvsfjs01 )		/* Marvel Super Heroes Vs. Street Fighter (Move The Order To Modify 2008-07-21) */
	DRIVER( mshvsfjs02 )		/* Marvel Super Heroes Vs. Street Fighter (Rise Again 2014-12-14) */
	DRIVER( mshvsfjs03 )		/* Marvel Super Heroes Vs. Street Fighter (Unknown Hack 2015-12-05) */
	DRIVER( mshvsfs01 )		/* Marvel Super Heroes Vs. Street Fighter (Can Be Substitutions At Any Time 2010-08-18) */
	DRIVER( mshvsfs02 )		/* Marvel Super Heroes Vs. Street Fighter (Unknown Hack 2013-10-08) */
	DRIVER( mshyh )		/* Marvel Super Heroes (Enable Hidden Characters) */
	DRIVER( mvscjemb )		/* Marvel Vs. Capcom: Clash of Super Heroes (Easy Moves 2009-04-24) */
	DRIVER( mvscjphp )		/* Marvel Vs. Capcom: Clash of Super Heroes (Get maximum power on a valid attack or being attacked) */
	DRIVER( mvscjs01 )		/* Marvel Vs. Capcom: Clash of Super Heroes (Move The Order To Modify V1 2008-07-15) */
	DRIVER( mvscjs02 )		/* Marvel Vs. Capcom: Clash of Super Heroes (Move The Order To Modify V2 2009-07-15) */
	//DRIVER( mvscrcp )		/* Marvel Vs. Capcom (RCP) */
	//DRIVER( mvscuh )		/* Marvel Vs. Capcom: Clash of Super Heroes (Add Boss) */
	DRIVER( mvsh01 )		/* Marvel Vs. Capcom: Clash of Super Heroes (Enable EX.Characters) */
	DRIVER( mvsh02 )		/* Marvel Vs. Capcom: Clash of Super Heroes (Unknown Hack 2013-10-08) */
	DRIVER( pfghtjrm )		/* Pocket Fighter (Rise Starts Lite 2014-12-17) */
	DRIVER( pfghtjs01 )		/* Pocket Fighter (Command Change 2008-01-12) */
	DRIVER( pfghtjs02 )		/* Pocket Fighter (Enhanced Power 2008-07-28) */
	DRIVER( pfghtjs03 )		/* Pocket Fighter (Move Mod 11-10-2007) */
	DRIVER( progearjds01 )		/* Progear no Arashi (Crazy Fire Version V1) */
	DRIVER( progearjds02 )		/* Progear no Arashi (Crazy Fire Version V2) */
	DRIVER( sfa2h )		/* Street Fighter Alpha 2 (Enable Hidden Characters) */
	DRIVER( sfa2us01 )		/* Street Fighter Alpha 2 (Command Change 2007-12-16) */
	DRIVER( sfa2us02 )		/* Street Fighter Alpha 2 (Super Killing Force Modification 2008-02-17) */
	DRIVER( sfa2us03 )		/* Street Fighter Alpha 2 (Cancellation Power) */
	DRIVER( sfa2us04 )		/* Street Fighter Alpha 2 (Simplified) */
	DRIVER( sfa3br )		/* Street Fighter Alpha 3 (Brasil translation) */
	DRIVER( sfa3dp )		/* Street Fighter Alpha 3 (Xiang Long edition 2009-05-10) */
	DRIVER( sfa3nc )		/* Street Fighter Alpha 3 (Edition Nude Cammy) */
	DRIVER( sfa3nch )		/* Street Fighter Alpha 3 (Edition Nude Chunli) */
	DRIVER( sfa3ncj )		/* Street Fighter Alpha 3 (Edition Nude Juli & Juni) */
	DRIVER( sfa3s01 )		/* Street Fighter Alpha 3 (Modified Version Of The Directive 2009-05-10) */
	DRIVER( sfa3s02 )		/* Street Fighter Alpha 3 (Simplified) */
	DRIVER( sfa3s03 )		/* Street Fighter Alpha 3 (Moves Hack 2007-11-03) */
	DRIVER( sfa3s04 )		/* Street Fighter Alpha 3 (Unlock All Modes 2004-04-18) */
	DRIVER( sfa3s05 )		/* Street Fighter Alpha 3 (2 VS 1 27 Round) */
	DRIVER( sfa3s06 )		/* Street Fighter Alpha 3 (Dragon Edition 2014-11-18) */
	DRIVER( sfa3sp2 )		/* Street Fighter Alpha 3 (Hidden Character Full Version Fix 2009-09-27) */
	DRIVER( sfa3spp )		/* Street Fighter Alpha 3 (Boss Special 2009-07-03) */
	DRIVER( sfa3uhd )		/* Street Fighter Alpha 3 (Revision Version) */
	DRIVER( sfas01 )		/* Street Fighter Alpha: Warriors' Dreams (Enable Hidden Characters) */
	DRIVER( sfas02 )		/* Street Fighter Alpha: Warriors' Dreams (Simplified) */
	//DRIVER( sfaud )		/* Street Fighter Alpha: Warriors' Dreams (USA 950727 Phoenix Edition)(bootleg) */
	DRIVER( sfz2abr )		/* Street Fighter Zero 2 Alpha (Brasil translation) */
	DRIVER( sfz2ajhp )		/* Street Fighter Zero 2 Alpha (Enhanced Dan Version 2008-12-11) */
	DRIVER( sfz2aldp )		/* Street Fighter Zero 2 Alpha (Dragon Edition v1.0 2009-03-17) */
	DRIVER( sfz2aldp2 )		/* Street Fighter Zero 2 Alpha (Dragon Edition v2.0 2009-04-24) */
	DRIVER( sfz2aljs00 )		/* Street Fighter Zero 2 Alpha (Simplified) */
	DRIVER( sfz2aljs01 )		/* Street Fighter Zero 2 Alpha (Command Change 12-10-2007) */
	DRIVER( sfz2aljs02 )		/* Street Fighter Zero 2 Alpha (Easy Moves Hack 11-10-2007) */
	DRIVER( sfz2aljs03 )		/* Street Fighter Zero 2 Alpha (Enable Hidden Characters) */
	DRIVER( sfz2aljs04 )		/* Street Fighter Zero 2 Alpha (Enhanced Power) */
	DRIVER( sfz2aljs05 )		/* Street Fighter Zero 2 Alpha (Moves Hack 11-10-2007) */
	DRIVER( sfz2aljs06 )		/* Street Fighter Zero 2 Alpha (Super Combo 2008-02-17) */
	DRIVER( sfz2aljs07 )		/* Street Fighter Zero 2 Alpha (Dragon Edition v2.1 2009-04-24) */
	DRIVER( sfz2aljs08 )		/* Street Fighter Zero 2 Alpha (Dragon Fighter Enhanced Edition 2014-11-19) */
	DRIVER( sfz2jyh )		/* Street Fighter Zero 2 (Boss hack) */
	DRIVER( sfz3jb )		/* Street Fighter Zero 3 (Enable hidden characters) */
	DRIVER( sfz3jemb )		/* Street Fighter Zero 3 (Easy Moves)(2009-05-01) */
	DRIVER( sfz3jhp )		/* Street Fighter Zero 3 (Moves hack 2017-03-11) */
	DRIVER( sfz3js01 )		/* Street Fighter Zero 3 (Balrog Lifts The Scene Crawl Limit) */
	DRIVER( sfz3js02 )		/* Street Fighter Zero 3 (Command Change) */
	DRIVER( sfz3js03 )		/* Street Fighter Zero 3 (Command Change V2) */
	DRIVER( sfz3js04 )		/* Street Fighter Zero 3 (Command Change V2.1) */
	DRIVER( sfz3js05 )		/* Street Fighter Zero 3 (Command Change V2.2) */
	DRIVER( sfz3js06 )		/* Street Fighter Zero 3 (Command Change V3 2007-12-22) */
	DRIVER( sfz3js07 )		/* Street Fighter Zero 3 (Enhanced Power) */
	DRIVER( sfz3js08 )		/* Street Fighter Zero 3 (Hidden Character Full Version Restored 2009-09-27) */
	DRIVER( sfz3js09 )		/* Street Fighter Zero 3 (2 VS 1 27 Round) */
	DRIVER( sfz3js10 )		/* Street Fighter Zero 3 (Nude Cammy) */
	DRIVER( sfz3js11 )		/* Street Fighter Zero 3 (Nude Chun-Li) */
	DRIVER( sfz3js12 )		/* Street Fighter Zero 3 (Nude Juli & Juni) */
	DRIVER( sfz3jsep )		/* Street Fighter Zero 3 (Shin Edition 2009-01-01) */
	DRIVER( sfzjboss )		/* Street Fighter Zero (Enable hidden characters V1) */
	DRIVER( sfzjs01 )		/* Street Fighter Zero (Command Change 2007-12-22) */
	DRIVER( sfzjs02 )		/* Street Fighter Zero (Enhanced Power) */
	DRIVER( sfzjs03 )		/* Street Fighter Zero (Fist Punch Enhancement 2009-06-05) */
	DRIVER( sfzjs04 )		/* Street Fighter Zero (Moves Hack 2007-11-10) */
	DRIVER( sfzjs05 )		/* Street Fighter Zero (Super-Entry Force To Modify 2008-02-17) */
	DRIVER( sfzjyh )		/* Street Fighter Zero (Enable hidden characters V2) */
	DRIVER( sgemfch )		/* Pocket Fighter (Color remix) */
	DRIVER( spf2tb )		/* Super Puzzle Fighter II Turbo (Boss Hack) */
	DRIVER( ssf2js01 )		/* Super Street Fighter II X: The New Challengers (Unknown Hack 2012-09-12) */
	DRIVER( ssf2r1d )		/* Super Street Fighter II X: The New Challengers (ETC 930911 Phoenix Edition) */
	//DRIVER( ssf2td )		/* Super Street Fighter II Turbo (940223 Etc Phoenix Edition)(bootleg) */
	DRIVER( ssf2tfp )		/* Super Street Fighter II Turbo (French Parody) */
	DRIVER( ssf2tfr )		/* Super Street Fighter II Turbo (Translation French 2015-01-XX) */
	DRIVER( ssf2tpls )		/* Super Street Fighter II Turbo (Plus v0.9 beta) */
	DRIVER( ssf2ts01 )		/* Super Street Fighter II Turbo (Accelerated Plus V0.9 Beta 2014-12-16) */
	DRIVER( ssf2ts02 )		/* Super Street Fighter II Turbo (Instruction Is Simplified 2009-05-28) */
	DRIVER( ssf2tus01 )		/* Super Street Fighter II Turbo (Nude Cammy) */
	DRIVER( ssf2tus02 )		/* Super Street Fighter II Turbo (Retro color) */
	DRIVER( ssf2xjhy )		/* Super Street Fighter II X: Grand Master Challenge (Choose hidden characters easier) */
	DRIVER( ssf2xjjs )		/* Super Street Fighter II X: Grand Master Challenge (Retro color) */
	DRIVER( ssf2xjnc )		/* Super Street Fighter II X: Grand Master Challenge (Nude Cammy) */
	DRIVER( ssf2xjs01 )		/* Super Street Fighter II X: Grand Master Challenge (Change FireBall 2012-01-07) */
	DRIVER( ssf2xjs02 )		/* Super Street Fighter II X: Grand Master Challenge (Gouki Color Change) */
	DRIVER( ssf2zhp )		/* Super Street Fighter II X: The New Challengers (Zangief instruction simplification 2009-01-05) */
	DRIVER( suicide )		/* Suicide Test */
	DRIVER( suicide2 )		/* Suicide Test v2 */
	DRIVER( vampjb )		/* Vampire: The Night Warriors (Enable hidden characters 2006-05-31) */
	DRIVER( vsav2emb )		/* Vampire Savior 2: The Lord of Vampire (Vampire Kingdom Study Order Simplification 2009-04-30) */
	DRIVER( vsav2s01 )		/* Vampire Savior 2: The Lord of Vampire (Command Change 2008-4-19) */
	DRIVER( vsav2s02 )		/* Vampire Savior 2: The Lord of Vampire (Infinite Power 2008-07-28) */
	DRIVER( xmcotaj2s01 )		/* X-Men: Children of the Atom (Enable Hidden Characters) */
	DRIVER( xmcotaj2s02 )		/* X-Men: Children of the Atom (Unknown Hack 2013-01-09) */
	DRIVER( xmcotajb )		/* X-Men: Children of the Atom (Boss hack) */
	DRIVER( xmcotajphp )		/* X-Men: Children of the Atom (Enhanced power) */
	DRIVER( xmvsfjphp )		/* X-Men Vs. Street Fighter (Enhanced power) */
	DRIVER( xmvsfjs01 )		/* X-Men Vs. Street Fighter (Move The Order To Modify 2008-07-20) */
	DRIVER( xmvsfrm )		/* X-Men Vs. Street Fighter (Easy Moves 2009-04-22) */
	DRIVER( xmvsfryh )		/* X-Men Vs. Street Fighter (Change character in battle) */
	DRIVER( xmvsfs01 )		/* X-Men Vs. Street Fighter (Nude Alpha Chun Li) */
	DRIVER( xmvsfs02 )		/* X-Men Vs. Street Fighter (Unknown Hack 2015-12-04) */
	DRIVER( xmvsfs03 )		/* X-Men Vs. Street Fighter (Edition Enhanced) */
	DRIVER( pzloop2jd )		/* Puzz Loop 2 (Japan 010226 Phoenix Edition) */
	
	/* *************************************** */
	/*  Part 7 - CPS HACKS FROM HBMAME 0.211  */
	/* *************************************** */	
	
	// Three Wonders
	DRIVER( 3wondrud )  /* Three Wonders (US 910520 Phoenix Edition) */
	DRIVER( 3wondersb01 )  /* Three Wonders (bootleg set 3, wonder 3 910520 etc) */
	DRIVER( 3wonders01 )  /* Three Wonders (Ex Super Version) */
	DRIVER( 3wonders02 )  /* Three Wonders (Unlimited Life) */

	// Captain Commando
	DRIVER( captcomc )  /* Captain Commando (Translation Chinese) */
	DRIVER( captcomh )  /* Captain Commando (Ex Super version 2008-05-10) */
	DRIVER( captcoud )  /* Captain Commando (US 910928 Phoenix Edition) */
	DRIVER( captcommh01 )  /* Captain Commando (Elite Edition Update 2018-12-31) */
	DRIVER( captcommh02 )  /* Captain Commando (Infinite Bullet Update 2019-01-21) */
	DRIVER( captcommh03 )  /* Captain Commando (Warlord Version 2019-01-07) */
	DRIVER( captcommh04 )  /* Captain Commando (Shape Shifting Version 2019-01-01) */
	DRIVER( captcommh05 )  /* Captain Commando (99 Beaters Edition Update 2019-01-02) */
	DRIVER( captcommh06 )  /* Captain Commando (99 Beaters Edition Update 2018-11-01) */
	DRIVER( captcomms01 )  /* Captain Commando (Characters Change 2009-01-20) */
	DRIVER( captcomms04 )  /* Captain Commando (Unlock 1Vs4 Mode 2009-04-25) */
	DRIVER( captcomms05 )  /* Captain Commando (1V4 Unparalleled Version 2016-02-17) */
	DRIVER( captcomms07 )  /* Captain Commando (War Chariot And Change Character 2015-10-12) */
	DRIVER( captcomms09 )  /* Captain Commando (Baby sitting reinforcement 2009-04-12) */
	DRIVER( captcomms10 )  /* Captain Commando (Boss White Blood) */
	DRIVER( captcomms11 )  /* Captain Commando (Easy Mode 2013-06-22) */
	DRIVER( captcomms12 )  /* Captain Commando (Level Enemy Configuration Changes 2015-01-12) */
	DRIVER( captcomms13 )  /* Captain Commando (Catch People Unlimited Hit v1 2013-10-26) */
	DRIVER( captcomms14 )  /* Captain Commando (Catch People Unlimited Hit v2 2014-07-26) */
	DRIVER( captcomms15 )  /* Captain Commando (Infinite Ammo) */
	DRIVER( captcomms16 )  /* Captain Commando (Infinite Time) */
	DRIVER( captcomms17 )  /* Captain Commando (Infinite Time Stage 5) */
	DRIVER( captcomms18 )  /* Captain Commando (Items Never Disappear) */
	DRIVER( captcomms19 )  /* Captain Commando (Stage 8 Soldier Became Boss Test 2016-03-06) */
	DRIVER( captcomms20 )  /* Captain Commando (4 Players White Blood) */
	DRIVER( captcomms21 )  /* Captain Commando (Robots White Blood) */
	DRIVER( captcomms22 )  /* Captain Commando (Unlock 1Vs4 Mode)(New) */
	DRIVER( captcomms23 )  /* Captain Commando (Weapons Flashing) */
	DRIVER( captcomms24 )  /* Captain Commando (Put Insurance Can Not Afford To Drop Blood) */
	DRIVER( captcomms27 )  /* Captain Commando (Extreme Mode) */
	DRIVER( captcomms29 )  /* Captain Commando (99 Beaters Edition Update 2017-22-09) */
	DRIVER( captcomms30 )  /* Captain Commando (99 Beaters Edition Update 2017-25-11) */
	DRIVER( captcomms31 )  /* Captain Commando (99 Beaters Edition Update 2017-20-12) */
	DRIVER( captcomms32 )  /* Captain Commando (99 Beaters Edition Update 2018-02-05) */
	DRIVER( captcomms33 )  /* Captain Commando (99 Beaters Edition Update 2017-03-09) */
	DRIVER( captcomms34 )  /* Captain Commando (99 Beaters Edition Update 2018-27-02) */
	DRIVER( captcomms35 )  /* Captain Commando (99 Beaters Edition Update 2018-26-01) */
	DRIVER( captcomms36 )  /* Captain Commando (1Vs4 Edition 2018 2018-01-20) */
	DRIVER( captcomms37 )  /* Captain Commando (Elite Edition Update 2018-05-30) */
	DRIVER( captcomms38 )  /* Captain Commando (99 Beaters Edition Update 2018-05-31) */
	DRIVER( captcomms39 )  /* Captain Commando (God of War Edition Update 2018-06-06) */
	DRIVER( captcomms40 )  /* Captain Commando (99 Beaters Edition Update 2018-07-04) */
	DRIVER( captcomms41 )  /* Captain Commando (Hit Anywhere Rev.1 2018-08-09) */
	DRIVER( captcomms42 )  /* Captain Commando (Press Button Change Weapon) */
	DRIVER( captcomms43 )  /* Captain Commando (Quickly Go Next Stage) */
	DRIVER( captcomms44 )  /* Captain Commando (Stage Select) */
	DRIVER( captcomms46 )  /* Captain Commando (Hit Anywhere Rev.2 2018-08-09) */
	DRIVER( captcomms47 )  /* Captain Commando (God of War Edition Update 2018-08-14) */
	DRIVER( captcomms48 )  /* Captain Commando (99 Beaters Edition Update 2018-07-07) */
	DRIVER( captcomms49 )  /* Captain Commando (Elite Edition Update 2018-07-07) */
	DRIVER( captcomms50 )  /* Captain Commando (God of War Edition Update 2018-09-11) */
	DRIVER( captcomms51 )  /* Captain Commando (99 Beaters Edition Update 2018-09-10) */
	DRIVER( captcomms52 )  /* Captain Commando (99 Beaters Edition Update 2018-10-12) */
	DRIVER( captcomms53 )  /* Captain Commando (Elite Edition Update 2018-11-08) */
	DRIVER( captcomms54 )  /* Captain Commando (God of War Edition Update 2018-10-31) */
	DRIVER( captcomms55 )  /* Captain Commando (Plus 2016-11-28) */
	DRIVER( captcomms56 )  /* Captain Commando (99 Beaters Edition Update 2019-04-15) */
	DRIVER( captcomms57 )  /* Captain Commando (God of War Edition Update 2019-04-15) */
	DRIVER( captcomms58 )  /* Captain Commando (Infinity bullet Update 2019-04-15) */
	DRIVER( captcomms59 )  /* Captain Commando (Dream Version 2019-04-15) */
	DRIVER( captcomms60 )  /* Captain Commando (Enhanced Edition 2019-05-30) */
	
	// Final Fight
	DRIVER( ffightb )  /* Final Fight (Quick whirlwind) */
	DRIVER( ffightjh01 )  /* Final Fight (Ming Yun Wu Shuang Edition 2016 2016-12-08) */
	DRIVER( ffights01 )  /* Final Fight (Change Fighter) */
	DRIVER( ffights02 )  /* Final Fight (1VS2 Enhanced Version 2016-08-17) */
	DRIVER( ffightj2s01 )  /* Final Fight (Ming Yun Wu Shuang Edition 2016 2016-10-24 ) */
	DRIVER( ffightj2s02 )  /* Final Fight (Paced Whirlwind 2016-08-17) */
	DRIVER( ffightj1s01 )  /* Final Fight (1VS2 Enhanced Version 2017-11-26) */
	
	// Strider
	DRIVER( stridergf )  /* Strider (Gfx fix) */
	DRIVER( stridergh )  /* Strider (Gfx fix, uncensored) */
	DRIVER( striders01 )  /* Strider (Fixed Music In Last Several Stages) */
	
	// Mercs
	DRIVER( mercs01 )  /* Mercs (Crazy Fire Version) */
	DRIVER( mercjs01 )  /* Senjou no Ookami II (Translation Chinese) */
	
	// Varth: Operation Thunderstorm
	DRIVER( varths01 )  /* Varth: Operation Thunderstorm (Ex Super Version V1) */
	DRIVER( varths02 )  /* Varth: Operation Thunderstorm (Ex Super Version V2) */
	
	// Willow
	DRIVER( willows01 )  /* Willow (Ex Super Version) */
	
	// Knights of the Round
	DRIVER( knight21 )  /* Knights of the Round (Stepping Value And Treasure Display Ver 2.1 2011-07-12) */
	//DRIVER( knightsa )  /* Knights of the Round (Angry Update) */
	DRIVER( knightshb2 )  /* Knights of the Round (bootleg/set 2) */
	//DRIVER( knightsh )  /* Knights of the Round (Unknown Hack) */
//	DRIVER( knightsha )  /* Knights of the Round (911127 etc bootleg set 2) */
	DRIVER( knightsjb )  /* Knights of the Round (bootleg set 3, 911127 Japan) */
	DRIVER( knightsro )  /* Knights of the Round (Romanian) */
	DRIVER( knightud )  /* Knights of the Round (US 911127 Phoenix Edition) */
	DRIVER( knightsh01 )  /* Knights of the Round (Anger upgrade) */
	DRIVER( knightsh02 )  /* Knights of the Round (Extreme Mode) */
	DRIVER( knightsh03 )  /* Knights of the Round (Random Characters, Items, Chaos Into Version V6-2) */
	DRIVER( knightsh04 )  /* Knights of the Round (Random Characters, Items, Chaos Into Version V6-3) */
	DRIVER( knightsh05 )  /* Knights of the Round (Round Table Samurai Chop Version 2015-09-14) */
	DRIVER( knightsh06 )  /* Knights of the Round (1V3 Unparalleled Edition 2016-02-17) */
	DRIVER( knightsh07 )  /* Knights of the Round (Select Players 3) */
	DRIVER( knightsh08 )  /* Knights of the Round (Super Plus 2016-08-26) */
	DRIVER( knightsh09 )  /* Knights of the Round (Tie Jia Ying Hao 1 Vs 3 Edition 2018-03-03) */
	DRIVER( knightsh10 )  /* Knights of the Round (Translation Chinese 2018-03-03) */
	DRIVER( knightsh11 )  /* Knights of the Round (Tie Jia Ying Hao 2) */
	DRIVER( knightsh12 )  /* Knights of the Round (Super Enhanced Latest Edition 2015-06-02) */
	DRIVER( knightsh13 )  /* Knights of the Round (Unknown Hack 2016-11-28) */
	DRIVER( knightsh14 )  /* Knights of the Round (Plus 2016-07-14) */
	DRIVER( knightsjs01 )  /* Knights of the Round (Translation Chinese) */
	
	// The King of Dragons
//	DRIVER( kodd )  /* The King of Dragons (World 910711 Phoenix Edition) */
	//DRIVER( kodh )  /* The King of Dragons (Bootleg)(ETC 910711) */
	DRIVER( kodsp )  /* The King of Dragons (Remix Special) */
//	DRIVER( kodud )  /* The King of Dragons (US 910910 Phoenix Edition (16b/40p) */
	DRIVER( koduhc01 )  /* The King of Dragons (Boss Battle Edition 2015-05-25) */
	DRIVER( koduhc02 )  /* The King of Dragons (3 Player Mode) */
	DRIVER( koduhc03 )  /* The King of Dragons (Boss Battle Edition 2015-05-24) */
	
	// Cadillacs and Dinosaurs
	DRIVER( dino08h2 )  /* Cadillacs and Dinosaurs (Enhanced Revision 2008 set 3 v2.0f 2008-10-17) */
	DRIVER( dino08h3 )  /* Cadillacs and Dinosaurs (Enhanced Revision 2008 set 1 v1.1 2008-10-11) */
	DRIVER( dino08hp )  /* Cadillacs and Dinosaurs (Enhanced Revision 2008 set 2 v1.1f 2008-10-17) */
	DRIVER( dinob )  /* Cadillacs and Dinosaurs (bootleg) */
	DRIVER( dinobt )  /* Cadillacs and Dinosaurs (BT hack version) */
	DRIVER( dinobtpp )  /* Cadillacs and Dinosaurs (All Weapons Ammunition Unlimited BT Version 2009-01-15) */
	DRIVER( dinocgba )  /* Cadillacs and Dinosaurs (Plus Version Rev.1) */
	DRIVER( dinocgbb )  /* Cadillacs and Dinosaurs (Plus Version Rev.2) */
	DRIVER( dinocgbc )  /* Cadillacs and Dinosaurs (Plus Version Rev.3) */
	DRIVER( dinoex )  /* Cadillacs and Dinosaurs (Unknown Hack 2014-06-18) */
	DRIVER( dinohp )  /* Cadillacs and Dinosaurs (Submachine gun and shotgun bullet version) */
	DRIVER( dinohx )  /* Cadillacs and Dinosaurs (Ex Super Version V2) */
	DRIVER( dinojp )  /* Cadillacs Kyouryuu-Shinseiki Plus (Double Edition 2010-03-10) */
	DRIVER( dinorp )  /* Cadillacs and Dinosaurs (Missile Embroidery Plus 2008-08-05) */
	DRIVER( dinoslice )  /* Cadillacs and Dinosaurs (Boss Improved Version 2014-10-04) */
	DRIVER( dinouphp )  /* Cadillacs and Dinosaurs (Lock Triple Mode 2009-1-15) */
	DRIVER( dinoz )  /* Cadillacs and Dinosaurs Z (Boss Hack) */
	DRIVER( dinos01 )  /* Cadillacs and Dinosaurs (Weapon Items Bazooka) */
	DRIVER( dinos02 )  /* Cadillacs and Dinosaurs (Weapon Items Club) */
	DRIVER( dinos03 )  /* Cadillacs and Dinosaurs (Weapon Items Dynamite or Grenade) */
	DRIVER( dinos04 )  /* Cadillacs and Dinosaurs (Weapon Items Dynamite) */
	DRIVER( dinos05 )  /* Cadillacs and Dinosaurs (Weapon Items Grenade) */
	DRIVER( dinos06 )  /* Cadillacs and Dinosaurs (Weapon Items Pistol) */
	DRIVER( dinos07 )  /* Cadillacs and Dinosaurs (Weapon Items Rifle/M-16A1) */
	DRIVER( dinos08 )  /* Cadillacs and Dinosaurs (Weapon Items Rod) */
	DRIVER( dinos09 )  /* Cadillacs and Dinosaurs (Weapon Items Shot Gun) */
	DRIVER( dinos10 )  /* Cadillacs and Dinosaurs (Weapon Items Uzi) */
	DRIVER( dinos11 )  /* Cadillacs and Dinosaurs (Bonus Items Ammonite) */
	DRIVER( dinos12 )  /* Cadillacs and Dinosaurs (Bonus Items Golddust) */
	DRIVER( dinos13 )  /* Cadillacs and Dinosaurs (Kill Enemies To Get Food Barbecue) */
	DRIVER( dinos14 )  /* Cadillacs and Dinosaurs (Kill Enemies To Get Food Cake) */
	DRIVER( dinos15 )  /* Cadillacs and Dinosaurs (Kill Enemies To Get Food Lobster) */
	DRIVER( dinos16 )  /* Cadillacs and Dinosaurs (Kill Enemies To Get Food Paffe) */
	DRIVER( dinos17 )  /* Cadillacs and Dinosaurs (Kill Enemies To Get Food Steak) */
	DRIVER( dinos18 )  /* Cadillacs and Dinosaurs (Kill Enemies To Get Food Sushi) */
	DRIVER( dinos19 )  /* Cadillacs and Dinosaurs (Put Insurance Can Not Afford To Lose Blood) */
	DRIVER( dinos20 )  /* Cadillacs and Dinosaurs (Weapons Unlimited + Does Not Disappear) */
	DRIVER( dinos21 )  /* Cadillacs and Dinosaurs (Tekken Invincible) */
	DRIVER( dinos22 )  /* Cadillacs and Dinosaurs (Change Char V2) */
	DRIVER( dinos23 )  /* Cadillacs and Dinosaurs (Enemy Replacement Edition 2010-03-10) */
	DRIVER( dinos24 )  /* Cadillacs and Dinosaurs (Integrated Repair-Blood Pro Plus Edition 2009-1-15/2011-03-31) */
	DRIVER( dinos25 )  /* Cadillacs and Dinosaurs (Unparalleled Multi-Boss Bloody Version) */
	DRIVER( dinos26 )  /* Cadillacs and Dinosaurs (Enhanced Revision 2008 2008-10-17) */
	DRIVER( dinos27 )  /* Cadillacs and Dinosaurs (Enhanced Modified Version 2008 v2.0f 2008-10-17) */
	DRIVER( dinos28 )  /* Cadillacs and Dinosaurs (Unparalleled Version Of The Revised Version Of 2011 2017-05-26) */
	DRIVER( dinos29 )  /* Cadillacs and Dinosaurs (Increase Enemy Enemy By Five Times 2016-01-10) */
	DRIVER( dinos30 )  /* Cadillacs and Dinosaurs (Self-Mutilation Blood 2011-03-23) */
	DRIVER( dinos31 )  /* Cadillacs and Dinosaurs (Bullet Unlimited Series-Pistol To Change The Gun Version v1.0) */
	DRIVER( dinos32 )  /* Cadillacs and Dinosaurs (Bullet Unlimited Series-Pistol To Change The Gun Version v2.0) */
	DRIVER( dinos33 )  /* Cadillacs and Dinosaurs (Bullet Unlimited Series-To The Rifle Version) */
	DRIVER( dinos34 )  /* Cadillacs and Dinosaurs (Bullet Unlimited Series-Shotgun Version) */
	DRIVER( dinos35 )  /* Cadillacs and Dinosaurs (Bullet Unlimited Series-Uz Assault Gun Version) */
	DRIVER( dinos36 )  /* Cadillacs and Dinosaurs (Bullet Unlimited Series-M-16A1 Edition) */
	DRIVER( dinos37 )  /* Cadillacs and Dinosaurs (Selection Time Is Not Reduced) */
	DRIVER( dinos38 )  /* Cadillacs and Dinosaurs (Ex Super Version V1) */
	DRIVER( dinos40 )  /* Cadillacs and Dinosaurs (Lock The Strongest Attack Power 2009-01-15) */
	DRIVER( dinos41 )  /* Cadillacs and Dinosaurs (Lock Three Mode 2009-01-15) */
	DRIVER( dinos42 )  /* Cadillacs and Dinosaurs (Shooting With The Footkl) */
	DRIVER( dinos43 )  /* Cadillacs and Dinosaurs Kyouryuu Shin Seiki (Battered Edition) */
	DRIVER( dinos44 )  /* Cadillacs and Dinosaurs (Cadillacs Kyouryuu-Shinseiki Plus 2010-02-10)) */
	DRIVER( dinos45 )  /* Cadillacs and Dinosaurs (Kill Enemies To Get Bonus Rev.1) */
	DRIVER( dinos46 )  /* Cadillacs and Dinosaurs (Kill Enemies To Get Bonus Rev.2) */
	DRIVER( dinos47 )  /* Cadillacs and Dinosaurs (Kill Enemies To Get Bonus Rev.3) */
	DRIVER( dinos48 )  /* Cadillacs and Dinosaurs (Kill Enemies To Get Bonus Rev.4) */
	DRIVER( dinos49 )  /* Cadillacs and Dinosaurs (Chaos x5) */
	DRIVER( dinos50 )  /* Cadillacs and Dinosaurs (Chaos x3) */
	DRIVER( dinos51 )  /* Cadillacs and Dinosaurs (Update Slice Version 2016-04-12) */
	DRIVER( dinos52 )  /* Cadillacs and Dinosaurs (Unknown Hack 2016-02-14) */
	DRIVER( dinos53 )  /* Cadillacs and Dinosaurs (Unknown Hack Fix 2016-02-14) */
	DRIVER( dinos54 )  /* Cadillacs and Dinosaurs (Bullet Unlimited Series-Bazooka) */
	DRIVER( dinos56 )  /* Cadillacs and Dinosaurs (Integral Repair-Blood Pro Plus Edition 2011-03-28) */
	DRIVER( dinos57 )  /* Cadillacs and Dinosaurs (Jurassic 99) */
	DRIVER( dinos59 )  /* Cadillacs and Dinosaurs (Final Boss) */
	DRIVER( dinos60 )  /* Cadillacs and Dinosaurs (2011 Plus New Version) */
	DRIVER( dinos61 )  /* Cadillacs and Dinosaurs (2011 Plus Bloody Warriors 2018 New Edition) */
	DRIVER( dinos62 )  /* Cadillacs and Dinosaurs (Phantom Musou Updated version 2017 2017-11-29) */
	DRIVER( dinos63 )  /* Cadillacs and Dinosaurs (Yong Chuang Tian Ya 2018) */
	DRIVER( dinos64 )  /* Cadillacs and Dinosaurs (Second Generation Extreme Edition 1 2017-12-16) */
	DRIVER( dinos65 )  /* Cadillacs and Dinosaurs (Second Generation Extreme Edition 2 2017-12-17) */
	DRIVER( dinos66 )  /* Cadillacs and Dinosaurs (Unknown Hack 2012-10-26) */
	DRIVER( dinos67 )  /* Cadillacs and Dinosaurs (Unknown Hack 2015-11-15) */
	DRIVER( dinos68 )  /* Cadillacs and Dinosaurs (Unknown Hack 2013-08-23) */
	DRIVER( dinos69 )  /* Cadillacs and Dinosaurs (Butcher's Wrath Final Edition Matchless Death 2017-11-23) */
	DRIVER( dinos70 )  /* Cadillacs and Dinosaurs 2011 Plus (2011 Mutual Final Crack Edition 2018-02-12) */
	DRIVER( dinos71 )  /* Cadillacs and Dinosaurs (Dou Shen Edition 2018 2018-05-14) */
	DRIVER( dinos72 )  /* Cadillacs and Dinosaurs (Di Yu Wu Shuang 2017-12-24) */
	DRIVER( dinos73 )  /* Cadillacs and Dinosaurs (99 Jurassic Plus 2017-11-13) */
	DRIVER( dinos74 )  /* Cadillacs and Dinosaurs (2018 Villain's Revenge 2017-12-31) */
	DRIVER( dinos75 )  /* Cadillacs and Dinosaurs (Qi Sha Edition) */
	DRIVER( dinos91 )  /* Cadillacs and Dinosaurs (Hacks Unknown 2018-03-09) */
	DRIVER( dinos92 )  /* Cadillacs and Dinosaurs (2011 Bloody Battle Unparalleled 2018-02-05) */
	DRIVER( dinos93 )  /* Cadillacs and Dinosaurs (Ogasa Version 2017-12-17) */
	DRIVER( dinos94 )  /* Cadillacs and Dinosaurs (Dewar Edition Update 2018-01-18) */
	DRIVER( dinos95 )  /* Cadillacs and Dinosaurs (Quick Warrior Edition Update 2018-01-16) */
	DRIVER( dinos96 )  /* Cadillacs and Dinosaurs (Boss Phantom Edition 2018-04-08) */
	DRIVER( dinos97 )  /* Cadillacs and Dinosaurs (Boss Phantom Edition 2018-04-02) */
	DRIVER( dinos98 )  /* Cadillacs and Dinosaurs (2017 Super Musou Update 2017-11-03) */
	DRIVER( dinos99 )  /* Cadillacs and Dinosaurs (Fighting Update 2017-11-03) */
	DRIVER( dinos100 )  /* Cadillacs and Dinosaurs (Boss Phantom Edition 2017-10-28) */
	DRIVER( dinos101 )  /* Cadillacs and Dinosaurs (Boss Phantom Edition 2017-10-30) */
	DRIVER( dinos102 )  /* Cadillacs and Dinosaurs (2017 Super Unparalleled Chaos 2017-11-12) */
	DRIVER( dinos103 )  /* Cadillacs and Dinosaurs (Zeng Xing X5 update 2017-11-08) */
	DRIVER( dinos104 )  /* Cadillacs and Dinosaurs (2011 Musou Update 2018 2017-12-14) */
	DRIVER( dinos105 )  /* Cadillacs and Dinosaurs (Second Generation Warriors 2017 2017-11-19) */
	DRIVER( dinos106 )  /* Cadillacs and Dinosaurs (99 Jurassic Enhanced 2017-12-16) */
	DRIVER( dinos107 )  /* Dinosaur Hunter (Burst Edition 2017-12-14) */
	DRIVER( dinos108 )  /* Cadillacs and Dinosaurs (Dewar Edition Update 2017-12-03) */
	DRIVER( dinos109 )  /* Cadillacs and Dinosaurs (2018 Villain Revenge 2017-12-14) */
	DRIVER( dinos110 )  /* Cadillacs and Dinosaurs (Second Generation Knight Edition 2017-11-19) */
	DRIVER( dinos111 )  /* Dinosaur Hunter (Challenge Edition 2017-11-16) */
	DRIVER( dinos112 )  /* Cadillacs and Dinosaurs (Quick Warrior Edition Update 2017-11-19) */
	DRIVER( dinos113 )  /* Cadillacs and Dinosaurs (Okami Ue rion 2017-12-12) */
	DRIVER( dinos114 )  /* Cadillacs and Dinosaurs (Dewar Edition Update 2017-12-25) */
	DRIVER( dinos115 )  /* Cadillacs and Dinosaurs (2018 Warrior Summoning Edition 2018-01-18) */
	DRIVER( dinos116 )  /* Cadillacs and Dinosaurs (97 Second Generation Speed Edition 2 2017-12-17) */
	DRIVER( dinos117 )  /* Cadillacs and Dinosaurs (2018 Globe Trekker 2017-12-31) */
	DRIVER( dinos118 )  /* Cadillacs and Dinosaurs (Quick Warrior Edition Update 2017-12-18) */
	DRIVER( dinos119 )  /* Cadillacs and Dinosaurs (The Warriors Edition 2017 Update 2017-04-18) */
	DRIVER( dinos120 )  /* Cadillacs and Dinosaurs (Quick Warrior Edition Update 2018-04-02) */
	DRIVER( dinos121 )  /* Cadillacs and Dinosaurs (The Warriors Edition 2017 Update 2017-06-07) */
	DRIVER( dinos122 )  /* Cadillacs and Dinosaurs (2015 Matchless 2017-09-09) */
	DRIVER( dinos123 )  /* Cadillacs and Dinosaurs (1VS3 Enhanced Version 2017-08-21) */
	DRIVER( dinos124 )  /* Cadillacs and Dinosaurs (Faster Version 2017 2017-07-15) */
	DRIVER( dinos125 )  /* Cadillacs and Dinosaurs (2017 Matchless Bullets 2017-09-02) */
	DRIVER( dinos126 )  /* Cadillacs and Dinosaurs (Beat 2017 Bloodless 2017-09-15) */
	DRIVER( dinos127 )  /* Cadillacs and Dinosaurs (The Beatless Hit Cool Version 2017 2017-09-17) */
	DRIVER( dinos128 )  /* Cadillacs and Dinosaurs (The Warriors Edition 2017 Update 2017-09-12) */
	DRIVER( dinos129 )  /* Cadillacs and Dinosaurs (The Military Commander 2018 2018-03-21) */
	DRIVER( dinos130 )  /* Cadillacs and Dinosaurs (Quick Warrior Edition Update 2018-02-13) */
	DRIVER( dinos131 )  /* Cadillacs and Dinosaurs (Fighting Update 2018-07-02) */
	DRIVER( dinos132 )  /* Cadillacs and Dinosaurs (Fast Fighting Update 2018-07-25) */
	DRIVER( dinos133 )  /* Cadillacs and Dinosaurs (Ruan Bu Wu Shuang 2018 2018-06-17) */
	DRIVER( dinos134 )  /* Cadillacs and Dinosaurs (Dead Time Permanent Effective 2018-01-18) */
	DRIVER( dinos135 )  /* Cadillacs and Dinosaurs (Second Generation Extreme Edition) */
	DRIVER( dinos136 )  /* Cadillacs and Dinosaurs (Iron Dragon 2018-07-31) */
	DRIVER( dinos137 )  /* Cadillacs and Dinosaurs (Hit Anywhere) */
	DRIVER( dinos138 )  /* Cadillacs and Dinosaurs (Press Button Call Out Weapon) */
	DRIVER( dinos139 )  /* Cadillacs and Dinosaurs (Quick Go Next Stage 2018-08-23) */
	DRIVER( dinos140 )  /* Cadillacs and Dinosaurs (Stage Select) */
	DRIVER( dinos141 )  /* Cadillacs and Dinosaurs (Fast Moving, Continuous, Unparalleled 2018-08-13) */
	DRIVER( dinos142 )  /* Cadillacs and Dinosaurs (Fast Fight Blood Battle Version 2018 Tour Version 2018-06-11) */
	DRIVER( dinos143 )  /* Cadillacs and Dinosaurs (Xue Zhan Edition 2018-10-25) */
	DRIVER( dinos144 )  /* Cadillacs and Dinosaurs (Dinosaur New Century 2016-01-26) */
	DRIVER( dinos145 )  /* Cadillacs and Dinosaurs (2017 Unparalleled Strike 2017-04-17) */
	DRIVER( dinos146 )  /* Cadillacs and Dinosaurs (Multi Boss 2017-04-06) */
	DRIVER( dinos147 )  /* Cadillacs and Dinosaurs (Happiness 2017 Unparalleled Edition 2017-10-24) */
	DRIVER( dinos148 )  /* Cadillacs and Dinosaurs (Quick Warrior Edition 2017-10-14) */
	DRIVER( dinos149 )  /* Cadillacs and Dinosaurs (Quickly Increased Edition X3 2017-10-30) */
	DRIVER( dinos150 )  /* Cadillacs and Dinosaurs (Unparalleled Bullet Enhanced 2017 2017-11-04) */
	DRIVER( dinos151 )  /* Cadillacs and Dinosaurs (Unparalleled Bloody Plus 2017 2017-10-25) */
	DRIVER( dinos152 )  /* Cadillacs and Dinosaurs (Dewar Edition 2017-08-17) */
	DRIVER( dinos153 )  /* Cadillacs and Dinosaurs (Fight, No Bloody, Enhanced Version, Japanese Version 2017 2017-08-02) */
	DRIVER( dinos154 )  /* Cadillacs and Dinosaurs (Speed Enhanced Version 2017 2017-10-16) */
	DRIVER( dinos155 )  /* Cadillacs and Dinosaurs (The 2017 Unparalleled Chaos 2017-11-10) */
	DRIVER( dinos156 )  /* Cadillacs and Dinosaurs (Second Generation Warriors 2017 2017-11-12) */
	DRIVER( dinos157 )  /* Cadillacs and Dinosaurs (Snow Version 2018-01-23) */
	DRIVER( dinos158 )  /* Cadillacs and Dinosaurs (Ghost Crying Godless Peerless Version 2018-01-18) */
	DRIVER( dinos159 )  /* Cadillacs and Dinosaurs (Chaos unparalleled 2018-08-16) */
	DRIVER( dinos160 )  /* Cadillacs and Dinosaurs (Fighting Update 2018-08-23) */
	DRIVER( dinos161 )  /* Cadillacs and Dinosaurs (Military version Update 2018-08-13) */
	DRIVER( dinos162 )  /* Cadillacs and Dinosaurs (Fast Increase Zeng Xing X5 2017-10-31) */
	DRIVER( dinos163 )  /* Cadillacs and Dinosaurs (Bloody update 2011-07-22) */
	DRIVER( dinos164 )  /* Cadillacs and Dinosaurs (2017 Super Musou Update 2017-10-26) */
	DRIVER( dinos165 )  /* Cadillacs and Dinosaurs (2017 Super Unparalleled Version 2017-10-17) */
	DRIVER( dinos166 )  /* Cadillacs and Dinosaurs (2017 Super Unparalleled Final Version 2017-11-02) */
	DRIVER( dinos167 )  /* Cadillacs and Dinosaurs (Ji 2011 2017-05-21) */
	DRIVER( dinos168 )  /* Cadillacs and Dinosaurs (Heaven And Earth Unparalleled 2011 2017-06-07) */
	DRIVER( dinos169 )  /* Cadillacs and Dinosaurs (Playing Uranus Edition 2018-09-27) */
	DRIVER( dinos170 )  /* Cadillacs and Dinosaurs (Fighting Update 2018-09-27) */
	DRIVER( dinos171 )  /* Cadillacs and Dinosaurs (Fight bloody version Update 2018-09-19) */
	DRIVER( dinos172 )  /* Cadillacs and Dinosaurs (Military version Update 2018-09-24) */
	DRIVER( dinos173 )  /* Cadillacs and Dinosaurs (Hit the king version 2018-10-30) */
	DRIVER( dinos174 )  /* Cadillacs and Dinosaurs (Fighting Update 2018-10-30) */
	DRIVER( dinos175 )  /* Cadillacs and Dinosaurs (playing Uranus Edition Update 2018-12-29) */
	DRIVER( dinos176 )  /* Cadillacs and Dinosaurs (God of War Edition Update 2018-12-22) */
	DRIVER( dinos177 )  /* Cadillacs and Dinosaurs (Fast Fighting Version Update 2018-12-29) */
	DRIVER( dinos178 )  /* Cadillacs and Dinosaurs (Playing Uranus version 2019-01-29) */
	DRIVER( dinos179 )  /* Cadillacs and Dinosaurs (The Warriors Edition Update 2018-12-21) */
	DRIVER( dinos180 )  /* Cadillacs and Dinosaurs (Fighting God Version 2019-01-14) */
	DRIVER( dinos181 )  /* Cadillacs and Dinosaurs (Arena Version 2019-01-23) */
	DRIVER( dinos182 )  /* Cadillacs and Dinosaurs (Sky King 2019-01-14) */
	DRIVER( dinos183 )  /* Cadillacs and Dinosaurs (God of War Update 2019-01-19) */
	DRIVER( dinos184 )  /* Cadillacs and Dinosaurs (Majin Ranbu 2019-01-17) */
	DRIVER( dinos185 )  /* Cadillacs and Dinosaurs (Unrivalled Version 2019 2019-01-07) */
	DRIVER( dinos186 )  /* Cadillacs and Dinosaurs (The Warriors Edition Update 2019-04-15) */
	DRIVER( dinos187 )  /* Cadillacs and Dinosaurs (God of War Update 2019-04-15) */
	DRIVER( dinos188 )  /* Cadillacs and Dinosaurs (Playing Competitive Version 2019-04-15) */
	DRIVER( dinos189 )  /* Cadillacs and Dinosaurs (The 2011 Musou Version 2019-04-15) */
	DRIVER( dinos190 )  /* Cadillacs and Dinosaurs (The king Version 2019-04-15) */
	DRIVER( dinos191 )  /* Cadillacs and Dinosaurs (Fast Fighting version Update 2019-04-15) */
	DRIVER( dinos192 )  /* Cadillacs and Dinosaurs (God of War Update 2019-05-30) */
	DRIVER( dinos193 )  /* Cadillacs and Dinosaurs (Group Demon Dance Version 2019-05-30) */

	// The Punisher
	DRIVER( punisherf )  /* The Punisher (Flash version 2007-09-24) */
	DRIVER( punisherje1 )  /* The Punisher (SM Experience Edition 2009-06-12) */
	DRIVER( punisherjh )  /* The Punisher (Ex Super version) */
	DRIVER( punisherjh1 )  /* The Punisher (Lock double mode + Unlimited Use Of Pistols 2009-06-08) */
	DRIVER( punisherjha )  /* The Punisher (Perverted Abuse Version) */
	DRIVER( punisherud1 )  /* The Punisher (US 930422 Phoenix Edition (8b/32p)) */
	DRIVER( punisherud2 )  /* The Punisher (US 930422 Phoenix Edition (16b/40p)) */
	DRIVER( punishers01 )  /* The Punisher (1 Vs 2 Perfect Update 2018-03-30) */
	DRIVER( punishers02 )  /* The Punisher (1 Vs 2 Perfect Update 2018-01-05) */
	DRIVER( punishers03 )  /* The Punisher (1 Vs 2 Perfect Update 2017-12-17) */
	DRIVER( punishers04 )  /* The Punisher (1 Vs 2 Perfect Update 2018-04-11) */
	DRIVER( punishers05 )  /* The Punisher (1 Vs 2 Perfect Update 2018-03-26) */
	DRIVER( punishers06 )  /* The Punisher (Unparalleled Fast Fight 2017-12-13) */
	DRIVER( punishers07 )  /* The Punisher (Unknown Hack 2019-05-30) */
	DRIVER( punisherjs01 )  /* The Punisher (Time No Decrease) */
	DRIVER( punisherjs02 )  /* The Punisher (100 Second For Every Scene 2017-12-26) */
	DRIVER( punisherjs03 )  /* The Punisher (1V2 Unparalleled Version 2016-02-18) */
	DRIVER( punisherjs04 )  /* The Punisher (Unknown Hack 2016-02-18) */
	DRIVER( punisherjs05 )  /* The Punisher (Lock double mode) */
	DRIVER( punisherjs06 )  /* The Punisher (Unlimited use of pistols) */
	DRIVER( punisherjs07 )  /* The Punisher (Button To Take Gun Unloading Gun 2009-06-09) */
	DRIVER( punisherjs08 )  /* The Punisher (Angry Boms 2011.07.31) */
	DRIVER( punisherjs09 )  /* The Punisher (Unparalleled Version 2017-11-02) */
	DRIVER( punisherjs10 )  /* The Punisher (Enhanced Version 0 2014-12-23) */
	DRIVER( punisherjs11 )  /* The Punisher (Enhanced Version 1 2014-12-26) */
	DRIVER( punisherjs12 )  /* The Punisher (Enhanced Version 2 2014-12-27) */
	DRIVER( punisherjs13 )  /* The Punisher (Strengthens Second Edition 2014-12-24) */
	DRIVER( punisherjs14 )  /* The Punisher (The fourth edition of V2 2014-12-30) */
	DRIVER( punisherjs15 )  /* The Punisher (1 Vs 2 Perfect Update 2019-05-30) */
	DRIVER( punisherjs16 )  /* The Punisher (Unknown Hack 2019) */
	DRIVER( punisherjs17 )  /* The Punisher (Unparalleled Version 2019-05-30) */
	
	// Muscle Bomber Duo: Ultimate Team Battle
	DRIVER( mbombrds01 )  /* Muscle Bomber Duo: Ultimate Team Battle (Region Asia Version) */
	DRIVER( mbombrds02 )  /* Muscle Bomber Duo: Ultimate Team Battle (Region Hispanic Version) */
	DRIVER( mbombrds03 )  /* Muscle Bomber Duo: Ultimate Team Battle (Region Japan Version) */
	DRIVER( mbombrds04 )  /* Muscle Bomber Duo: Ultimate Team Battle (Region Usa Version) */
	
	// Saturday Night Slam Masters
	DRIVER( slammastud )  /* Saturday Night Slam Masters (USA 930713 Phoenix Edition) */
	DRIVER( slammasts01 )  /* Saturday Night Slam Masters (Region Asia Version) */
	DRIVER( slammasts02 )  /* Saturday Night Slam Masters (Region Asia Version (Buggy)) */
	DRIVER( slammasts03 )  /* Saturday Night Slam Masters (Region Hispanic Version) */
	DRIVER( slammasts04 )  /* Saturday Night Slam Masters (Region Hispanic Version (Buggy)) */
	DRIVER( slammasts05 )  /* Saturday Night Slam Masters (Easy Move) */

	// Street Fighter II
	DRIVER( sf2bhj )  /* Street Fighter II - The World Warrior (Boss hack) */
	DRIVER( sf2c )  /* Street Fighter II - The World Warrior (Chinese 911210) */
	DRIVER( sf2ced )  /* Street Fighter II' - Champion Edition (Sheng Long Hack v7.1) */
	DRIVER( sf2ceda )  /* Street Fighter II' - Champion Edition (Unknown Hack) */
	DRIVER( sf2cehp )  /* Street Fighter II' - Champion Edition (Moves hack 2009-01-10) */
	DRIVER( sf2cejem )  /* Street Fighter II' - Champion Edition (Easy Moves 2009-07-30) */
	DRIVER( sf2jbh )  /* Street Fighter II - The World Warrior (Edition Plus 2014) */
	DRIVER( sf2koryuh )  /* Street Fighter II' - Champion Edition (Koryu) */
	DRIVER( sf2h9 )  /* Street Fighter II' - Champion Edition (bootleg set 2, 920313 etc) */
	DRIVER( sf2h10 )  /* Street Fighter II' - Champion Edition (Alpha Magic-F bootleg set 4, 920313 etc) */
	DRIVER( sf2h11 )  /* Street Fighter II' - Champion Edition (920322 Japan bootleg set 1) */
	DRIVER( sf2h12 )  /* Street Fighter II' - Champion Edition (Rainbow bootleg set 5, 920322 Japan) */
	DRIVER( sf2h13 )  /* Street Fighter II' Turbo - Hyper Fighting (bootleg set 1, 921209 Japan) */
	DRIVER( sf2pun )  /* Street Fighter II' - Champion Edition (Punishment Simplified Edition v1 Final 2012-04-10) */
	//DRIVER( sf2sl73a )  /* Street Fighter II' - Champion Edition (Sheng Long v7.3a) */
	DRIVER( sf2th )  /* Street Fighter II' - Champion Edition (Turbo set 1, bootleg) */
	DRIVER( sf2tha )  /* Street Fighter II' - Champion Edition (Turbo set 2, bootleg) */
	//DRIVER( sf2tlona )  /* Street Fighter II' - Champion Edition (Tu Long bootleg set 1, 811102 001) */
	//DRIVER( sf2tlonb )  /* Street Fighter II' - Champion Edition (Tu Long bootleg set 2, 811102 001) */
	//DRIVER( sf2tlonc )  /* Street Fighter II' - Champion Edition (Tu Long bootleg set 3, 811102 001) */
	DRIVER( sf2turyu )  /* Street Fighter II' - Champion Edition (Tu Long prototype) */
	DRIVER( sf2yyc3d5 )  /* Street Fighter II' - Champion Edition (Red Wave bootleg set 2, 920313 etc) */
	DRIVER( sf2yyc3g )  /* Street Fighter II' - Champion Edition (V004 bootleg set 2, 920313 etc) */
	DRIVER( sf2yyc6 )  /* Street Fighter II' - Champion Edition (YYC bootleg set 2, 920313 etc) */
	DRIVER( sf2ces01 )	/* Street Fighter II' - Champion Edition (Translation Brasil) */
	DRIVER( sf2ces02 )  /* Street Fighter II' - Champion Edition (Translation Hispanic) */
	DRIVER( sf2ces03 )  /* Street Fighter II' - Champion Edition (Do Not Force) */
	DRIVER( sf2ces04 )  /* Street Fighter II' - Champion Edition (Sangigel's Whirlwind To Sit Simplified) */
	DRIVER( sf2ces05 )  /* Street Fighter II' - Champion Edition (Vega Lifts The Main Scene Crawl Limit) */
	DRIVER( sf2ces06 )  /* Street Fighter II' - Champion Edition (Super Plus Teleportation) */
	DRIVER( sf2ces07 )  /* Street Fighter II' - Champion Edition (Turbo Balrog Storm) */
	DRIVER( sf2ces08 )  /* Street Fighter II' - Champion Edition (Galactic Super Vega) */
	DRIVER( sf2ces09 )  /* Street Fighter II' - Champion Edition (Insane Edition) */
	DRIVER( sf2ces10 )  /* Street Fighter II' - Champion Edition (Brazil 920313/hack) */
	//DRIVER( sf2ces11 )  /* Street Fighter II' - Champion Edition (M16, bootleg) */
	DRIVER( sf2ces12 )  /* Street Fighter II' - Champion Edition (Hispanic 990804/hack) */
	DRIVER( sf2js01 )  /* Street Fighter II - The World Warrior (King Of The Four Heavenly Kings) */
	DRIVER( sf2js02 )  /* Street Fighter II - The World Warrior (12 Person Version 2016-01-01) */
	DRIVER( sf2s01 )  /* Street Fighter II - The World Warrior (Cancellation Of Force) */
	DRIVER( sf2s02 )  /* Street Fighter II - The World Warrior (Hacks Unknown 2014-03-24) */
	DRIVER( sf2s03 )  /* Street Fighter II - The World Warrior (Easy Move) */
	DRIVER( sf2s04 )  /* Street Fighter II - The World Warrior (Hit Any Where) */
	DRIVER( sf2s05 )  /* Street Fighter II - The World Warrior (Magic Throw) */
	DRIVER( sf2koryus01 )  /* Street Fighter II' - Champion Edition (Huaping Repair) */
	DRIVER( sf2koryus02 )  /* Street Fighter II' - Champion Edition - Xiang Long (Chinese bootleg  set 3) */
	DRIVER( sf2koryus03 )  /* Street Fighter II' - Champion Edition - Xiang Long (Chinese bootleg  set 4) */
	DRIVER( sf2tlonas01 )  /* Street Fighter II' - Champion Edition (Replacement Blank Screen Repair) */
	DRIVER( sf2tlonas02 )  /* Street Fighter II' - Champion Edition (Zangief Spiral Piling Instructions Simplify 2012-01-1X) */
	DRIVER( sf2tlonas03 )  /* Street Fighter II' - Champion Edition (Zangief Spiral Piling Instructions Simplify 2012-01-15) */
	DRIVER( sf2tlonas04 )  /* Street Fighter II' - Champion Edition (Hack Unknown 2015-11-01) */
	DRIVER( sf2hfus01 )  /* Street Fighter II' - Hyper Fighting (Deceleration) */
	DRIVER( sf2hfus02 )  /* Street Fighter II' - Hyper Fighting (Shorten the time 60% ) */
	DRIVER( sf2hfus03 )  /* Street Fighter II' - Hyper Fighting (Guile Shorten the time 1 90% ) */
	DRIVER( sf2hfus04 )  /* Street Fighter II' - Hyper Fighting (Guile Shorten the time 2 90% ) */
	DRIVER( sf2h11s01 )  /* Street Fighter II' - Champion Edition (920322 Japan bootleg set 2) */
	DRIVER( sf2puns01 )  /* Street Fighter II' - Champion Edition (Punishment Edition Simplified 2018-06-26) */
	DRIVER( sf2reds01 )  /* Street Fighter II' - Champion Edition (Golden Edition) */
	DRIVER( sf2reds02 )  /* Street Fighter II' - Champion Edition (Hardest Level) */
	DRIVER( sf2reds03 )  /* Street Fighter II' - Champion Edition (Ultra Golden Edition) */
	DRIVER( sf2reds04 )  /* Street Fighter II' - Champion Edition (Golden Edition Easy Move) */
	
	// Pnickies
	DRIVER( pnicku )  /* Pnickies (This Edition Is Just A Regional USA Version) */
	
	// Street Fighter Zero
	DRIVER( sfzchs01 )  /* Street Fighter Zero (CPS Changer - Street Fighter Alpha - Warriors' Dreams) */
	DRIVER( sfzchs02 )  /* Street Fighter Zero (Move Hack 2007-02-11) */
	DRIVER( sfzchs03 )  /* Street Fighter Zero (CPS Changer, Asia 950925) */
	DRIVER( sfzchs04 )  /* Street Fighter Zero (CPS Changer, Euro 950727) */
	DRIVER( sfzchs05 )  /* Street Fighter Zero (CPS Changer, Hispanic 950727) */
	DRIVER( sfzchs06 )  /* Street Fighter Zero (CPS Changer, Brazil 950727 hack) */
	
	// Sangokushi II
	DRIVER( sk2h12 )  /* Sangokushi II (set H12) */
	DRIVER( sk2h13 )  /* Sangokushi II (set H13) */
	DRIVER( sk2h14 )  /* Sangokushi II (Chinese Translation 2017-04-26) */
	DRIVER( sk2h16 )  /* Sangokushi II (Easy Moves 2009-01-12) */
	DRIVER( sk3p1 )  /* Sangokushi 3 Gaiden Kakou-on's Revenge DX 2010 (Red) */
	DRIVER( sk3p2 )  /* Sangokushi 3 Gaiden Kakou-on's Revenge DX 2010 (Green set 1) */
	DRIVER( sk3p3 )  /* Sangokushi 3 Gaiden Kakou-on's Revenge DX 2010 2015-06-12) */
	DRIVER( tk2c1 )  /* Tenchi wo Kurau II (Boss Enhanced) */
	DRIVER( tk2c2 )  /* Tenchi wo Kurau II (Kassar(Chou-Hi)'s Kusanagi kick) */
	DRIVER( tk2c3 )  /* Tenchi wo Kurau II (Kadan (Kou-Chuu)'s Kusanagi arrow) */
	DRIVER( tk2c4 )  /* Tenchi wo Kurau II (Di Yu Enhanced Enemies) */
	DRIVER( tk2c5 )  /* Tenchi wo Kurau II (Di Yi Guan Enhanced) */
	DRIVER( tk2c6 )  /* Tenchi wo Kurau II (Fen Hong Enhanced)(Pink Version) */
	DRIVER( tk2c7 )  /* Tenchi wo Kurau II (Portor(Kan-U)'s Horseback energy attack with flaming arrow effect) */
	DRIVER( tk2c8 )  /* Tenchi wo Kurau II (Portor(Kan-U)'s Horseback energy attack with blue flaming arrow effect) */
	DRIVER( tk2c9 )  /* Tenchi wo Kurau II (Horseback energy attack with blue Sonic Blade effect) */
	DRIVER( tk2c10 )  /* Tenchi wo Kurau II (Enhanced Kadan (Kou-Chuu)) */
	DRIVER( tk2c11 )  /* Tenchi wo Kurau II (Bloody Plus V1.50) */
	DRIVER( tk2c12 )  /* Tenchi wo Kurau II (Enhanced energy attack) */
	DRIVER( tk2c13 )  /* Tenchi wo Kurau II (Mei ren Guan Enhanced) */
	DRIVER( tk2c14 )  /* Tenchi wo Kurau II (Weapon attack with multiple fire-like effect) */
	DRIVER( tk2c15 )  /* Tenchi wo Kurau II (Super sword & energy v3) */
	DRIVER( tk2c16 )  /* Tenchi wo Kurau II (Shao Zhu Enhanced Roast pork) */
	DRIVER( tk2c17 )  /* Tenchi wo Kurau II (Throwing Axes Plus) */
	DRIVER( tk2c18 )  /* Tenchi wo Kurau II (Ying Xiong Guan Enhanced) */
	DRIVER( tk2c19 )  /* Tenchi wo Kurau II (Zhao Huan Shou Enhanced)(Conjured beast) */
	DRIVER( tk2c20 )  /* Tenchi wo Kurau II (Zhao Huan Shou + Yu Jian Shu Enhanced)(Swordplay & Summoning) */
	DRIVER( tk2c21 )  /* Tenchi wo Kurau II (Enhanced Subutai (Chou-Un)'s kick) */
	DRIVER( tk2c22 )  /* Tenchi wo Kurau II (Enhanced Subutai (Chou-Un)'s uppercut) */
	DRIVER( tk2c23 )  /* Tenchi wo Kurau II (Violent Subutai (Chou-Un)) */
	DRIVER( tk2h1 )  /* Tenchi wo Kurau II (Jianqi version) */
	DRIVER( tk2h2 )  /* Tenchi wo Kurau II (Kusanagi horse) */
	DRIVER( tk2h3 )  /* Tenchi wo Kurau II (Hack set 3) */
	DRIVER( tk2h4 )  /* Tenchi wo Kurau II (Replacement version of the enemy) */
	DRIVER( tk2h5 )  /* Tenchi wo Kurau II (Edition Chinese) */
	DRIVER( tk2h6 )  /* Tenchi wo Kurau II (Phoenix Edition) */
	DRIVER( tk2h7 )  /* Tenchi wo Kurau II (Group modified version 2008-01-02) */
	DRIVER( tk2h8 )  /* Tenchi wo Kurau II (Heaven and Earth Double Attack Test Version 2009-12-14) */
	DRIVER( tk2h9 )  /* Tenchi wo Kurau II (Easy Tornado Sitting Second Edition 2009-01-12) */
	DRIVER( tk2h10 )  /* Tenchi wo Kurau II (Sanmei Spiral Counterattack Beta 1.03 2013-12-26) */
	DRIVER( tk2h11 )  /* Tenchi wo Kurau II (Change Character 2010-01-26) */
	DRIVER( tk2h12 )  /* Tenchi wo Kurau II (Playstation Version 2019-01-13) */
	DRIVER( tk2h13 )  /* Tenchi wo Kurau II (Modified Time 2009-12-17) */
	DRIVER( tk2h14 )  /* Tenchi wo Kurau II (Zhao Yun dregs version 2009-03-21) */
	DRIVER( tk2h17 )  /* Tenchi wo Kurau II (Zhao Chain Revised v1.0 2009-12-16) */
	DRIVER( tk2h18 )  /* Tenchi wo Kurau II (Power edition) */
	DRIVER( tk2p44 )  /* Tenchi wo Kurau II (Lock Triple Mode) */
	DRIVER( tk2p45 )  /* Tenchi wo Kurau II (Imitation Sword Invincible Version 2010-01-29) */
	DRIVER( woffr )  /* Warriors of Fate (French Translation 2003-07-28) */
	//DRIVER( wofsf2 )  /* Warriors of Fate (conversion for SF2 HW) */
	DRIVER( wofud )  /* Warriors of Fate (USA 921031 Phoenix Edition) */
	DRIVER( tk2h19 )  /* Tenchi wo Kurau II (Max Power) */
	DRIVER( tk2h20 )  /* Tenchi wo Kurau II (Residual of Zhao Yun) */
	DRIVER( tk2h21 )  /* Tenchi wo Kurau II (Optional Lidian Second Edition) */
	DRIVER( tk2h23 )  /* Tenchi wo Kurau II (Super sword & energy v2) */
	DRIVER( tk2h24 )  /* Tenchi wo Kurau II (Easy Spinning Pile Driver) */
	DRIVER( tk2h25 )  /* Tenchi wo Kurau II (Battle of Chibi - Holy Sword (version 3 invincible)) */
	DRIVER( tk2h26 )  /* Tenchi wo Kurau II (Subdue the Dragon) */
	DRIVER( tk2h27 )  /* Tenchi wo Kurau II (Bloody Plus)(Ver.?) */
	DRIVER( tk2h28 )  /* Tenchi wo Kurau II (Bloody Plus V1.40) */
	DRIVER( tk2h29 )  /* Tenchi wo Kurau II (Perverted Version) */
	DRIVER( tk2h30 )  /* Tenchi wo Kurau II (Holly Sword Three Kingdoms Invincible) */
	DRIVER( tk2h31 )  /* Tenchi wo Kurau II (Unknown Hack Rev.1) */
	DRIVER( tk2h32 )  /* Tenchi wo Kurau II (The Battle Of Chibi - The True Of Warriors 2016-02-27) */
	DRIVER( tk2h33 )  /* Tenchi wo Kurau II (Unknown Hack Rev.2) */
	DRIVER( tk2h35 )  /* Tenchi wo Kurau II (Unknown Hack Rev.3) */
	DRIVER( tk2h37 )  /* Tenchi wo Kurau II (Boss Cho Unparalleled Edition 2016-03-01) */
	DRIVER( tk2h38 )  /* Tenchi wo Kurau II (Boss Cho Unparalleled Edition 2016-02-28) */
	DRIVER( tk2h39 )  /* Tenchi wo Kurau II (Boss Cho Unparalleled Edition 2016-02-27) */
	DRIVER( tk2h40 )  /* Tenchi wo Kurau II (Chibi Battle 2016 Real World Unparalleled 2016-03-04) */
	DRIVER( tk2h41 )  /* Tenchi wo Kurau II (Sanmei Wushuang 2016-02-27) */
	DRIVER( tk2h42 )  /* Tenchi wo Kurau II (Lu Bu Wushuang 2016-03-01) */
	DRIVER( tk2h43 )  /* Tenchi wo Kurau II (Super Sword-Energy V1) */
	DRIVER( tk2h44 )  /* Tenchi wo Kurau II (Japanese Version Of The World Turn) */
	DRIVER( tk2h45 )  /* Tenchi wo Kurau II (Lock Three-Person Model First Edition) */
	DRIVER( tk2h46 )  /* Tenchi wo Kurau II (Lock Three People Model Perfect Version) */
	DRIVER( tk2h47 )  /* Tenchi wo Kurau II (Player's Anger) */
	DRIVER( tk2h48 )  /* Tenchi wo Kurau II (Angry Upgrade) */
	DRIVER( tk2h49 )  /* Tenchi wo Kurau II (Zhao Yun Strengthened) */
	DRIVER( tk2h53 )  /* Tenchi wo Kurau II (Hell Difficulty Version) */
	DRIVER( tk2h54 )  /* Tenchi wo Kurau II (Double Edition) */
	DRIVER( tk2h55 )  /* Tenchi wo Kurau II (Warriors Version 2) */
	DRIVER( tk2h56 )  /* Tenchi wo Kurau II (Final Attack) */
	DRIVER( tk2h57 )  /* Tenchi wo Kurau II (Better Dragon Punch) */
	DRIVER( tk2h58 )  /* Tenchi wo Kurau II (Zhang Fei Uppercut Fist 2013-05-23) */
	DRIVER( tk2h59 )  /* Tenchi wo Kurau II (Enhanced Subutai (Chou-Un)) */
	DRIVER( tk2h60 )  /* Tenchi wo Kurau II (Series Of Legs Modified Version 1.0) */
	DRIVER( tk2h61 )  /* Tenchi wo Kurau II (Kassar - Spinning Pile Driver (A) 2013-03-12) */
	DRIVER( tk2h62 )  /* Tenchi wo Kurau II (Kassar - Spinning Pile Driver (+A) 2013-03-12) */
	DRIVER( tk2h63 )  /* Tenchi wo Kurau II (Kassar - Spinning Pile Driver (-A) 2013-03-12) */
	DRIVER( tk2h64 )  /* Tenchi wo Kurau II (Kassar - Viper Halberd - Spinning Pile Driver 2013-03-12) */
	DRIVER( tk2h65 )  /* Tenchi wo Kurau II (Kassar - Grabbing - Spinning Pile Driver 2013-03-12) */
	DRIVER( tk2h66 )  /* Tenchi wo Kurau II (Kassar - Unlimited Spinning Pile Driver 2013-03-12) */
	DRIVER( tk2h67 )  /* Tenchi wo Kurau II (Zhang Fei Horse Battle To Strengthen The First Edition 2011-10-26) */
	DRIVER( tk2h68 )  /* Tenchi wo Kurau II (Zhang Fei Horse Battle To Strengthen The Second Edition 2012-01-01) */
	DRIVER( tk2h69 )  /* Tenchi wo Kurau II (Kassar (Chou-Hi)'s Kicking Hack 2011-11-01) */
	DRIVER( tk2h70 )  /* Tenchi wo Kurau II (Guan Yu Began To Move Out of Buttons 2011-10-28) */
	DRIVER( tk2h71 )  /* Tenchi wo Kurau II (Guan Yu - Screw Pile (Cyclone Sit) 2013-08-08) */
	DRIVER( tk2h72 )  /* Tenchi wo Kurau II (Zhao Wei Direct Use Of Weapons In Hand) */
	DRIVER( tk2h73 )  /* Tenchi wo Kurau II (Horseback Energy Attack With Blue Sonic Blade Effect (A)) */
	DRIVER( tk2h74 )  /* Tenchi wo Kurau II (Horseback Energy Attack With Blue Sonic Blade Effect (B)) */
	DRIVER( tk2h75 )  /* Tenchi wo Kurau II (Horseback Energy Attack With Blue Sonic Blade Effect (C)) */
	DRIVER( tk2h76 )  /* Tenchi wo Kurau II (Boss Words) */
	DRIVER( tk2h77 )  /* Tenchi wo Kurau II (Double The Attack Power)(2013-09-30) */
	DRIVER( tk2h78 )  /* Tenchi wo Kurau II (Start Key Riding) */
	DRIVER( tk2h79 )  /* Tenchi wo Kurau II (Sword And arrow Fly) */
	DRIVER( tk2h80 )  /* Tenchi wo Kurau II (Kassar (Chou-Hi)'s Kusanagi kick) */
	DRIVER( tk2h81 )  /* Tenchi wo Kurau II (Enhanced Portor (Kan-U)) */
	DRIVER( tk2h82 )  /* Tenchi wo Kurau II (Kusanagi Horse)(Ver.?) */
	DRIVER( tk2h83 )  /* Tenchi wo Kurau II (The First Pass In The World) */
	DRIVER( tk2h84 )  /* Tenchi wo Kurau II (Portor (Kan-U)'s Horseback Energy Attack With Flaming Arrow Effect) */
	DRIVER( tk2h85 )  /* Tenchi wo Kurau II (Beauty Stage) */
	DRIVER( tk2h86 )  /* Tenchi wo Kurau II (Hero Stage) */
	DRIVER( tk2h87 )  /* Tenchi wo Kurau II (Five Tiger Insurance Out Of Lu Bu Zhang Liao Aura) */
	DRIVER( tk2h88 )  /* Tenchi wo Kurau II (Weapons That Are Hit By The Enemy Or Dropped From The AB key Will Not Disappear) */
	DRIVER( tk2h89 )  /* Tenchi wo Kurau II (Optional Lidian First Edition) */
	DRIVER( tk2h90 )  /* Tenchi wo Kurau II (Optional Lidian Basic Edition) */
	DRIVER( tk2h91 )  /* Tenchi wo Kurau II (Cao Ren Single Extended Version) */
	DRIVER( tk2h92 )  /* Tenchi wo Kurau II (Cao Ren Expansion Single Version Small Correction (Color)) */
	DRIVER( tk2h93 )  /* Tenchi wo Kurau II (Cao Ren Move The Full Version) */
	DRIVER( tk2h94 )  /* Tenchi wo Kurau II (Super Sword) */
	DRIVER( tk2h95 )  /* Tenchi wo Kurau II (Super Enhanced Integrated Version) */
	DRIVER( tk2h96 )  /* Tenchi wo Kurau II (Variant Metamorphosis Edition) */
	DRIVER( tk2h97 )  /* Tenchi wo Kurau II (The Above Modification Adds Invincible Effect) */
	DRIVER( tk2h98 )  /* Tenchi wo Kurau II (Title Screen Modification) */
	DRIVER( tk2h99 )  /* Tenchi wo Kurau II (Zhang Fei Vampire Version 2010-11-12) */
	DRIVER( tk2h100 )  /* Tenchi wo Kurau II (Unlimited Time)(Battle Scenes Only) */
	DRIVER( tk2h101 )  /* Tenchi wo Kurau II (Wolf Edition 2017-12-23) */
	DRIVER( tk2h102 )  /* Tenchi wo Kurau II (San Jian Sheng Super Edition Update 2018-02-10) */
	DRIVER( tk2h103 )  /* Tenchi wo Kurau II (Lidian) */
	DRIVER( tk2h104 )  /* Tenchi wo Kurau II (Boss Cho Unparalleled Edition 2016-02-26) */
	DRIVER( tk2h105 )  /* Tenchi wo Kurau II (Boss Cho Unparalleled Edition 2016-02-25) */
	DRIVER( tk2h106 )  /* Tenchi wo Kurau II (Zhao Wei) */
	DRIVER( tk2h107 )  /* Tenchi wo Kurau II (San Mei Wu Shuang 2017) */
	DRIVER( tk2h108 )  /* Tenchi wo Kurau II (Warriors of Fate Plus 2 2018) */
	DRIVER( tk2h109 )  /* Tenchi wo Kurau II (San Mei Wu Shuang 2018) */
	DRIVER( tk2h110 )  /* Tenchi wo Kurau II (Da Ren Edition) */
	DRIVER( tk2h111 )  /* Tenchi wo Kurau II (Basic Attack With Throwing Axes, Special Horseback Energy Attack)(2004-11-12) */
	DRIVER( tk2h112 )  /* Tenchi wo Kurau II (Beauty Stage)(Ordinary Roms) */
	DRIVER( tk2h113 )  /* Tenchi wo Kurau II (Hero Stage)(Ordinary Roms) */
	DRIVER( tk2h114 )  /* Tenchi wo Kurau II (Ma Zhan Wu Shuang 2018-06-03) */
	DRIVER( tk2h115 )  /* Tenchi wo Kurau II (Xia Hou Dun Plus) */
	DRIVER( tk2h116 )  /* Tenchi wo Kurau II (No Pairs Enhanced 2018 2014-07-18) */
	DRIVER( tk2h118 )  /* Tenchi wo Kurau II (Three Boss Edition 2017-11-03) */
	DRIVER( tk2h119 )  /* Tenchi wo Kurau II (Iron Needle Edition 2016-09-13) */
	DRIVER( tk2h120 )  /* Tenchi wo Kurau II (Daren Edition Update 2018-02-23) */
	DRIVER( tk2h121 )  /* Tenchi wo Kurau II (Eight Difficult V3) */
	DRIVER( tk2h122 )  /* Tenchi wo Kurau II (Daren Edition Update 2018-06-08) */
	DRIVER( tk2h123 )  /* Tenchi wo Kurau II (Li Dian Da Ren Edition 2018-06-02) */
	DRIVER( tk2h124 )  /* Tenchi wo Kurau II (Xu Zhu Edition 2018 2018-08-03) */
	DRIVER( tk2h125 )  /* Tenchi wo Kurau II (San Jian Sheng Super Edition Update 2019-07-07) */
	DRIVER( tk2h126 )  /* Tenchi wo Kurau II (Master Edition 2018-09-19) */
	DRIVER( tk2h127 )  /* Tenchi wo Kurau II (Master Version 2019-01-20) */
	DRIVER( tk2h128 )  /* Tenchi wo Kurau II (Full Attack Enhanced Version) */
	DRIVER( tk2h129 )  /* Tenchi wo Kurau II (Full Screen Attack Sanmei Wushuang version 2017-03-02) */
	DRIVER( tk2h130 )  /* Tenchi wo Kurau II (San Jian Sheng Super Edition Update 2018-02-02) */
	DRIVER( tk2h131 )  /* Tenchi wo Kurau II (Master Edition 2018-07-27) */
	DRIVER( tk2h132 )  /* Tenchi wo Kurau II (Master Edition 2018-08-17) */
	DRIVER( tk2h133 )  /* Tenchi wo Kurau II (Daren Edition Update 2018-12-15) */
	DRIVER( tk2h134 )  /* Tenchi wo Kurau II (Daren Edition Update 2019-01-12) */
	DRIVER( tk2h135 )  /* Tenchi wo Kurau II (Daren Edition Update 2019-02-16) */
	DRIVER( tk2h136 )  /* Tenchi wo Kurau II (Daren Edition Update 2019-02-21) */
	DRIVER( tk2h137 )  /* Tenchi wo Kurau II (War On Horseback 2017-11-20) */
	DRIVER( tk2h138 )  /* Tenchi wo Kurau II (Daren Edition Update 2019-04-15) */
	DRIVER( tk2h139 )  /* Tenchi wo Kurau II (Three US Edition 1v3 2019-05-01) */
	DRIVER( tk2p02 )  /* Tenchi wo Kurau II (Boss Rush) */
	DRIVER( tk2p03 )  /* Tenchi wo Kurau II (Boss Rush Extreme 2018-06-18) */
	DRIVER( tk2p04 )  /* Tenchi wo Kurau II (Mode Plus) */
	DRIVER( tk2p05 )  /* Tenchi wo Kurau II (A key to enter the mode) */
	DRIVER( tk2p07 )  /* Tenchi wo Kurau II (True Purgatory Edition) */
	DRIVER( tk2p08 )  /* Tenchi wo Kurau II (Open Mode) */
	DRIVER( tk2p09 )  /* Tenchi wo Kurau II (Skull And Grass) */
	DRIVER( tk2p10 )  /* Tenchi wo Kurau II (Sangokushi III Gaiden: Kakou-on's Revenge) */
	DRIVER( tk2p11 )  /* Tenchi wo Kurau II (Sangokushi III Gaiden: Kakou-on's Revenge DX) */
	DRIVER( tk2p12 )  /* Tenchi wo Kurau II (Sangokushi III Part 2) */
	DRIVER( tk2p13 )  /* Tenchi wo Kurau II (Sangokushi III Gaiden: Kakou-on's Revenge)(Alt) */
	DRIVER( tk2p14 )  /* Tenchi wo Kurau II (Zhao Yunsheng Long Edition) */
	DRIVER( tk2p15 )  /* Tenchi wo Kurau II (Zhang Feiwu 2010-08-21) */
	DRIVER( tk2p18 )  /* Tenchi wo Kurau II (Zhang Fei Moves To Simplify) */
	DRIVER( tk2p19 )  /* Tenchi wo Kurau II (Extra Mode ON 2013-03-19) */
	DRIVER( tk2p20 )  /* Tenchi wo Kurau II (Easy Control-Kassar-Super Spinning Pile Driver (A) 2013-03-19) */
	DRIVER( tk2p21 )  /* Tenchi wo Kurau II (Kassar-Super Spinning Pile Driver (+A) 2013-03-19) */
	DRIVER( tk2p22 )  /* Tenchi wo Kurau II (Kassar-Super Spinning Pile Driver (-A) 2013-03-19) */
	DRIVER( tk2p23 )  /* Tenchi wo Kurau II (Kassar-Viper Halberd-Super Spinning Pile Driver 2013-03-19) */
	DRIVER( tk2p24 )  /* Tenchi wo Kurau II (Kassar-Grabbing-Super Spinning Pile Driver 2013-03-19) */
	DRIVER( tk2p25 )  /* Tenchi wo Kurau II (Kassar-Midair Grabbing Simplified 2013-03-19) */
	DRIVER( tk2p26 )  /* Tenchi wo Kurau II (Kassar-Unlimited Super Spinning Pile Driver 2013-03-19) */
	DRIVER( tk2p27 )  /* Tenchi wo Kurau II (Guan Yu's Big Move Improved) */
	DRIVER( tk2p28 )  /* Tenchi wo Kurau II (Wei Yan Ordinary Drop Cancellation) */
	DRIVER( tk2p29 )  /* Tenchi wo Kurau II (Wei Yan Empty Into A Big Seat) */
	DRIVER( tk2p30 )  /* Tenchi wo Kurau II (Open Space To Strengthen The First Edition) */
	DRIVER( tk2p31 )  /* Tenchi wo Kurau II (Open space Enhanced Second Edition) */
	DRIVER( tk2p33 )  /* Tenchi wo Kurau II (Zhao Yun Sheng Long Lie broke) */
	DRIVER( tk2p34 )  /* Tenchi wo Kurau II (Add Kassar's Super Punch) */
	DRIVER( tk2p36 )  /* Tenchi wo Kurau II (Boss Rush Extreme 2018-06-14) */
	DRIVER( tk2p37 )  /* Tenchi wo Kurau II (Many Boss 2018-06-13) */
	DRIVER( tk2p38 )  /* Tenchi wo Kurau II (Kakou-on's Revenge-Prologue) */
	DRIVER( tk2p39 )  /* Tenchi wo Kurau II (Zhang Fei Vampire Edition V2 2010-11-12) */
	DRIVER( tk2p41 )  /* Tenchi wo Kurau II (Enhanced mode) */
	DRIVER( tk2p42 )  /* Tenchi wo Kurau II (Many Boss 2018-06-14) */
	DRIVER( tk2p43 )  /* Tenchi wo Kurau II (Juggernauts) */
	DRIVER( sk2h17 )  /* Sangokushi II (Holly Sword Three Kingdoms) */
	DRIVER( sk2h18 )  /* Sangokushi II (Enhanced Attack Power) */
	DRIVER( sk2h23 )  /* Sangokushi II (Three Sword Masters) */
	DRIVER( sk2h45 )  /* Sangokushi II (Kakou-on's revenge 2017 full attack 2017-04-03) */
	DRIVER( sk3p4 )  /* Sangokushi 3 Gaiden Kakou-on's Revence Dx 2010 (Set 01) */
	DRIVER( sk3p5 )  /* Sangokushi 3 Kakou-on's second set of revenge Rev.3 2016-02-28) */
	DRIVER( sk3p6 )  /* Sangokushi 3 Kakou-on's second set of revenge Rev.2 2016-02-28) */
	DRIVER( sk3p7 )  /* Sangokushi 3 Gaiden Kakou-on's Revence Dx 2010 (Set 04) */
	DRIVER( sk3p8 )  /* Sangokushi 3 Gaiden Kakou-on's Revence Dx 2010 (Set 05) */
	DRIVER( sk3p9 )  /* Sangokushi 3 Kakou-on's second set of revenge 2018 2018-01-12) */
	DRIVER( sk3p10 )  /* Sangokushi 3 Kakou-on's second set of revenge Rev.1 2016-02-28) */
	DRIVER( wofs00 )  /* Warriors of Fate (Easy Kassar's Spinning Pile Driver. Fire, Foods And Swords Anywhere)(Happy Version) */
	DRIVER( wofs01 )  /* Warriors of Fate (Boss Cho Unparalleled Edition 2016-03-02) */
	DRIVER( wofs02 )  /* Warriors of Fate (Combination key To Take Grass Blade Sword) */
	DRIVER( wofs03 )  /* Warriors of Fate (Holy Sword Three Kingdoms Invincible 2017-12-26) */
	DRIVER( wofs04 )  /* Warriors of Fate (Zhang Fei Vampires First Edition 2010-11-12) */
	DRIVER( wofs05 )  /* Warriors of Fate (Unique Sword Armour 2019-01-13) */
	DRIVER( wofs06 )  /* Warriors of Fate (Not Automatically Abandoned Sword) */
	DRIVER( wofs07 )  /* Warriors of Fate (Optimized Version Of The Move) */
	DRIVER( wofs08 )  /* Warriors of Fate (Zhang Fei vampire Second Edition) */
	
	/* *************************************** */
	/* Part 8 - NEOGEO HACKS FROM HBMAME 0.210 */
	/* *************************************** */

	/* KOF97 HACKS */	
	DRIVER( kof97aa )  /* KOF'97 (#2 Athena Plus Version)(NGM-2320) */
	DRIVER( kof97ae )  /* KOF'97 10TH ANNIVERSARY (set 1)(NGM-2320) */
	DRIVER( kof97ae1 )  /* KOF'97 10TH ANNIVERSARY (set 2)(NGM-2320) */
	DRIVER( kof97aot )  /* KOF'97 (AOT)(NGM-2320) */
	DRIVER( kof97bh )  /* KOF'97 (Add Char - Orochi icon - Extra stage select)(NGM-2320) */
	DRIVER( kof97bng )  /* KOF'97 (Combo 2006)(set 1)(NGM-2320) */
	DRIVER( kof97bs )  /* KOF'97 (Boss Hack)(NGM-2320) */
	DRIVER( kof97cb2 )  /* KOF'97 (Combo 2006)(set 2)(NGM-2320) */
	DRIVER( kof97cr )  /* KOF'97 (Moves and Style changed - Extra stage select)(NGM-2320) */
	DRIVER( kof97chl )  /* KOF'97 (Diff Moves - 030325)(NGM-2320) */
	DRIVER( kof97chl2 )  /* KOF'97 (Diff Moves rev.2 - 030409)(NGM-2320) */
	DRIVER( kof97chris )  /* KOF'97 (Optimized version)(2013.05.29)(NGM-2320) */
	DRIVER( kof97co )  /* KOF'97 (Combo 2010-02-07)(NGM-2320) */
	DRIVER( kof97co6 )  /* KOF'97 (Combo 2006)(NGM-2320) */
	DRIVER( kof97cy )  /* KOF'97 (Through)(NGM-2320) */
	DRIVER( kof97dse )  /* KOF'97 (2013.06.10) [GOTVG](NGM-2320) */
	DRIVER( kof97eh )  /* KOF'97 (Add Char - Ultra kill start max in Adv Mode - Ultra pow hack ABC - Extra stage select)(NGM-2320) */
	DRIVER( kof97eh2 )  /* KOF'97 (Add Char - Ultra kill start max in Adv Mode - Pow hack ABC - Extra stage select)(NGM-2320) */
	DRIVER( kof97eho )  /* KOF'97 (Add Char - Ultra kill start max in Adv Mode - Pow hack ABC)(NGM-2320) */
	DRIVER( kof97ei )  /* KOF'97 (Combo 2010-02-07) (EI)(NGM-2320) */
	DRIVER( kof97evo )  /* KOF'97 (#2 Evolution New Hack)(NGM-2320) */
	DRIVER( kof97evoa )  /* KOF'97 Evolution (Old)(NGM-2320) */
	DRIVER( kof97frb )  /* KOF'97 (FRB)(NGM-2320) */
	DRIVER( kof97hk )  /* KOF'97 Evolution (Hakeshu)(NGM-2320) */
	DRIVER( kof97hl )  /* KOF'97 (Drop dragon version)(NGM-2320) */
	DRIVER( kof97hxd )  /* KOF'97 (Add Char)(NGM-2320) */
	DRIVER( kof97ice )  /* KOF'97 (Icy blue style v2)(NGM-2320) */
	DRIVER( kof97irgc )  /* KOF'97 (IRGC)(NGM-2320) */
	DRIVER( kof97irgc2 )  /* KOF'97 (IRGC2)(NGM-2320) */
	DRIVER( kof97kai )  /* KOF'97 (Plus)(Alt)(NGM-2320) */
	DRIVER( kof97kp )  /* KOF'97 (Enable 1 hidden character)(Orochi)(NGM-2320) */
	DRIVER( kof97kp1 )  /* KOF'97 (KP 2000)(NGM-2320) */
	DRIVER( kof97lb )  /* KOF'97 (Quanhuang Shaman 3.0)(NGM-2320) */
	DRIVER( kof97lc )  /* KOF'97 (Valentine's Day and Red fire)(NGM-2320) */
	DRIVER( kof97lr )  /* KOF'97 (Lover Red)(NGM-2320) */
	DRIVER( kof97m )  /* KOF'97 (2012.06.28)(NGM-2320) */
	DRIVER( kof97mit )  /* KOF'97 (Char style enhanced 050324)(NGM-2320) */
	DRIVER( kof97mj )  /* KOF'97 (Shion Edition)(NGM-2320) */
	DRIVER( kof97nd )  /* KOF'97 (Baidu)(NGM-2320) */
	DRIVER( kof97ne )  /* KOF'97 (Remixed)(NGM-2320) */
	DRIVER( kof97neo )  /* KOF'97 (Neo Charity Team)(NGM-2320) */
	DRIVER( kof97nude )  /* KOF'97 (Nude)(NGM-2320) */
	DRIVER( kof97pj )  /* KOF'97 (hxd fixed ver - Add Char)(NGM-2320) */
	DRIVER( kof97pjc )  /* KOF'97 (Color Version V1)(NGM-2320) */
	DRIVER( kof97phl )  /* KOF'97 Plus (Hack unknown)(NGM-2320) */
	DRIVER( kof97pl2 )  /* KOF'97 (Plus)(set 2)(NGM-2320) */
	DRIVER( kof97pl3 )  /* KOF'97 (Plus)(set 3)(NGM-2320) */
	DRIVER( kof97plc )  /* KOF'97 Plus (Black Edition)(NGM-2320) */
	DRIVER( kof97plus )  /* KOF'97 (Plus 2006)(NGM-2320) */
	DRIVER( kof97pm )  /* KOF'97 (Practice Mode)(NGM-2320) */
	DRIVER( kof97ps )  /* KOF'97 (Playstation)(New)(NGM-2320) */
	DRIVER( kof97rev )  /* KOF'97 (The Revival 2016)(NGM-2320) */
	DRIVER( kof97ribe )  /* KOF'97 Plus (RIBE)(NGM-2320) */
	DRIVER( kof97rk )  /* KOF'97 (Hack unknown)(NGM-2320) */
	DRIVER( kof97rst )  /* KOF'97 Plus (RST)(NGM-2320) */
	DRIVER( kof97rst2 )  /* KOF'97 Plus (RST2)(NGM-2320) */
	DRIVER( kof97rst3 )  /* KOF'97 Plus (RISK012003)(NGM-2320) */
	DRIVER( kof97rv )  /* KOF'97 (revised edition)(NGM-2320) */
	DRIVER( kof97saw )  /* KOF'97 (Kill red flame special effect)(NGM-2320) */
	DRIVER( kof97sex )  /* KOF'97 (Sexy Edition)(NGM-2320) */
	DRIVER( kof97shi )  /* KOF'97 (Evolution Shin Edition)(NGM-2320) */
	DRIVER( kof97sm )  /* KOF'97 (Colorful version v1.5)(Alt)(NGM-2320) */
	DRIVER( kof97svs )  /* KOF'97 (SVS)(NGM-2320) */
	DRIVER( kof97svsb2 )  /* KOF'97 (SVSB2)(NGM-2320) */
	DRIVER( kof97sw )  /* KOF'97 (26a-c and 623a-c red flame special effect)(NGM-2320) */
	DRIVER( kof97tse )  /* KOF'97 (TSE)(NGM-2320) */
	DRIVER( kof97wh )  /* KOF'97 (Style Kyo to 95' Kyo)(NGM-2320) */
	DRIVER( kof97wpls )  /* KOF'97 Plus (NGM-2320) */
	DRIVER( kof97xbt )  /* KOF'97 (BT X Version)(NGM-2320) */
	DRIVER( kof97xi )  /* KOF'97 (XI Flash Version)(NGM-2320) */
	DRIVER( kof97xp )  /* KOF'97 (Xuhui plus)(NGM-2320) */
	DRIVER( kof97xt1 )  /* KOF'97 (Unfinished version)(NGM-2320) */
	DRIVER( kof97xxx )  /* KOF'97 (Nude mix)(NGM-2320) */
	DRIVER( kof97y )  /* KOF'97 (Enable 5 hidden characters)(NGM-2320) */
	DRIVER( kof97ya )  /* KOF'97 (Add Orochi set 1)(NGM-2320) */
	DRIVER( kof97yb )  /* KOF'97 (Add Orochi set 2)(NGM-2320) */
	DRIVER( kof97ye )  /* KOF'97 (Add Char - no Orochi - Pow hack ABC in Extra Mode set 1)(NGM-2320) */
	DRIVER( kof97yg )  /* KOF'97 (Add Char - Pow hack ABC in Extra Mode)(NGM-2320) */
	DRIVER( kof97yh )  /* KOF'97 (Add Char - no Orochi - Pow hack ABC in Extra Mode set 2)(NGM-2320) */
	DRIVER( kof97yk )  /* KOF'97 (Yukimura Hack YK)(NGM-2320) */
	DRIVER( kof97yk1 )  /* KOF'97 (World Buwu 0.083)(2008-01-01)(NGM-2320) */
	DRIVER( kof97yk2 )  /* KOF'97 (Yukimura Hack YK2)(NGM-2320) */
	DRIVER( kof97yk83 )  /* KOF'97 (Yukimura Hack YK83)(NGM-2320) */
	DRIVER( kof97yk85 )  /* KOF'97 (Yukimura Hack YK85)(NGM-2320) */
	DRIVER( kof97yl )  /* KOF'97 (Add Char - Extra stage select set 1)(NGM-2320) */
	DRIVER( kof97yl2 )  /* KOF'97 (Add Char - Extra stage select set 2)(NGM-2320) */
	DRIVER( kof97yo )  /* KOF'97 (Seven Yoga Community Imitation 98)(NGM-2320) */
	DRIVER( kof97z )  /* KOF'97 (Hack unknown)(Alt)(NGM-2320) */
	DRIVER( kof97zm )  /* KOF'97 (ZMonanger)(NGM-2320) */
	DRIVER( kof97s01 )  /* KOF'97 (Boss PS Special Blue Version)(NGM-2320) */
	DRIVER( kof97s02 )  /* KOF'97 (Dragon Edition 7.0)(NGM-2320) */
	DRIVER( kof97s03 )  /* KOF'97 (Dragon Edition 6.0)(NGM-2320) */
	DRIVER( kof97s04 )  /* KOF'97 (Version Mixs T.Chino)(NGM-2320) */
	DRIVER( kof97s06 )  /* KOF'97 (Hyper Plus)(NGM-2320) */
	DRIVER( kof97s07 )  /* KOF'97 (Final Battle 1997)(Alt)(NGM-2320) */
	DRIVER( kof97s08 )  /* KOF'97 (Magic Fking)(NGM-2320) */
	DRIVER( kof97s09 )  /* KOF'97 (Translation Korean (Plus))(NGM-2320) */
	DRIVER( kof97s10 )  /* KOF'97 (Kof on Kalcetin)(2011-04-18)(NGM-2320) */
	DRIVER( kof97s11 )  /* KOF'97 (Plus Quanhuang Shaman V2.0)(NGM-2320) */
	DRIVER( kof97s12 )  /* KOF'97 (Plus 2009 (MHT))(NGM-2320) */
	DRIVER( kof97s13 )  /* KOF'97 (Blue Remix Plus Edition )(NGM-2320) */
	DRIVER( kof97s14 )  /* KOF'97 (Perfect Edition)(NGM-2320) */
	DRIVER( kof97s15 )  /* KOF'97 (Smoke Version V1.5)(NGM-2320) */
	DRIVER( kof97s16 )  /* KOF'97 (Edition Royal)(Set 01)(NGM-2320) */
	DRIVER( kof97s17 )  /* KOF'97 (Chinese Battle Plus 2003)(NGM-2320) */
	DRIVER( kof97s18 )  /* KOF'97 (Netizen The work of the crispy SP)(NGM-2320) */
	DRIVER( kof97s19 )  /* KOF'97 (Description Of Hack Unknown)(Set 05)(NGM-2320) */
	DRIVER( kof97s20 )  /* KOF'97 (SVS)(Alt)(NGM-2320) */
	DRIVER( kof97s21 )  /* KOF'97 (Description Of Hack Unknown)(Set 06)(NGM-2320) */
	DRIVER( kof97s22 )  /* KOF'97 (Edition Royal)(Set 2)(NGM-2320) */
	DRIVER( kof97s23 )  /* KOF'97 (Evolution)(2008-12-19)(NGM-2320) */
	DRIVER( kof97s24 )  /* KOF'97 (Devastating Match)(NGM-2320) */
	DRIVER( kof97s25 )  /* KOF'97 (Unlimited Company)(2010-02-07)(NGM-2320) */
	DRIVER( kof97s26 )  /* KOF'97 (Super Edition)(NGM-2320) */
	DRIVER( kof97s27 )  /* KOF'97 (Color Hack)(NGM-2320) */
	DRIVER( kof97s28 )  /* KOF'97 (KOF vs SF2)(NGM-2320) */
	DRIVER( kof97s29 )  /* KOF'97 (10th Anniversary)(NGM-2320) */
	DRIVER( kof97s30 )  /* KOF'97 (Mitologia)(NGM-2320) */
	DRIVER( kof97s31 )  /* KOF'97 (Rush Hits Extreme)(NGM-2320) */
	DRIVER( kof97s32 )  /* KOF'97 (Yukimura Edition v0.085)(NGM-2320) */
	DRIVER( kof97s33 )  /* KOF'97 (Super Edition Plus 1)(NGM-2320) */
	DRIVER( kof97s34 )  /* KOF'97 (Super Edition Plus 2)(NGM-2320) */
	DRIVER( kof97s35 )  /* KOF'97 (Old Chen Wave Boxing)(NGM-2320) */
	DRIVER( kof97s36 )  /* KOF'97 (Evolution New Revision)(Ver.?)(NGM-2320) */
	DRIVER( kof97s37 )  /* KOF'97 (Evolutionary Balance)(Ver.?)(NGM-2320) */
	DRIVER( kof97s38 )  /* KOF'97 (Super metamorphosis version)(Ver.?)(NGM-2320) */
	DRIVER( kof97s39 )  /* KOF'97 (Heavenly Protoss)(Ver.?)(NGM-2320) */
	DRIVER( kof97s40 )  /* KOF'97 (Dragon Super Plus)(Ver.?)(NGM-2320) */
	DRIVER( kof97s61 )  /* KOF'97 (Ge Xin Edition)(NGM-2320) */
	DRIVER( kof97s62 )  /* KOF'97 (Tu She Edition)(NGM-2320) */
	DRIVER( kof97s63 )  /* KOF'97 (Combo version)(Ver.?)(NGM-2320) */
	DRIVER( kof97s64 )  /* KOF'97 (Plus 2017)(Ver.?)(NGM-2320) */
	DRIVER( kof97s65 )  /* KOF'97 (Plus Battle Of The Strong)(Ver.?)(NGM-2320) */
	DRIVER( kof97s66 )  /* KOF'97 (The 11Th Anniversary)(Set 01)(Ver.?)(NGM-2320) */
	DRIVER( kof97s67 )  /* KOF'97 (The 11Th Anniversary)(Set 02)(Ver.?)(NGM-2320) */
	DRIVER( kof97s68 )  /* KOF'97 (No Unknown Original 1)(NGM-2320) */
	DRIVER( kof97s69 )  /* KOF'97 (No Unknown Original 2)(NGM-2320) */
	DRIVER( kof97s70 )  /* KOF'97 (Revolutionary Version)(NGM-2320) */
	DRIVER( kof97s71 )  /* KOF'97 (Evil Demons Dance Plus)(NGM-2320) */
	DRIVER( kof97s72 )  /* KOF'97 (Description Of Hack Unknown)(2012.06.28) [GOTVG](NGM-2320) */
	DRIVER( kof97s73 )  /* KOF'97 (Description Of Hack Unknown)[GOTVG](NGM-2320) */
	DRIVER( kof97s74 )  /* KOF'97 (Super Edition Plus 3)(NGM-2320) */
	DRIVER( kof97s75 )  /* KOF'97 (Clone Zero Modified Version)(Fat Lianhua + Even Strokes + Big Snake Green Sunshine Two  First Free, Went To The Fan Slap Small Bug To Be Repaired))(NGM-2320) */
	DRIVER( kof97h01 )  /* KOF'97 (Rush Hits)(NGM-2320) */
	DRIVER( kof97h02 )  /* KOF'97 (Unfinished Colors Revision)(NGM-2320) */
	DRIVER( kof97h03 )  /* KOF'97 (Golden Blood Version)(NGM-2320) */
	DRIVER( kof97h04 )  /* KOF'97 (Rainbow Style set 1)(NGM-2320) */
	DRIVER( kof97h05 )  /* KOF'97 (Sound Effect Revision)(NGM-2320) */
	DRIVER( kof97h06 )  /* KOF'97 (Unknown Hack)(NGM-2320) */
	DRIVER( kof97h07 )  /* KOF'97 (BT Version X Set 1)(NGM-2320) */
	DRIVER( kof97h08 )  /* KOF'97 (Yukimura Hack 2008-01-27)(NGM-2320) */
	DRIVER( kof97h09 )  /* KOF'97 (BT X Version)(Set 02)(NGM-2320) */
	DRIVER( kof97h10 )  /* KOF'97 (SVS)(Ver.?)(Set 03)(NGM-2320) */
	DRIVER( kof97h11 )  /* KOF'97 (Hack Unknown)(?)(NGM-2320) */
	DRIVER( kof97h12 )  /* KOF'97 (crosses 2 Update Original)(NGM-2320) */
	DRIVER( kof97h13 )  /* KOF'97 (Zero's Intrusion)(NGM-2320) */
	DRIVER( kof97h14 )  /* KOF'97 (windbreaker Another Iory Eight God Original)(NGM-2320) */
	DRIVER( kof97h15 )  /* KOF'97 (SvS Crystal Vercion)(Set 3)(NGM-2320) */
	DRIVER( kof97h16 )  /* KOF'97 (3 Question Version)(NGM-2320) */
	DRIVER( kof97h17 )  /* KOF'97 (SVS)(Ver.2013)(NGM-2320) */
	DRIVER( kof97hx01 )  /* KOF'97 (Attack Finished)(2005-08-27)(NGM-2320) */
	DRIVER( kof97hx02 )  /* KOF'97 (Translation Korean)(NGM-2320) */
	DRIVER( kof97hx03 )  /* KOF'97 (#1 Athena Modified)(NGM-2320) */
	DRIVER( kof97hx04 )  /* KOF'97 (#1 Evolution)(2008-03-02)(NGM-2320) */
	DRIVER( kof97hx05 )  /* KOF'97 (Three Artifact Version)(NGM-2320) */
	DRIVER( kof97hx06 )  /* KOF'97 (Household Coin Is Not Reduced)(NGM-2320) */
	DRIVER( kof97hx07 )  /* KOF'97 (Household Coin Full)(NGM-2320) */
	DRIVER( kof97hx08 )  /* KOF'97 (Combo 2007 - 10th Anniversary)(NGM-2320) */
	DRIVER( kof97hx09 )  /* KOF'97 (#2 EVO New Hack (Alt))(NGM-2320) */
	DRIVER( kof97hx10 )  /* KOF'97 (Evolution)(NGM-2320) */
	DRIVER( kof97hx11 )  /* KOF'97 (EX Mode Plus)(NGM-2320) */
	DRIVER( kof97hx12 )  /* KOF'97 (Plus 2003 (Alt))(NGM-2320) */
	DRIVER( kof97hx13 )  /* KOF'97 (Enhanced Version)(NGM-2320) */
	DRIVER( kof97hx14 )  /* KOF'97 (Fix V3)(NGM-2320) */
	DRIVER( kof97hx15 )  /* KOF'97 (Proton Version Ver 2.0)(NGM-2320) */
	DRIVER( kof97hx16 )  /* KOF'97 (Proton Version Ver 3.0)(NGM-2320) */
	DRIVER( kof97hx17 )  /* KOF'97 (Proton Version Ver 4.0)(NGM-2320) */
	DRIVER( kof97hx18 )  /* KOF'97 (Proton Version Ver 4A.0)(NGM-2320) */
	DRIVER( kof97hx19 )  /* KOF'97 (Always Level 8)(NGM-2320) */
	DRIVER( kof97hx20 )  /* KOF'97 (2011.07.09)(NGM-2320) */
	DRIVER( kof97hx21 )  /* KOF'97 (2011.08.06)(NGM-2320) */
	DRIVER( kof97hx22 )  /* KOF'97 (2011.09.18)(NGM-2320) */
	DRIVER( kof97hx23 )  /* KOF'97 (2011.10.22)(NGM-2320) */
	DRIVER( kof97hx24 )  /* KOF'97 (2011.12.27)(NGM-2320) */
	DRIVER( kof97hx25 )  /* KOF'97 (2012.02.12)(NGM-2320) */
	DRIVER( kof97hx26 )  /* KOF'97 (2012.08.31)(NGM-2320) */
	DRIVER( kof97hx27 )  /* KOF'97 (2013.01.06 (AI Plus))(NGM-2320) */
	DRIVER( kof97hx28 )  /* KOF'97 Plus (Alt)(?)(NGM-2320) */
	DRIVER( kof97hx29 )  /* KOF'97 Plus (Hack 2003)(NGM-2320) */
	DRIVER( kof97hx30 )  /* KOF'97 (Arcade Fix 1)(NGM-2320) */
	DRIVER( kof97hx31 )  /* KOF'97 (Fix Orochi)(NGM-2320) */
	DRIVER( kof97hx32 )  /* KOF'97 (Overall Change P2)(NGM-2320) */
	DRIVER( kof97hx33 )  /* KOF'97 (Combat Time Extended To 99)(NGM-2320) */
	DRIVER( kof97hx34 )  /* KOF'97 (Select The Extension Of Time)(NGM-2320) */
	DRIVER( kof97hx35 )  /* KOF'97 (Add Orochi's Portrait (S1 version))(2004-05-23)(NGM-2320) */
	DRIVER( kof97hx36 )  /* KOF'97 (Add Orochi's portrait (C1 C2 version))(2005-02-23)(NGM-2320) */
	DRIVER( kof97hx37 )  /* KOF'97 (Add Orochi's portrait (C1 C2 version)(Hack ?))(2005-02-23)(NGM-2320) */
	DRIVER( kof97hx38 )  /* KOF'97 (Add Orochi's portrait (C5 C6 version))(NGM-2320) */
	DRIVER( kof97hx39 )  /* KOF'97 (Replace Orochi's Portrait To Old Style)(NGM-2320) */
	DRIVER( kof97hx40 )  /* KOF'97 (Replace Orochi's portrait To PS Style)(NGM-2320) */
	DRIVER( kof97hx41 )  /* KOF'97 (Enable 5 Hidden Characters (Old))(NGM-2320) */
	DRIVER( kof97hx42 )  /* KOF'97 (Enable Hidden Characters' Portrait)(NGM-2320) */
	DRIVER( kof97hx43 )  /* KOF'97 (Double Select Leona And Iori)(NGM-2320) */
	DRIVER( kof97hx44 )  /* KOF'97 (Enable Hidden Stage (Middle Boss))(NGM-2320) */
	DRIVER( kof97hx45 )  /* KOF'97 (Enable Orochi Stage v1)(NGM-2320) */
	DRIVER( kof97hx46 )  /* KOF'97 (Enable Hidden Stage (Bousou)(NGM-2320) */
	DRIVER( kof97hx47 )  /* KOF'97 (Enable Hidden characters v1)(NGM-2320) */
	DRIVER( kof97hx48 )  /* KOF'97 (Enable Hidden characters v3)(NGM-2320) */
	DRIVER( kof97hx49 )  /* KOF'97 (Enable Hidden characters-Enable Orochi (S1 version))(2004-5-23)(NGM-2320) */
	DRIVER( kof97hx50 )  /* KOF'97 (Enable Hidden characters-Enable Orochi (C1 C2 version))(2005-2-23)(NGM-2320) */
	DRIVER( kof97hx51 )  /* KOF'97 (Hidden Characters - Enable Orochi (C5 C6 version))(NGM-2320) */
	DRIVER( kof97hx52 )  /* KOF'97 (Hidden Characters - Replace Orochi's Portrait (PS style))(NGM-2320) */
	DRIVER( kof97hx53 )  /* KOF'97 (Fix 5 Icons' Positions. (Right-Shift 1 Pixel))(2006-03-08)(NGM-2320) */
	DRIVER( kof97hx54 )  /* KOF'97 (Fix 5 Icons' Positions & 2 Pixel Stretch For 4 Icons)(2006-04-04)(NGM-2320) */
	DRIVER( kof97hx55 )  /* KOF'97 (Hidden Characters Extra/Fix Icons' Positions)(2006-04-04)(NGM-2320) */
	DRIVER( kof97hx57 )  /* KOF'97 (Hidden Characters Extra/Fix Icons' Positions V2)(2006-04-04)(NGM-2320) */
	DRIVER( kof97hx58 )  /* KOF'97 (Hidden Characters Extra/Fix Icons' Positions V3)(2006-04-04)(NGM-2320) */
	DRIVER( kof97hx59 )  /* KOF'97 (Hidden Characters Extra/Fix Icons' Positions V4)(2006-04-04)(NGM-2320) */
	DRIVER( kof97hx60 )  /* KOF'97 (Hidden Characters Enable Alt 01)(NGM-2320) */
	DRIVER( kof97hx61 )  /* KOF'97 (Hidden Characters Enable Alt 02)(NGM-2320) */
	DRIVER( kof97hx62 )  /* KOF'97 (Hidden Characters Enable V3 (Fix, Old Style))(NGM-2320) */
	DRIVER( kof97hx63 )  /* KOF'97 (Hidden Characters Enable Hidden Characters V1 (Fix, PS Style))(NGM-2320) */
	DRIVER( kof97hx64 )  /* KOF'97 (Enable All Hidden Characters V2)(NGM-2320) */
	DRIVER( kof97hx65 )  /* KOF'97 (Hidden Characters Enable Hidden Characters V2 (oak's fix))(2006-03-08)(NGM-2320) */
	DRIVER( kof97hx66 )  /* KOF'97 (Hidden Characters Enable Hidden Characters V2 (PS style))(NGM-2320) */
	DRIVER( kof97hx67 )  /* KOF'97 (Hidden Characters Enable Hidden Characters V2 (Fix, PS style))(NGM-2320) */
	DRIVER( kof97hx68 )  /* KOF'97 (Hidden Characters Extra-No Orochi's Shadow 1st)(NGM-2320) */
	DRIVER( kof97hx69 )  /* KOF'97 (Hidden Characters Extra-Fix Orochi Iori)(NGM-2320) */
	DRIVER( kof97hx70 )  /* KOF'97 (Hidden Characters Extra-Fix Orochi 1st)(NGM-2320) */
	DRIVER( kof97hx71 )  /* KOF'97 (Hidden Characters Extra-Fix Orochi 2nd)(NGM-2320) */
	DRIVER( kof97hx72 )  /* KOF'97 (Hidden Characters Extra-Fix Orochi 3rd)(NGM-2320) */
	DRIVER( kof97hx73 )  /* KOF'97 (Hidden Characters Extra-Fix Orochi 4th)(NGM-2320) */
	DRIVER( kof97hx74 )  /* KOF'97 (Hidden Characters Extra-#1 Replace 2 Colors For Orochi)(NGM-2320) */
	DRIVER( kof97hx75 )  /* KOF'97 (Hidden Characters Extra-#1 Replace 2 Poises For Orochi)(NGM-2320) */
	DRIVER( kof97hx76 )  /* KOF'97 Plus (Hack Alt 01)(NGM-2320) */
	DRIVER( kof97hx77 )  /* KOF'97 (Start With Power Max)(NGM-2320) */
	DRIVER( kof97hx78 )  /* KOF'97 (Power Mode Likes KOF98)(NGM-2320) */
	DRIVER( kof97hx79 )  /* KOF'97 (Always Maximum Power)(NGM-2320) */
	DRIVER( kof97hx80 )  /* KOF'97 (Unlimited Power Store)(NGM-2320) */
	DRIVER( kof97hx81 )  /* KOF'97 (Behind The Energy Beads Add And Subtract Changes)(NGM-2320) */
	DRIVER( kof97hx82 )  /* KOF'97 (KOF98 Energy Mode (New))(NGM-2320) */
	DRIVER( kof97hx83 )  /* KOF'97 (ABC Under MAX No Action)(NGM-2320) */
	DRIVER( kof97hx84 )  /* KOF'97 (Disassemble Ordinary Gas Investment)(NGM-2320) */
	DRIVER( kof97hx85 )  /* KOF'97 (Table Role Moves To Add)(NGM-2320) */
	DRIVER( kof97hx86 )  /* KOF'97 (Special Skills To Add)(NGM-2320) */
	DRIVER( kof97hx87 )  /* KOF'97 (Add Chris's New Moves)(NGM-2320) */
	DRIVER( kof97hx88 )  /* KOF'97 (Add Chris's Purple Fire)(NGM-2320) */
	DRIVER( kof97hx89 )  /* KOF'97 (Yagami Temple Instruction Ranaway)(NGM-2320) */
	DRIVER( kof97hx90 )  /* KOF'97 (Combo Version)(NGM-2320) */
	DRIVER( kof97hx91 )  /* KOF'97 (Moves' Appearance Change)(NGM-2320) */
	DRIVER( kof97hx92 )  /* KOF'97 (Evolutionary Balance)(NGM-2320) */
	DRIVER( kof97hx93 )  /* KOF'97 (Evolutionary Balance(2010.08))(NGM-2320) */
	DRIVER( kof97hx94 )  /* KOF'97 (Evolutionary Balance(2011.07))(NGM-2320) */
	DRIVER( kof97hx95 )  /* KOF'97 (Added Super Move For '94 Kyo)(NGM-2320) */
	DRIVER( kof97hx96 )  /* KOF'97 (#2 Snake Sunshine Action Replaces)(NGM-2320) */
	DRIVER( kof97hx97 )  /* KOF'97 (#2 Big Black Snake Effect Replacement)(2015-07-21)(NGM-2320) */
	DRIVER( kof97hx98 )  /* KOF'97 (Super Plus v1.2)(2006-02-05)(NGM-2320) */
	DRIVER( kof97hx99 )  /* KOF'97 (Super kill-Style Move Closed Action changes)(2005-09-18)(NGM-2320) */
	DRIVER( kof97hx100 )  /* KOF'97 (Athena Moves More Change)(2005-09-23)(NGM-2320) */
	DRIVER( kof97hx101 )  /* KOF'97 (Athena Phoenix Arrow Instruction To Amend)(NGM-2320) */
	DRIVER( kof97hx102 )  /* KOF'97 (Athena Phoenix Bombs Controllable Direction)(NGM-2320) */
	DRIVER( kof97hx103 )  /* KOF'97 (Athena Phoenix Arrows Move Correction)(NGM-2320) */
	DRIVER( kof97hx104 )  /* KOF'97 (Yagami Dark Hook Unlimited Chase)(NGM-2320) */
	DRIVER( kof97hx105 )  /* KOF'97 (Sakazaki Good Move To Strengthen)(NGM-2320) */
	DRIVER( kof97hx106 )  /* KOF'97 (Terry Before The Collision Intensified)(NGM-2320) */
	DRIVER( kof97hx107 )  /* KOF'97 (Colorful Version V1.5)(NGM-2320) */
	DRIVER( kof97hx108 )  /* KOF'97 (Color Change)(NGM-2320) */
	DRIVER( kof97hx109 )  /* KOF'97 (Black Version)(NGM-2320) */
	DRIVER( kof97hx110 )  /* KOF'97 (Color Version V2)(NGM-2320) */
	DRIVER( kof97hx111 )  /* KOF'97 (Violet Fire)(NGM-2320) */
	DRIVER( kof97hx112 )  /* KOF'97 (Icy Blue Style)(NGM-2320) */
	DRIVER( kof97hx113 )  /* KOF'97 (Icy Blue Style V1)(NGM-2320) */
	DRIVER( kof97hx114 )  /* KOF'97 (Interface Modified Version (Qingming Edition))(NGM-2320) */
	DRIVER( kof97hx115 )  /* KOF'97 (Purple & Green Edition)(NGM-2320) */
	DRIVER( kof97hx116 )  /* KOF'97 (Color Transplant Highlights)(NGM-2320) */
	DRIVER( kof97hx117 )  /* KOF'97 (Fix Hidden Characters' Icons)(2006-08-16)(NGM-2320) */
	DRIVER( kof97hx118 )  /* KOF'97 (Bug Fixes 1st 08.08.09)(NGM-2320) */
	DRIVER( kof97hx119 )  /* KOF'97 (Bug Fixes 2nd 14.05.23(NGM-2320)) */
	DRIVER( kof97hx120 )  /* KOF'97 (The Door Voted Correction)(NGM-2320) */
	DRIVER( kof97hx122 )  /* KOF'97 (Task Over Off)(NGM-2320) */
	DRIVER( kof97hx123 )  /* KOF'97 (Athena Opening Action Modified)(2011-12-26)(NGM-2320) */
	DRIVER( kof97hx124 )  /* KOF'97 (Transparent Energy Bar V2)(NGM-2320) */
	DRIVER( kof97hx125 )  /* KOF'97 (PPX Finished Version)(NGM-2320) */
	DRIVER( kof97hx126 )  /* KOF'97 (PPX Finished Version (Trap))(2006-04-19)(NGM-2320) */
	DRIVER( kof97hx127 )  /* KOF'97 (Slightly Traditional Chinese)(2005-08-29)(NGM-2320) */
	DRIVER( kof97hx128 )  /* KOF'97 (Blood Gas Pan Pan-Green (Advanced Only))(NGM-2320) */
	DRIVER( kof97hx129 )  /* KOF'97 (Echo Select Same Characters 2nd)(NGM-2320) */
	DRIVER( kof97hx130 )  /* KOF'97 (Echo Select Same Characters 3rd)(2014-02-01)(NGM-2320) */
	DRIVER( kof97hx131 )  /* KOF'97 (Echo Select Same Characters)(NGM-2320) */
	DRIVER( kof97hx133 )  /* KOF'97 (No Flash Version)(NGM-2320) */
	DRIVER( kof97hx134 )  /* KOF'97 (Attack Shows 1 Hit)(NGM-2320) */
	DRIVER( kof97hx135 )  /* KOF'97 (Modified Kusanagi's Standing Pose)(NGM-2320) */
	DRIVER( kof97hx136 )  /* KOF'97 (Nude Pack From Kog)(NGM-2320) */
	DRIVER( kof97hx137 )  /* KOF'97 (Switch Positive And Negative Roles)(NGM-2320) */
	DRIVER( kof97hx138 )  /* KOF'97 (Switch Positive And Negative Characters v1)(2006-01-29)(NGM-2320) */
	DRIVER( kof97hx139 )  /* KOF'97 (Qin Yang Attack Location To Modify)(2015-06-06)(NGM-2320) */
	DRIVER( kof97hx140 )  /* KOF'97 (Mode & Characters Select)(NGM-2320) */
	DRIVER( kof97hx141 )  /* KOF'97 (Increase Random Selection V1)(2013-05-23)(NGM-2320) */
	DRIVER( kof97hx142 )  /* KOF'97 (Random Selection Plus Version (V1 HACK 1))(2013-06-05)(NGM-2320) */
	DRIVER( kof97hx143 )  /* KOF'97 (Random Selection Plus Version (V1 HACK 2))(2013-05-2)(NGM-2320) */
	DRIVER( kof97hx144 )  /* KOF'97 (Random Selection Plus Version (V1 HACK 2, FIX))(2013-05-29)(NGM-2320) */
	DRIVER( kof97hx145 )  /* KOF'97 (Hits Number And Smile Change)(2006.6.15)(NGM-2320) */
	DRIVER( kof97hx146 )  /* KOF'97 (Enable Select All Colors v1)(NGM-2320) */
	DRIVER( kof97hx147 )  /* KOF'97 (Enable Select All Colors v2)(2006-10-06)(NGM-2320) */
	DRIVER( kof97hx148 )  /* KOF'97 (Sexy Edition)(Alt)(NGM-2320) */
	DRIVER( kof97hx149 )  /* KOF'97 (Close Part Of The Splash Screen)(NGM-2320) */
	DRIVER( kof97hx150 )  /* KOF'97 (Add Randomly Selected Characters)(NGM-2320) */
	DRIVER( kof97hx151 )  /* KOF'97 (Change The Heads As KOF98)(NGM-2320) */
	DRIVER( kof97hx152 )  /* KOF'97 (Enable Orochi Stage)(NGM-2320) */
	DRIVER( kof97hx153 )  /* KOF'97 (Blood Gas Tank Time Transparent First Edition)(NGM-2320) */
	DRIVER( kof97hx154 )  /* KOF'97 (Blood Gas Tank Time Transparent Second Edition)(NGM-2320) */
	DRIVER( kof97hx155 )  /* KOF'97 (Blood Gas Tank Time Transparent Third Edition)(NGM-2320) */
	DRIVER( kof97hx156 )  /* KOF'97 (Blood Gas Tank Time Transparent Quarter Edition)(NGM-2320) */
	DRIVER( kof97hx157 )  /* KOF'97 (Blood Gas Tank Time Transparent Fifth Edition)(NGM-2320) */
	DRIVER( kof97hx158 )  /* KOF'97 (Increase Defense Reminder)(NGM-2320) */
	DRIVER( kof97hx159 )  /* KOF'97 (KOFXI Flash Version)(NGM-2320) */
	DRIVER( kof97hx160 )  /* KOF'97 (Phase Friendliness Modify)(NGM-2320) */
	DRIVER( kof97hx162 )  /* KOF'97 (Chinese First Edition)(NGM-2320) */
	DRIVER( kof97hx163 )  /* KOF'97 (Chinese Second Edition)(NGM-2320) */
	DRIVER( kof97hx164 )  /* KOF'97 (Deepen Unlimited Repair)(NGM-2320) */
	DRIVER( kof97hx165 )  /* KOF'97 (Yagami Temple Shot Kill)(NGM-2320) */
	DRIVER( kof97hx166 )  /* KOF'97 (Cancel Itself Is Forbidden)(NGM-2320) */
	DRIVER( kof97hx167 )  /* KOF'97 (Provocative Reduction v1)(NGM-2320) */
	DRIVER( kof97hx168 )  /* KOF'97 (Provocative Reduction v2)(NGM-2320) */
	DRIVER( kof97hx169 )  /* KOF'97 (Runaway Seven Strong)(2015-01-06)(NGM-2320) */
	DRIVER( kof97hx170 )  /* KOF'97 (Substitution System)(NGM-2320) */
	DRIVER( kof97hx171 )  /* KOF'97 (Unlimited Credits In Console Mode)(NGM-2320) */
	DRIVER( kof97hx172 )  /* KOF'97 (AI fix & plus)(NGM-2320) */
	DRIVER( kof97hx173 )  /* KOF'97 (Batter Character Style Change)(NGM-2320) */
	DRIVER( kof97hx174 )  /* KOF'97 (KOFXI Flash Version V?)(NGM-2320) */
	DRIVER( kof97hx175 )  /* KOF'97 (Mode Select Off)(NGM-2320) */
	DRIVER( kof97hx176 )  /* KOF'97 (Random Test 2)(2013-5-17)(NGM-2320) */
	DRIVER( kof97hx177 )  /* KOF'97 (Jumping In The Same Volume Box With '98)(2006-08-04)(NGM-2320) */
	DRIVER( kof97hx178 )  /* KOF'97 (Special Volume Box Modification)(2006-08-05)(NGM-2320) */
	DRIVER( kof97hx179 )  /* KOF'97 (Investment Skills Hits Counted)(2007-01-02)(NGM-2320) */
	DRIVER( kof97hx180 )  /* KOF'97 (Blocking Version)(2010.02.07)(NGM-2320) */
	DRIVER( kof97hx181 )  /* KOF'97 (Time Infinite For Console Mode)(NGM-2320) */
	DRIVER( kof97hx182 )  /* KOF'97 (Close The Eye Flashes)(NGM-2320) */
	DRIVER( kof97hx183 )  /* KOF'97 (Add Flash Option)(NGM-2320) */
	DRIVER( kof97hx184 )  /* KOF'97 (Edit Team Again)(2012-08-13)(NGM-2320) */
	DRIVER( kof97hx185 )  /* KOF'97 (Romman Perfect Edition)(NGM-2320) */
	DRIVER( kof97hx186 )  /* KOF'97 (EX mode plus)(NGM-2320) */
	DRIVER( kof97hx187 )  /* KOF'97 (EX Red Blood Modification)(NGM-2320) */
	DRIVER( kof97hx188 )  /* KOF'97 (Close Kill The Splash Screen)(NGM-2320) */
	DRIVER( kof97hx189 )  /* KOF'97 (Turn Towards)(NGM-2320) */
	DRIVER( kof97hx190 )  /* KOF'97 (Optimized And Simplified Version Alt)(NGM-2320) */
	DRIVER( kof97hx191 )  /* KOF'97 (Use Your Dream To Do [L])(NGM-2320) */
	DRIVER( kof97hx192 )  /* KOF'97 (Evolution New)(NGM-2320) */
	DRIVER( kof97hx193 )  /* KOF'97 (Evolution New (new))(NGM-2320) */
	DRIVER( kof97hx194 )  /* KOF'97 (2013.01.06 AI (Test))(NGM-2320) */
	DRIVER( kof97hx195 )  /* KOF'97 (2011.07.11)(NGM-2320) */
	DRIVER( kof97hx196 )  /* KOF'97 (2011.07.21)(NGM-2320) */
	DRIVER( kof97hx197 )  /* KOF'97 (2011.08.01)(NGM-2320) */
	DRIVER( kof97hx199 )  /* KOF'97 (2012.07.20)(NGM-2320) */
	DRIVER( kof97hx200 )  /* KOF'97 (Dream 97)(NGM-2320) */
	DRIVER( kof97hx201 )  /* KOF'97 (Repair Big Serpent 1)(NGM-2320) */
	DRIVER( kof97hx202 )  /* KOF'97 (Repair Big Serpent 2)(NGM-2320) */
	DRIVER( kof97hx203 )  /* KOF'97 (Strongest VS Strongest Official Version)(NGM-2320) */
	DRIVER( kof97hx204 )  /* KOF'97 (Strongest Beta 2)(NGM-2320) */
	DRIVER( kof97hx205 )  /* KOF'97 (Overall Change Alt)(NGM-2320) */
	DRIVER( kof97hx206 )  /* KOF'97 (Enable 3 Hidden Characters)(NGM-2320) */
	DRIVER( kof97hx207 )  /* KOF'97 (Enable All Hidden Characters Alt)(NGM-2320) */
	DRIVER( kof97hx208 )  /* KOF'97 (Hidden Characters - Enable Orochi (S1 version)(Alt))(2004-5-23)(NGM-2320) */
	DRIVER( kof97hx209 )  /* KOF'97 (Hidden Characters - Enable Orochi (C1 C2 version)(A)(Alt)(2005-2-23)(NGM-2320) */
	DRIVER( kof97hx210 )  /* KOF'97 (Hidden Characters - Replace Orochi's portrait (old style) (Alt)(NGM-2320) */
	DRIVER( kof97hx212 )  /* KOF'97 (Hidden Characters - Replace Orochi's (PS style)(Alt))(NGM-2320) */
	DRIVER( kof97hx213 )  /* KOF'97 (Optional First Hidden Version Of Fix (Alt))(NGM-2320) */
	DRIVER( kof97hx214 )  /* KOF'97 (Change Serpent Picture Perfect Edition (PS Version)(Alt))(NGM-2320) */
	DRIVER( kof97hx215 )  /* KOF'97 (Optional Hidden Characters (Revised Edition)(Alt))(NGM-2320) */
	DRIVER( kof97hx216 )  /* KOF'97 (Optional Hidden Characters (Korean Version)(Alt))(NGM-2320) */
	DRIVER( kof97hx217 )  /* KOF'97 (Hidden People Add / Close Serpent Shadow & Flash)(NGM-2320) */
	DRIVER( kof97hx218 )  /* KOF'97 (94 Kyo plus 95 Kyo)(NGM-2320) */
	DRIVER( kof97hx219 )  /* KOF'97 (Red Pill Move To Modify)(NGM-2320) */
	DRIVER( kof97hx220 )  /* KOF'97 (BT Modify The Door)(NGM-2320) */
	DRIVER( kof97hx221 )  /* KOF'97 (I Do Not know The Fire Dance BT Flying)(NGM-2320) */
	DRIVER( kof97hx222 )  /* KOF'97 (Update The Repair Version)(NGM-2320) */
	DRIVER( kof97hx223 )  /* KOF'97 (Easy Move Version)(NGM-2320) */
	DRIVER( kof97hx224 )  /* KOF'97 (Move To Simplify The Boss Version)(NGM-2320) */
	DRIVER( kof97hx225 )  /* KOF'97 (Easy move final v1)(NGM-2320) */
	DRIVER( kof97hx226 )  /* KOF'97 (Easy move final v2)(NGM-2320) */
	DRIVER( kof97hx227 )  /* KOF'97 (Flying Props Enhanced Version)(NGM-2320) */
	DRIVER( kof97hx228 )  /* KOF'97 (Iori Unlimited Eight Glasses)(NGM-2320) */
	DRIVER( kof97hx229 )  /* KOF'97 (Yagami Temple Moves To Replace)(NGM-2320) */
	DRIVER( kof97hx230 )  /* KOF'97 (Move Simplified Version (B))(NGM-2320) */
	DRIVER( kof97hx231 )  /* KOF'97 (Table Grass Beijing Moves To Add)(NGM-2320) */
	DRIVER( kof97hx232 )  /* KOF'97 (Kyo Ghost Change)(2005-10-07)(NGM-2320) */
	DRIVER( kof97hx233 )  /* KOF'97 (Grass In Beijing To Strengthen The Version)(NGM-2320) */
	DRIVER( kof97hx234 )  /* KOF'97 (Move Instruction Changes(Alt))(NGM-2320) */
	DRIVER( kof97hx235 )  /* KOF'97 (Move Modified Version(Alt))(NGM-2320) */
	DRIVER( kof97hx236 )  /* KOF'97 (Simple Unlimited Connection)(07/08/2002)(NGM-2320) */
	DRIVER( kof97hx237 )  /* KOF'97 (Robert Moves To Add)(NGM-2320) */
	DRIVER( kof97hx238 )  /* KOF'97 (Dragon And Tiger Flurry & Phoenix Foot Defense With 95)(NGM-2320) */
	DRIVER( kof97hx239 )  /* KOF'97 (Mary Special Skills Modification)(2008.5.6)(NGM-2320) */
	DRIVER( kof97hx240 )  /* KOF'97 (Mary Special Skills Added)(2008.3.25)(NGM-2320) */
	DRIVER( kof97hx241 )  /* KOF'97 (Grass Beijing Special Skills To Add)(2008.3.25)(NGM-2320) */
	DRIVER( kof97hx242 )  /* KOF'97 (Robert Special Skill Added)(2008.3.25)(NGM-2320) */
	DRIVER( kof97hx243 )  /* KOF'97 (Terry Special Skills To Add)(2008.3.25)(NGM-2320) */
	DRIVER( kof97hx244 )  /* KOF'97 (Yamazaki Long Double Back To Return Faster)(2005-02-20)(NGM-2320) */
	DRIVER( kof97hx245 )  /* KOF'97 (Yamasaki Drag Back Slowly)(2005-02-20)(NGM-2320) */
	DRIVER( kof97hx246 )  /* KOF'97 (Change All Characters 2)(NGM-2320) */
	DRIVER( kof97hx247 )  /* KOF'97 (P2 MO ? [!])(NGM-2320) */
	DRIVER( kof97hx248 )  /* KOF'97 (Bug fixes)(NGM-2320) */
	DRIVER( kof97hx249 )  /* KOF'97 (BUG Part Of The Amendment)(NGM-2320) */
	DRIVER( kof97hx250 )  /* KOF'97 (Fixed Missing ADV Bar)(NGM-2320) */
	DRIVER( kof97hx251 )  /* KOF'97 (Fixed Kim Vs Choi)(NGM-2320) */
	DRIVER( kof97hx252 )  /* KOF'97 (Fixed Kyo In Demo Screen)(NGM-2320) */
	DRIVER( kof97hx253 )  /* KOF'97 (Fixed Orochi Vs Kenso)(NGM-2320) */
	DRIVER( kof97hx254 )  /* KOF'97 (Chris Instruction Transfiguration)(NGM-2320) */
	DRIVER( kof97hx255 )  /* KOF'97 (Liana Orders The Runaway)(NGM-2320) */
	DRIVER( kof97hx256 )  /* KOF'97 (Directed To Run Away Optimized Version)(NGM-2320) */
	DRIVER( kof97hx257 )  /* KOF'97 (Flying Props Unlimited)(NGM-2320) */
	DRIVER( kof97hx258 )  /* KOF'97 (Defense Endurance Modification V2)(2010.3.8)(NGM-2320) */
	DRIVER( kof97hx259 )  /* KOF'97 (Adjust The Cursor Position)(2013-05-29)(NGM-2320) */
	DRIVER( kof97hx260 )  /* KOF'97 (Super Abnormal Version)(NGM-2320) */
	DRIVER( kof97hx261 )  /* KOF'97 (Perfectly Integrated Patch)(NGM-2320) */
	DRIVER( kof97hx262 )  /* KOF'97 (Provocative Gas Reduction First Edition)(NGM-2320) */
	DRIVER( kof97hx263 )  /* KOF'97 (Provocative Deflated Second Edition)(NGM-2320) */
	DRIVER( kof97hx264 )  /* KOF'97 (Random + FLASH Integrated Version [!])(NGM-2320) */
	DRIVER( kof97hx265 )  /* KOF'97 (Home Edition Unlimited Time (B))(NGM-2320) */
	DRIVER( kof97hx266 )  /* KOF'97 (Extended Combat Time)(2005.07.22)(NGM-2320) */
	DRIVER( kof97hx267 )  /* KOF'97 (XXX Version)(NGM-2320) */
	DRIVER( kof97hx268 )  /* KOF'97 (Unlimited Credits In Console Mode 2ND)(NGM-2320) */
	DRIVER( kof97hx269 )  /* KOF'97 (Imitation KOF98)(NGM-2320) */
	DRIVER( kof97hx270 )  /* KOF'97 (Orochi Max Sun Shine To White Luo Extinction)(NGM-2320) */
	DRIVER( kof97hx271 )  /* KOF'97 (Shermie Added New Moves)(NGM-2320) */
	DRIVER( kof97hx273 )  /* KOF'97 (Combo 2010-02-07)(Alt)(NGM-2320) */
	DRIVER( kof97hx274 )  /* KOF'97 Plus (2003 Hack)(NGM-2320) */
	DRIVER( kof97hx275 )  /* KOF'97 (Chinese version)(2006-05-24)(NGM-2320) */
	DRIVER( kof97hx276 )  /* KOF'97 (The Final Decision - S1)(NGM-2320) */
	DRIVER( kof97hx277 )  /* KOF'97 (Couple Version)(NGM-2320) */
	DRIVER( kof97hx278 )  /* KOF'97 (Chris Became A Snake)(NGM-2320) */
	DRIVER( kof97hx279 )  /* KOF'97 (Transparent Energy Bar v6)(NGM-2320) */
	DRIVER( kof97hx281 )  /* KOF'97 (King of Gladiator)(Bootleg-Fix v1)(NGM-2320) */
	DRIVER( kof97hx282 )  /* KOF'97 (King of Gladiator)(Bootleg-Fix v2)(NGM-2320) */
	DRIVER( kof97hx285 )  /* KOF'97 (Enable hidden characters v1)(Alt)(NGM-2320) */
	DRIVER( kof97hx286 )  /* KOF'97 (Enable 3 hidden characters)(2011-12-05)(Alt)(NGM-2320) */
	DRIVER( kof97hx287 )  /* KOF'97 (Hidden Characters Fix Orochi 2nd)(Alt)(NGM-2320) */
	DRIVER( kof97hx289 )  /* KOF'97 (Hidden Characters-Enable Orochi (S1 version))(Alt)(2004-5-23)(NGM-2320) */
	DRIVER( kof97hx290 )  /* KOF'97 (Hidden Characters-Enable Orochi (C1 C2 version))(2005-2-23)(Alt)(NGM-2320) */
	DRIVER( kof97hx291 )  /* KOF'97 (Hidden Characters-Replace Orochi's portrait (old style))(Alt)(NGM-2320) */
	DRIVER( kof97hx292 )  /* KOF'97 (Hidden Characters-Replace Orochi's portrait (PS style))(Alt)(NGM-2320) */
	DRIVER( kof97hx293 )  /* KOF'97 (Hidden Characters Extra Fix Orochi 1st)(2004-12-24)(Alt)(NGM-2320) */
	DRIVER( kof97hx294 )  /* KOF'97 (Hidden Characters Extra Fix Orochi 2nd)(Alt)(NGM-2320) */
	DRIVER( kof97hx295 )  /* KOF'97 (Three Artifacts Wrath Official Version)(NGM-2320) */
	DRIVER( kof97hx296 )  /* KOF'97 (Evolutionary Balance (2010.08))(NGM-2320) */
	DRIVER( kof97hx297 )  /* KOF'97 (Chris Became A Snake)(Alt)(NGM-2320) */
	DRIVER( kof97hx298 )  /* KOF'97 (Dragon Edition 2.0)(Alt)(NGM-2320) */
	DRIVER( kof97hx299 )  /* KOF'97 (Dragon Edition 3.0)(Alt)(NGM-2320) */
	DRIVER( kof97hx300 )  /* KOF'97 (Cancel Power)(Alt)(NGM-2320) */
	DRIVER( kof97hx302 )  /* KOF'97 (Strengthened Defense)(NGM-2320) */
	DRIVER( kof97hx303 )  /* KOF'97 (Unknown Hack)(Alt)(NGM-2320) */
	DRIVER( kof97hx304 )  /* KOF'97 (Fix v3)(Alt ?)(NGM-2320) */
	DRIVER( kof97hs01 )  /* KOF'97 (Three Artifact Version)(NGH-2320) */
	DRIVER( kof97hs02 )  /* KOF'97 (Evolution)(NGH-2320) */
	DRIVER( kof97hs03 )  /* KOF'97 (EX mode plus)(NGH-2320) */
	DRIVER( kof97hs04 )  /* KOF'97 (King of Gladiator)(NGH-2320) */
	DRIVER( kof97hs05 )  /* KOF'97 (King of Gladiator)(Fix v1)(NGH-2320) */
	DRIVER( kof97hs06 )  /* KOF'97 (King of Gladiator)(Fix v2)(NGH-2320) */
	DRIVER( kof97hs07 )  /* KOF'97 (The Wrath Of The Masses v1)(NGH-2320) */
	DRIVER( kof97hs08 )  /* KOF'97 (The Wrath Of The Masses v2)(NGH-2320) */
	DRIVER( kof97hs09 )  /* KOF'97 Plus(NGH-2320) */
	DRIVER( kof97hs10 )  /* KOF'97 Plus (Hack 2006)(NGH-2320) */
	DRIVER( kof97hs11 )  /* KOF'97 Plus (Alt)(NGH-2320) */
	DRIVER( kof97hs12 )  /* KOF'97 Plus (Hack 2003)(Alt)(NGH-2320) */
	DRIVER( kof97hs13 )  /* KOF'97 (Imitate PlayStation Version Final)(NGH-2320) */
	DRIVER( kof97hs14 )  /* KOF'97 (Enable Orochi stage)(NGH-2320) */
	DRIVER( kof97hs15 )  /* KOF'97 (Enable Hidden Characters v1)(NGH-2320) */
	DRIVER( kof97hs16 )  /* KOF'97 (Enable Hidden Characters v2)(NGH-2320) */
	DRIVER( kof97hs17 )  /* KOF'97 (Hidden Characters Enable Orochi (S1 Version))(2004-5-23)(NGH-2320) */
	DRIVER( kof97hs18 )  /* KOF'97 (Hidden Characters Enable Orochi (C1 C2 Version))(2005-2-23)(NGH-2320) */
	DRIVER( kof97hs19 )  /* KOF'97 (Hidden Characters Enable Orochi (C5 C6 Version))(NGH-2320) */
	DRIVER( kof97hs20 )  /* KOF'97 (Hidden Characters Replace Orochi's portrait (PS Style))(NGH-2320) */
	DRIVER( kof97hs21 )  /* KOF'97 (Fix 5 Icons' Positions. (Right Shift 1 Pixel))(2006-03-08)(NGH-2320) */
	DRIVER( kof97hs22 )  /* KOF'97 (Enhanced Power)(NGH-2320) */
	DRIVER( kof97hs23 )  /* KOF'97 (Power Mode Likes Kof98)(NGH-2320) */
	DRIVER( kof97hs24 )  /* KOF'97 (Always Maximum Power)(NGH-2320) */
	DRIVER( kof97hs25 )  /* KOF'97 (Unlimited Power Store)(NGH-2320) */
	DRIVER( kof97hs26 )  /* KOF'97 (Table Role Move)(NGH-2320) */
	DRIVER( kof97hs27 )  /* KOF'97 (Special Skill Added)(NGH-2320) */
	DRIVER( kof97hs28 )  /* KOF'97 (Add Chris's New Moves)(NGH-2320) */
	DRIVER( kof97hs29 )  /* KOF'97 (Combo version)(NGH-2320) */
	DRIVER( kof97hs30 )  /* KOF'97 (Change In The Form Of The Move 2.22)(NGH-2320) */
	DRIVER( kof97hs31 )  /* KOF'97 (Added super move for '94 Kyo)(NGH-2320) */
	DRIVER( kof97hs32 )  /* KOF'97 (Remix)(NGH-2320) */
	DRIVER( kof97hs33 )  /* KOF'97 (Super Plus v1.2)(NGH-2320) */
	DRIVER( kof97hs34 )  /* KOF'97 (Bug Fixes)(NGH-2320) */
	DRIVER( kof97hs35 )  /* KOF'97 (Double Select Leona And Iori)(NGH-2320) */
	DRIVER( kof97hs36 )  /* KOF'97 (Echo Select Same Characters)(NGH-2320) */
	DRIVER( kof97hs37 )  /* KOF'97 (Switch Between Positive And Negative Roles)(NGH-2320) */
	DRIVER( kof97hs38 )  /* KOF'97 (Enable Select All Colors)(NGH-2320) */
	DRIVER( kof97hs39 )  /* KOF'97 (Kofxi Flash Version)(NGH-2320) */
	DRIVER( kof97hs40 )  /* KOF'97 (Unlimited Credits in Console Mode)(NGH-2320) */
	DRIVER( kof97hs41 )  /* KOF'97 (Hidden Characters Enable Orochi (C1 C2 Version))(Alt)(2005-2-23)(NGH-2320) */
	DRIVER( kof97hs42 )  /* KOF'97 (Hidden Characters Replace Orochi's Portrait (Old Style))(Alt)(NGH-2320) */
	DRIVER( kof97hs43 )  /* KOF'97 (Hidden Characters Replace Orochi's Portrait (PS Style))(Alt)(NGH-2320) */
	DRIVER( kof97hs44 )  /* KOF'97 (Hidden Characters Enable Hidden Characters v2)(2006-03-08)(NGH-2320) */
	DRIVER( kof97hs45 )  /* KOF'97 (Hidden Characters Fix Orochi 1st)(NGH-2320) */
	DRIVER( kof97hs46 )  /* KOF'97 (Hidden Characters Fix Orochi 2st)(NGH-2320) */
	DRIVER( kof97hs47 )  /* KOF'97 (Global Match v1)(NGH-2320) */
	DRIVER( kof97hs48 )  /* KOF'97 (Remix)(Ver.?)(NGH-2320) */
	DRIVER( kof97hs49 )  /* KOF'97 (KP 2000)(Ver.?)(NGM-2320) */
	DRIVER( kof97hs50 )  /* KOF'97 (Evolution Shin Edition)(Ver.?)(NGM-2320) */
	DRIVER( kof97hs51 )  /* KOF'97 (Get Out Of The Way Experience Version)(Ver.?)(NGM-2320) */
	DRIVER( kof97hs52 )  /* KOF'97 (Wulin Myth Dark Snake Test Edition 8)(Ver.?)(NGM-2320) */
	DRIVER( kof97hs53 )  /* KOF'97 (Remix ? Hacks)(Ver.?)(NGM-2320) */
	DRIVER( kof97hs54 )  /* KOF'97 (Combo 2018-05-05)(NGM-2320) */
	DRIVER( kof97plss01 )  /* KOF'97 Plus (Translation Korean)(bootleg) */
	DRIVER( kof97plss02 )  /* KOF'97 Plus (Enable Orochi Stage)(bootleg) */
	DRIVER( kof97plss03 )  /* KOF'97 Plus (Hidden Characters - Fix Icons' Positions V1)(2006-04-04)(bootleg) */
	DRIVER( kof97plss04 )  /* KOF'97 Plus (Hidden Characters - Fix Icons' Positions V2)(2006-04-04)(bootleg) */
	DRIVER( kof97plss05 )  /* KOF'97 Plus (Hidden Characters - Fix Icons' Positions V3)(2006-04-04)(bootleg) */
	DRIVER( kof97plss06 )  /* KOF'97 Plus (Hidden Characters - Fix Icons' Positions V4)(2006-04-04)(bootleg) */
	DRIVER( kof97plss07 )  /* KOF'97 Plus (Colorful Version V1.5)(bootleg) */
	DRIVER( kof97plss08 )  /* KOF'97 Plus (Color Change)(bootleg) */
	DRIVER( kof97plss09 )  /* KOF'97 Plus (Violet Fire)(bootleg) */
	DRIVER( kof97plss10 )  /* KOF'97 Plus (Icy Blue Style)(bootleg) */
	DRIVER( kof97plss11 )  /* KOF'97 Plus (Purple & Green Edition)(bootleg) */
	DRIVER( kof97plss12 )  /* KOF'97 Plus (Ma Palace Athena Summer Swimwear)(bootleg) */
	DRIVER( kof97plss13 )  /* KOF'97 Plus (Nude pack from kog)(bootleg) */
	DRIVER( kof97plss14 )  /* KOF'97 Plus (Transparent Energy Bar V1)(bootleg) */
	DRIVER( kof97plss15 )  /* KOF'97 Plus (Transparent Energy Bar V2)(bootleg) */
	DRIVER( kof97plss16 )  /* KOF'97 Plus (Transparent Energy Bar V3)(bootleg) */
	DRIVER( kof97plss17 )  /* KOF'97 Plus (Transparent Energy Bar V5)(bootleg) */
	DRIVER( kof97plss18 )  /* KOF'97 Plus (Transparent Energy Bar V6)(bootleg) */
	DRIVER( kof97plss19 )  /* KOF'97 Plus (Unlimited Credits In Console Mode)(bootleg) */
	DRIVER( kof97plss20 )  /* KOF'97 Plus (Description Of Hack Unknown)[GOTVG](bootleg) */
	DRIVER( kof97plas01 )  /* KOF'97 Plus (set 1)(Enable Orochi Stage)(NGM-2320) */
	DRIVER( kof97plas02 )  /* KOF'97 Plus (set 1)(Transparent Energy Bar v1)(NGM-2320) */
	DRIVER( kof97plas03 )  /* KOF'97 Plus (set 1)(Transparent Energy Bar v2)(NGM-2320) */
	DRIVER( kof97plas04 )  /* KOF'97 Plus (set 1)(Transparent Energy Bar v3)(NGM-2320) */
	DRIVER( kof97plas05 )  /* KOF'97 Plus (set 1)(Transparent Energy Bar v4)(NGM-2320) */
	DRIVER( kof97plas06 )  /* KOF'97 Plus (set 1)(Transparent Energy Bar v5)(NGM-2320) */
	DRIVER( kof97plas07 )  /* KOF'97 Plus (set 1)(Transparent Energy Bar v6)(NGM-2320) */
	DRIVER( kof97xts02 )  /* KOF'97 (Final Battle)(Orochi like NBC's Mizuchi [!])(NGM-2320) */
	DRIVER( kof97xts03 )  /* KOF'97 (Final Battle)(PS & XI Flash Perfect Edition [!])(NGM-2320) */
	DRIVER( kof97xts04 )  /* KOF'97 (Final Battle)(07.05.12)(B)(NGM-2320) */
	DRIVER( kof97xts05 )  /* KOF'97 (Final Battle)(SVS Beta Version 1)(NGM-2320) */
	DRIVER( kof97xts06 )  /* KOF'97 (Final Battle)(SVS Beta Version 2)(NGM-2320) */
	DRIVER( kof97xts07 )  /* KOF'97 (Final Battle)(The Strongest VS Strongest Official Version)(NGM-2320) */
	DRIVER( kof97xts08 )  /* KOF'97 (Final Battle)(TASK OVER OFF)(NGM-2320) */
	DRIVER( kof97xts09 )  /* KOF'97 (Final Battle)(2007-03-15)(v1)(NGM-2320) */
	DRIVER( kof97xts10 )  /* KOF'97 (Final Battle)(07.04.15)(A)(NGM-2320) */
	DRIVER( kof97xts11 )  /* KOF'97 (Final Battle)(07.04.15)(B)(NGM-2320) */
	DRIVER( kof97xts12 )  /* KOF'97 (Final Battle)(World Buwu)(07.08.26)(NGM-2320) */
	DRIVER( kof97xts13 )  /* KOF'97 (Final Battle)(World Buwu)(07.10.05)(NGM-2320) */
	DRIVER( kof97xts14 )  /* KOF'97 (Final Battle)(World Buwu)(07.11.16)(NGM-2320) */
	DRIVER( kof97xts15 )  /* KOF'97 (Final Battle)(World Buwu 0.083)(2008-01-01)(NGM-2320) */
	DRIVER( kof97xts16 )  /* KOF'97 (Final Battle)(World Buwu 0.084a)(NGM-2320) */
	DRIVER( kof97xts17 )  /* KOF'97 (Final Battle)(Group Demon Dance [!])(NGM-2320) */
	DRIVER( kof97xts18 )  /* KOF'97 (Final Battle)(Kagura Thousand Cranes Add)(NGM-2320) */
	DRIVER( kof97xts21 )  /* KOF'97 (Final Battle)(Chen Guohan Version Of Yanhua)(Alt)(NGM-2320) */
	DRIVER( kof97xts23 )  /* KOF'97 (Final Battle)(Orochi Hack)(NGM-2320) */
	DRIVER( kof97xts24 )  /* KOF'97 (Final Battle)(Zhenwu Added 75 Style Change)(NGM-2320) */
	DRIVER( kof97xts25 )  /* KOF'97 (Final Battle)(Seven-Year Society Kof98)(NGM-2320) */
	
	/* KOF98 HACKS */
	DRIVER( kof98aas ) /* KOF'98 (Asamiya Athena 99 Style)(NGH-2420) */
	DRIVER( kof98bge ) /* KOF'98 (Boss Gold Edition)(Korean board) */
	DRIVER( kof98bh ) /* KOF'98 (Boss Hack 2006)(NGM-2420) */
	DRIVER( kof98c2006 ) /* KOF'98 (Combo 2006)(NGH-2420) */
	DRIVER( kof98c20060214 ) /* KOF'98 (Combo 2006-02-14)(NGH-2420) */
	DRIVER( kof98c20100214 ) /* KOF'98 (Combo 2010-02-14)(NGH-2420) */
	DRIVER( kof98c20100304 ) /* KOF'98 (Combo 2010-03-04)(NGH-2420) */
	DRIVER( kof98c20110114 ) /* KOF'98 (Combo 2011-01-14)(NGH-2420) */
	DRIVER( kof98c20110314 ) /* KOF'98 (Combo 2011-03-14)(NGH-2420) */
	DRIVER( kof98c20120116 ) /* KOF'98 (Combo 2012-01-16)(NGH-2420) */
	DRIVER( kof98c20120915 ) /* KOF'98 (Combo 2012-09-15)(NGH-2420) */
	DRIVER( kof98c20130213 ) /* KOF'98 (Combo 2013-02-13)(NGH-2420) */
	DRIVER( kof98c20130311 ) /* KOF'98 (Combo 2013-03-19)(NGH-2420) */
	DRIVER( kof98c20130509 ) /* KOF'98 (Combo 2013-05-09)(NGH-2420) */
	DRIVER( kof98c20130528 ) /* KOF'98 (Combo 2013-05-30)(NGH-2420) */
	DRIVER( kof98c20130617 ) /* KOF'98 (Combo 2013-06-17)(NGH-2420) */
	DRIVER( kof98c20130808 ) /* KOF'98 (Combo 2013-08-08)(NGH-2420) */
	DRIVER( kof98c20130820 ) /* KOF'98 (Combo 2013-08-20)(NGH-2420) */
	DRIVER( kof98c20131113 ) /* KOF'98 (Combo 2013-11-13)(NGH-2420) */
	DRIVER( kof98c20140101 ) /* KOF'98 (Combo 2014-01-01)(NGH-2420) */
	DRIVER( kof98c20140110 ) /* KOF'98 (Combo 2014-01-10)(NGH-2420) */
	DRIVER( kof98c20140118 ) /* KOF'98 (Combo 2014-01-18)(NGH-2420) */
	DRIVER( kof98c20140204 ) /* KOF'98 (Combo 2014-02-04)(NGH-2420) */
	DRIVER( kof98c20140213 ) /* KOF'98 (Combo 2014-02-13)(NGH-2420) */
	DRIVER( kof98c20140217 ) /* KOF'98 (Combo 2014-02-17)(NGH-2420) */
	DRIVER( kof98c20140228 ) /* KOF'98 (Combo 2014-02-28)(NGH-2420) */
	DRIVER( kof98c20140302 ) /* KOF'98 (Combo 2014-03-02)(NGH-2420) */
	DRIVER( kof98c20140310 ) /* KOF'98 (Combo 2014-03-10)(NGH-2420) */
	DRIVER( kof98c20140317 ) /* KOF'98 (Combo 2014-03-17)(NGH-2420) */
	DRIVER( kof98c20140403 ) /* KOF'98 (Combo 2014-04-03)(NGH-2420) */
	DRIVER( kof98c20140412 ) /* KOF'98 (Combo 2014-04-12)(NGH-2420) */
	DRIVER( kof98c20140416 ) /* KOF'98 (Combo 2014-04-16)(NGH-2420) */
	DRIVER( kof98c20140419 ) /* KOF'98 (Combo 2014-04-19)(NGH-2420) */
	DRIVER( kof98c20140428 ) /* KOF'98 (Combo 2014-04-28)(NGH-2420) */
	DRIVER( kof98c20140504 ) /* KOF'98 (Combo 2014-05-04)(NGH-2420) */
	DRIVER( kof98c20140524 ) /* KOF'98 (Combo 2014-05-24)(NGH-2420) */
	DRIVER( kof98c20140606 ) /* KOF'98 (Combo 2014-06-06)(NGH-2420) */
	DRIVER( kof98c20140620 ) /* KOF'98 (Combo 2014-06-20)(NGH-2420) */
	DRIVER( kof98c20140717 ) /* KOF'98 (Combo 2014-07-17)(NGH-2420) */
	DRIVER( kof98c20140809 ) /* KOF'98 (Combo 2014-08-09)(NGH-2420) */
	DRIVER( kof98c20140816 ) /* KOF'98 (Combo 2014-08-16)(NGH-2420) */
	DRIVER( kof98c20140824 ) /* KOF'98 (Combo 2014-08-24)(NGH-2420) */
	DRIVER( kof98c20140906 ) /* KOF'98 (Combo 2014-09-06)(NGH-2420) */
	DRIVER( kof98c20140924 ) /* KOF'98 (Combo 2014-09-24)(NGH-2420) */
	DRIVER( kof98c20141002 ) /* KOF'98 (Combo 2014-10-02)(NGH-2420) */
	DRIVER( kof98c20141020 ) /* KOF'98 (Combo 2014-10-20)(NGH-2420) */
	DRIVER( kof98c20150201 ) /* KOF'98 (Combo 2015-02-01)(NGH-2420) */
	DRIVER( kof98c20150228 ) /* KOF'98 (Combo 2015-02-28)(NGH-2420) */
	DRIVER( kof98c20150302 ) /* KOF'98 (Combo 2015-03-02)(NGH-2420) */
	DRIVER( kof98c20150310 ) /* KOF'98 (Combo 2015-03-10)(NGH-2420) */
	DRIVER( kof98c20150330 ) /* KOF'98 (Combo 2015-03-30)(NGH-2420) */
	DRIVER( kof98c20150528 ) /* KOF'98 (Combo 2015-05-28)(NGH-2420) */
	DRIVER( kof98c20150614 ) /* KOF'98 (Combo 2015-06-14)(NGH-2420) */
	DRIVER( kof98c20150705 ) /* KOF'98 (Combo 2015-07-05)(NGH-2420) */
	DRIVER( kof98c20150729 ) /* KOF'98 (Combo 2015-07-29)(NGH-2420) */
	DRIVER( kof98c20150827 ) /* KOF'98 (Combo 2015-08-27)(NGH-2420) */
	DRIVER( kof98c20151103 ) /* KOF'98 (Combo 2015-11-03)(NGH-2420) */
	DRIVER( kof98c20151108 ) /* KOF'98 (Combo 2015-11-08)(NGH-2420) */
	DRIVER( kof98c20151110 ) /* KOF'98 (Combo 2015-11-10)(NGH-2420) */
	DRIVER( kof98c20151223 ) /* KOF'98 (Combo 2015-12-23)(NGH-2420) */
	DRIVER( kof98c20160320 ) /* KOF'98 (Combo 2016-03-20)(NGH-2420) */
	DRIVER( kof98c20160907 ) /* KOF'98 (Combo 2016-09-07)(NGH-2420) */
	DRIVER( kof98c20170303 ) /* KOF'98 (Combo 2017-03-03)(NGH-2420) */
	DRIVER( kof98c20170408 ) /* KOF'98 (Combo 2017-04-08)(NGH-2420) */
	DRIVER( kof98c20170601 ) /* KOF'98 (Combo 2017-06-01)(NGH-2420) */
	DRIVER( kof98c20170612 ) /* KOF'98 (Combo 2017-06-12)(NGH-2420) */
	DRIVER( kof98c20180228 ) /* KOF'98 (Combo 2018-02-28)(NGH-2420) */
	DRIVER( kof98c20180301 ) /* KOF'98 (Combo 2018-03-01)(NGH-2420) */
	DRIVER( kof98cd ) /* KOF'98 (CD conversion)(NGM-2420) */
	DRIVER( kof98cd1 ) /* KOF'98 (Hack Like NeoGeoCD Verson 1.4F)(NGH-2420) */
	DRIVER( kof98cd2 ) /* KOF'98 (Hack Like NeoGeoCD Verson 1.4)(NGH-2420) */
	DRIVER( kof98ch ) /* KOF'98 (Diff Moves 2003-05-03)(NGM-2420) */
	DRIVER( kof98ch1 ) /* KOF'98 (Chinese Translation hack set 2)(NGM-2420) */
	DRIVER( kof98chl ) /* KOF'98 (Diff Moves 2003-03-20)(NGM-2420) */
	DRIVER( kof98chris ) /* KOF'98 (Chris 2k2 Style)(NGH-2420)(NGM-2420) */
	DRIVER( kof98cn ) /* KOF'98 (Chinese Translation)(NGM-2420) */
	DRIVER( kof98cn1 ) /* KOF'98 (Chinese Translation)(Alt)(NGM-2420) */
	DRIVER( kof98cos ) /* KOF'98 (Cosmic)(Alt)(NGM-2420) */
	DRIVER( kof98cos1 ) /* KOF'98 (Cosmic 1)(NGM-2420) */
	DRIVER( kof98cos2 ) /* KOF'98 (Cosmic 2.0)(NGM-2420) */
	DRIVER( kof98dc ) /* KOF'98 (Char color changed - Negative style)(Korean board) */
	DRIVER( kof98ecm ) /* KOF'98 (Enhanced Chris Moves)(NGM-2420) */
	DRIVER( kof98ehr ) /* KOF'98 (Diff Moves - Ultra kill start max in Adv Mode - Ultra pow hack ABC)(NGM-2420) */
	DRIVER( kof98evl ) /* KOF'98 (Ultra Evolution Lite)(NGM-2420) */
	DRIVER( kof98evo ) /* KOF'98 (Evolution version)(NGM-2420) */
	DRIVER( kof98evo2 ) /* KOF'98 (Evolution Orochi Baozou Hack Set 2)(NGM-2420) */
	DRIVER( kof98evr ) /* KOF'98 (EVR)(NGM-2420) */
	DRIVER( kof98f ) /* KOF'98 ('fake')(NGM-2420) */
	DRIVER( kof98fr ) /* KOF'98 (French 2004)(NGM-2420) */
	DRIVER( kof98fro ) /* KOF'98 (French 2003)(NGM-2420) */
	DRIVER( kof98fro2 ) /* KOF'98 (French 2002)(NGM-2420) */
	DRIVER( kof98frp ) /* KOF'98 (Translation French Set 2)(04-01-2006)(NGM-2420) */
	DRIVER( kof98fv ) /* KOF'98 (Flash Revision)(NGM-2420) */
	DRIVER( kof98fv2 ) /* KOF'98 (Flash Version UK)(NGM-2420) */
	DRIVER( kof98gold ) /* KOF'98 (Gold Color Hack)(NGH-2420) */
	DRIVER( kof98hk ) /* KOF'98 (Hakeshu)(NGM-2420) */
	DRIVER( kof98ice ) /* KOF'98 (Icy blue style)(Korean board) */
	DRIVER( kof98ico ) /* KOF'98 (Icy blue style) (Old)(Korean board) */
	DRIVER( kof98iori ) /* KOF'98 (Iori Special)(2010-02-13)(NGM-2420) */
	DRIVER( kof98izh ) /* KOF'98 (Imitates Kof2002 Attacks Version)(2008-12-24)(Korean board) */
	DRIVER( kof98jh ) /* KOF'98 (Add Rugal - Athena style changed)(NGM-2420) */
	DRIVER( kof98k95 ) /* KOF'98 (EX KYO SP)(NGM-2420) */
	DRIVER( kof98lb ) /* KOF'98 (Tongtian Edition)(NGM-2420) */
	DRIVER( kof98lv ) /* KOF'98 (Love Edition)(2009-12-27)(NGM-2420) */
	DRIVER( kof98m ) /* KOF'98 (Mix)(NGM-2420) */
	DRIVER( kof98mev ) /* KOF'98 (MEV)(NGM-2420) */
	DRIVER( kof98mix ) /* KOF'98  (Mix 2011-10-01)(NGM-2420) */
	DRIVER( kof98nc ) /* KOF'98 (Neo-Geo CD 1.2)(NGM-2420) */
	DRIVER( kof98ncdh ) /* KOF'98 (CD to MVS Conversion)(NGM-2420) */
	DRIVER( kof98new ) /* KOF'98 (New Version)(NGM-2420) */
	DRIVER( kof98pjc ) /* KOF'98 (Char color changed)(Korean board) */
	DRIVER( kof98rh ) /* KOF'98 (Floating judgment enhanced version)(NGM-2420) */
	DRIVER( kof98rh1 ) /* KOF'98 (Real Rugal Hack)(NGM-2420) */
	DRIVER( kof98rl ) /* KOF'98 (Angry and angry)(NGM-2420) */
	DRIVER( kof98rm ) /* KOF'98 (Remix Changed Move List)(NGM-2420) */
	DRIVER( kof98rsa ) /* KOF'98 (Ralf Special Attack)(Korean board) */
	DRIVER( kof98rup ) /* KOF'98 (Ultimate Edition v1.0)(NGM-2420) */
	DRIVER( kof98seh ) /* KOF'98 (Ultra kill start max in Adv Mode - Ultra pow hack ABC)(NGM-2420) */
	DRIVER( kof98seho ) /* KOF'98 (Ultra kill start max in Adv Mode - Pow hack ABC)(NGM-2420) */
	DRIVER( kof98sof ) /* KOF'98 (Silver Omega Tributo a Fliperman)(NGM-2420) */
	DRIVER( kof98sp ) /* KOF'98 Super Plus (Hack)(NGM-2420) */
	DRIVER( kof98sp2 ) /* KOF'98 Super Plus (Hack Alternate Set)(NGM-2420) */
	DRIVER( kof98sr ) /* KOF'98 (Flash Landscaping)(NGM-2420) */
	DRIVER( kof98sv ) /* KOF'98 (Silver Style Edition)(Korean board) */
	DRIVER( kof98tim ) /* KOF'98 (Triple Impact Remix)(NGM-2420) */
	DRIVER( kof98ul ) /* KOF'98 (Ultra Leona)(NGM-2420) */
	DRIVER( kof98ur ) /* KOF'98 (Ultra Rugal)(NGM-2420) */
	DRIVER( kof98urf ) /* KOF'98 (Ultra Rugal Final Version)(NGM-2420) */
	DRIVER( kof98wh ) /* KOF'98 (Style changes for Kyo to 95' Kyo)(NGM-2420) */
	DRIVER( kof98wh1 ) /* KOF'98 (Moves' effect change)(NGH-2420) */
	DRIVER( kof98wh2 ) /* KOF'98 (Style changes for Kyo to 95' Kyo, Iori and Rugal)(NGM-2420) */
	DRIVER( kof98xi ) /* KOF'98 (XI Flash Version)(NGM-2420) */
	DRIVER( kof98y ) /* KOF'98 (Add Rugal)(NGM-2420) */
	DRIVER( kof98yh ) /* KOF'98 (Add Rugal - Pow hack ABC in Extra Mode)(NGM-2420) */
	DRIVER( kof98zy ) /* KOF'98 (Purple version)(Korean board) */
	DRIVER( kof98s01 ) /* KOF'98 (Rugal Ray)(NGM-2420) */
	DRIVER( kof98s02 ) /* KOF'98 (Description Of Hack Unknown)(Set 01)(NGM-2420) */
	DRIVER( kof98s03 ) /* KOF'98 (Cosmic)(NGM-2420) */
	DRIVER( kof98s04 ) /* KOF'98 (Combo 2010-03-21)(NGM-2420) */
	DRIVER( kof98s05 ) /* KOF'98 (Description Of Hack Unknown)(Set 04)(NGM-2420) */
	DRIVER( kof98s06 ) /* KOF'98 (Anniversary Edition Combo)(NGM-2420) */
	DRIVER( kof98s07 ) /* KOF'98 (Rugel Project)(NGM-2420) */
	DRIVER( kof98s08 ) /* KOF'98 (Description Of Hack Unknown)(Set 06)(NGM-2420) */
	DRIVER( kof98s09 ) /* KOF'98 (Slugfest Fever)(NGM-2420) */
	DRIVER( kof98s10 ) /* KOF'98 (Slugfest Fever Super)(NGM-2420) */
	DRIVER( kof98s11 ) /* KOF'98 (Heavenly Protoss Edition)(Love Edition)(NGH-2420) */
	DRIVER( kof98s12 ) /* KOF'98 (Unlimited Mix 2011)(NGM-2420) */
	DRIVER( kof98s13 ) /* KOF'98 (Roms Original)(Set 2)(NGM-2420) */
	DRIVER( kof98s14 ) /* KOF'98 (Console Mode)(Ver.?)(NGM-2420) */
	DRIVER( kof98s15 ) /* KOF'98 (Green Edition)(Chinese Version)(NGM-2420) */
	DRIVER( kof98s16 ) /* KOF'98 (Remixed New Colors)(NGM-2420) */
	DRIVER( kof98s17 ) /* KOF'98 (WI)(NGM-2420) */
	DRIVER( kof98s18 ) /* KOF'98 (Enhance Version)(NGM-2420) */
	DRIVER( kof98s19 ) /* KOF'98 (Description Of Hack Unknown)(Set 17)(NGM-2420) */
	DRIVER( kof98s20 ) /* KOF'98 (Description Of Hack Unknown)(Set 18)(NGM-2420) */
	DRIVER( kof98s21 ) /* KOF'98 (Extra Hidden Characters)(NGM-2420) */
	DRIVER( kof98s22 ) /* KOF'98 (Description Of Hack Unknown)(Set 20)(Korean board) */
	DRIVER( kof98s23 ) /* KOF'98 (Combo 2017-07-27)(NGM-2420) */
	DRIVER( kof98s24 ) /* KOF'98 (Description Of Hack Unknown)(Set 21)(Korean board) */
	DRIVER( kof98s25 ) /* KOF'98 Anniversary Edition (set s57) */
	DRIVER( kof98s26 ) /* KOF'98 Anniversary Edition (set s58) */
	DRIVER( kof98s27 ) /* KOF'98 (Combo 2006)(Chinese Edition)(NGM-2420) */
	DRIVER( kof98s28 ) /* KOF'98 (Combo 2006)(English Edition)(NGM-2420) */
	DRIVER( kof98s29 ) /* KOF'98 (Color)(Set 01)(NGM-2420) */
	DRIVER( kof98s30 ) /* KOF'98 (Color)(Set 02)(NGM-2420) */
	DRIVER( kof98s31 ) /* KOF'98 (The Dark Power)(NGM-2420) */
	DRIVER( kof98s32 ) /* KOF'98 (The Dark Power Extreme Edition)(NGM-2420) */
	DRIVER( kof98s33 ) /* KOF'98 (The Evil Power)(NGM-2420) */
	DRIVER( kof98s34 ) /* KOF'98 (The Evil Power Extreme Edition)(NGM-2420) */
	DRIVER( kof98s35 ) /* KOF'98 (Green Edition)(NGM-2420) */
	DRIVER( kof98s36 ) /* KOF'98 (Chinese Version Remix)(NGM-2420) */
	DRIVER( kof98s37 ) /* KOF'98 (Mint & Ice Chinese Edition Remix)(NGM-2420) */
	DRIVER( kof98s38 ) /* KOF'98 (Mint & Ice Chinese Edition Remix)(Alt)(NGM-2420) */
	DRIVER( kof98s39 ) /* KOF'98 (Platinum Edition Chinese)(NGM-2420) */
	DRIVER( kof98s40 ) /* KOF'98 (Purple Edition)(NGM-2420) */
	DRIVER( kof98s41 ) /* KOF'98 (Ryu Dragon Version fourth Edition)(NGH-2420) */
	DRIVER( kof98s42 ) /* KOF'98 (Ryu Dragon Version First Edition)(NGH-2420) */
	DRIVER( kof98s43 ) /* KOF'98 (Ryu Dragon Version Tree Edition)(NGH-2420) */
	DRIVER( kof98s44 ) /* KOF'98 (Ryu Dragon Version Fifth Edition)(NGH-2420) */
	DRIVER( kof98s45 ) /* KOF'98 (Ryu Dragon Version Second Edition)(NGH-2420) */
	DRIVER( kof98s46 ) /* KOF'98 (Gold Edition)(NGH-2420) */
	DRIVER( kof98s47 ) /* KOF'98 (Platinum Edition)(NGH-2420) */
	DRIVER( kof98s48 ) /* KOF'98 (Super Plus Remixed)(NGH-2420) */
	DRIVER( kof98s49 ) /* KOF'98 (Ice Edition Remixed)(NGH-2420) */
	DRIVER( kof98s50 ) /* KOF'98 (Negative Color)(NGH-2420) */
	DRIVER( kof98h01 ) /* KOF'98 (Get Power Up After Being Attacked)(Korean board) */
	DRIVER( kof98h02 ) /* KOF'98 (Enable Choosing Same One)(Korean board) */
	DRIVER( kof98h09 ) /* KOF'98 (Imitate KOFXI flash)(Korean board) */
	DRIVER( kof98h10 ) /* KOF'98 (Unlimited Credits In Console Mode)(Korean board) */
	DRIVER( kof98hh01 ) /* KOF'98 (Translation Chinese)(NGH-2420) */
	DRIVER( kof98hh02 ) /* KOF'98 (Interface Culture)(NGH-2420) */
	DRIVER( kof98hh03 ) /* KOF'98 (Translation French)(09-27-2002)(NGH-2420) */
	DRIVER( kof98hh04 ) /* KOF'98 (Translation Korean)(2006-04-25)(NGH-2420) */
	DRIVER( kof98hh05 ) /* KOF'98 (Imitate The NeoCD Version)(NGH-2420) */
	DRIVER( kof98hh06 ) /* KOF'98 (Combo 2006-02-03)(NGH-2420) */
	DRIVER( kof98hh07 ) /* KOF'98 (Combo 2006-10-10)(NGH-2420) */
	DRIVER( kof98hh08 ) /* KOF'98 (Combo 2007-01-10)(NGH-2420) */
	DRIVER( kof98hh09 ) /* KOF'98 (Combo 2007-02-22)(NGH-2420) */
	DRIVER( kof98hh10 ) /* KOF'98 (Combo 2007-03-22)(NGH-2420) */
	DRIVER( kof98hh11 ) /* KOF'98 (Combo 2007-07-20)(Alt)(NGH-2420) */
	DRIVER( kof98hh12 ) /* KOF'98 (Combo 2007-09-23)(Alt)(NGH-2420) */
	DRIVER( kof98hh13 ) /* KOF'98 (Combo 2008-01-21)(NGH-2420) */
	DRIVER( kof98hh14 ) /* KOF'98 (Combo 2008-07-31)(NGH-2420) */
	DRIVER( kof98hh15 ) /* KOF'98 (Combo 2009-05-31)(NGH-2420) */
	DRIVER( kof98hh16 ) /* KOF'98 (Get Power Up After Being Attacked)(NGH-2420) */
	DRIVER( kof98hh17 ) /* KOF'98 (Always Maximum Power)(NGH-2420) */
	DRIVER( kof98hh18 ) /* KOF'98 (Add '97 Shavings Wind)(2007.12.06)(NGH-2420) */
	DRIVER( kof98hh19 ) /* KOF'98 (Added Super Move For '95 Kyo)(NGH-2420) */
	DRIVER( kof98hh20 ) /* KOF'98 (Added Special Move For Ralf)(NGH-2420) */
	DRIVER( kof98hh21 ) /* KOF'98 (Ultra Leona)(NGH-2420) */
	DRIVER( kof98hh22 ) /* KOF'98 (Ultra Rugal Final Version)(NGH-2420) */
	DRIVER( kof98hh23 ) /* KOF'98 (Color Change V1)(NGH-2420) */
	DRIVER( kof98hh24 ) /* KOF'98 (Color Change V2)(NGH-2420) */
	DRIVER( kof98hh26 ) /* KOF'98 (Turn Red Fire Into Green)(NGH-2420) */
	DRIVER( kof98hh27 ) /* KOF'98 (Change Leona's Color)(NGH-2420) */
	DRIVER( kof98hh28 ) /* KOF'98 (Siver Style)(NGH-2420) */
	DRIVER( kof98hh29 ) /* KOF'98 (Bug Fixes)(NGH-2420) */
	DRIVER( kof98hh30 ) /* KOF'98 (Enable Choosing Same One)(NGH-2420) */
	DRIVER( kof98hh31 ) /* KOF'98 (Mai's Wedding Dress)(NGH-2420) */
	DRIVER( kof98hh32 ) /* KOF'98 (Slender Type Of Blood Scale)(NGH-2420) */
	DRIVER( kof98hh33 ) /* KOF'98 (Modified Kusanagi's Standing Pose)(NGH-2420) */
	DRIVER( kof98hh34 ) /* KOF'98 (Simplified Version)(NGH-2420) */
	DRIVER( kof98hh35 ) /* KOF'98 (New Flash)(NGH-2420) */
	DRIVER( kof98hh36 ) /* KOF'98 (Switch positive And Negative Roles Second Edition)(NGH-2420) */
	DRIVER( kof98hh37 ) /* KOF'98 (X Time Counter)(NGH-2420) */
	DRIVER( kof98hh38 ) /* KOF'98 (Transparent Energy Bar V1)(NGH-2420) */
	DRIVER( kof98hh39 ) /* KOF'98 (Transparent Energy Bar V2)(NGH-2420) */
	DRIVER( kof98hh40 ) /* KOF'98 (Imitate KOFXI Flash)(NGH-2420) */
	DRIVER( kof98hh41 ) /* KOF'98 (Unlimited Credits In Console Mode)(NGH-2420) */
	DRIVER( kof98hh44 ) /* KOF'98 (Combo 2008-03-30)(Alt)(NGH-2420) */
	DRIVER( kof98hh47 ) /* KOF'98 (Combo 2011-01-14)(Alt)(NGH-2420) */
	DRIVER( kof98hh48 ) /* KOF'98 (Combo 2011-01-26)(NGH-2420) */
	DRIVER( kof98hh49 ) /* KOF'98 (Combo 2011-02-23)(NGH-2420) */
	DRIVER( kof98hh50 ) /* KOF'98 (Combo 2011-04-01)(NGH-2420) */
	DRIVER( kof98hh51 ) /* KOF'98 (Combo 2011-04-11)(NGH-2420) */
	DRIVER( kof98hh52 ) /* KOF'98 (Combo 2011-04-15)(NGH-2420) */
	DRIVER( kof98hh53 ) /* KOF'98 (Combo 2011-04-17)(NGH-2420) */
	DRIVER( kof98hh54 ) /* KOF'98 (Combo 2011-04-26)(NGH-2420) */
	DRIVER( kof98hh55 ) /* KOF'98 (Combo 2012-02-06)(NGH-2420) */
	DRIVER( kof98hh56 ) /* KOF'98 (Combo 2012-04-06)(NGH-2420) */
	DRIVER( kof98hh57 ) /* KOF'98 (Combo 2012-04-20)(NGH-2420) */
	DRIVER( kof98hh58 ) /* KOF'98 (Combo 2012-06-19)(NGH-2420) */
	DRIVER( kof98hh59 ) /* KOF'98 (Combo 2012-07-06)(NGH-2420) */
	DRIVER( kof98hh60 ) /* KOF'98 (Combo 2012-07-10)(NGH-2420) */
	DRIVER( kof98hh61 ) /* KOF'98 (Protoss Version)(NGH-2420) */
	DRIVER( kof98hh62 ) /* KOF'98 (Unabated Energy Mode)(NGH-2420) */
	DRIVER( kof98hh63 ) /* KOF'98 (Super Easy To Move)(NGH-2420) */
	DRIVER( kof98hh64 ) /* KOF'98 (Mary Vertical Arrow)(2006.10.22)(NGH-2420) */
	DRIVER( kof98hh65 ) /* KOF'98 (Simplify The Move Version)(NGH-2420) */
	DRIVER( kof98hh66 ) /* KOF'98 (Simplify Move Combo Version)(NGH-2420) */
	DRIVER( kof98hh67 ) /* KOF'98 (Add Move To Yashiro)(NGH-2420) */
	DRIVER( kof98hh68 ) /* KOF'98 (Ryu Dragon Version Of The Sixth Edition)(NGH-2420) */
	DRIVER( kof98hh69 ) /* KOF'98 (Charge Removed)(NGH-2420) */
	DRIVER( kof98hh71 ) /* KOF'98 (Enable Choosing Same One V1)(NGH-2420) */
	DRIVER( kof98hh72 ) /* KOF'98 (Enable Choosing Same One V2)(NGH-2420) */
	DRIVER( kof98hh73 ) /* KOF'98 (Practice Mode Fix)(NGH-2420) */
	DRIVER( kof98hh74 ) /* KOF'98 (Enable Hidden Characters)(NGH-2420) */
	DRIVER( kof98hh75 ) /* KOF'98 (Combo 2013-09-13)(NGH-2420) */
	DRIVER( kof98hh76 ) /* KOF'98 (Combo 2016-03-21)(NGH-2420) */
	DRIVER( kof98hh77 ) /* KOF'98 (Combo 2016-12-20)(NGH-2420) */
	DRIVER( kof98hh78 ) /* KOF'98 (Combo 2017-01-08)(NGH-2420) */
	DRIVER( kof98hh79 ) /* KOF'98 (Combo 2015-10-07)(NGH-2420) */
	DRIVER( kof98hh80 ) /* KOF'98 (MEV)(Alt)(NGM-2420) */
	DRIVER( kof98hh84 ) /* KOF'98 (Combo 2010-10-10)(NGH-2420) */
	DRIVER( kof98hh96 ) /* KOF'98 (Combo 2009-12-04)(NGH-2420) */
	DRIVER( kof98hh97 ) /* KOF'98 (Combo 2009-10-24)(NGH-2420) */
	DRIVER( kof98hh98 ) /* KOF'98 (Combo 2009_10_26)(NGH-2420) */
	DRIVER( kof98hh100 ) /* KOF'98 (Combo 2010-06-15)(NGH-2420) */
	DRIVER( kof98hh102 ) /* KOF'98 (Combo 2010-08-27)(NGH-2420) */
	DRIVER( kof98hh103 ) /* KOF'98 (Combo 2011-03-29)(NGH-2420) */
	DRIVER( kof98hh104 ) /* KOF'98 (Combo 2011-04-18)(NGH-2420) */
	DRIVER( kof98hh105 ) /* KOF'98 (Combo 2007-02-04)(NGH-2420) */
	DRIVER( kof98hh106 ) /* KOF'98 (Combo 2009-11-23)(NGH-2420) */
	DRIVER( kof98hh107 ) /* KOF'98 (Combo 2010-02-04)(NGH-2420) */
	DRIVER( kof98hh108 ) /* KOF'98 (Combo 2010-05-16)(NGH-2420) */
	DRIVER( kof98hh109 ) /* KOF'98 (Combo 2011-11-11)(NGH-2420) */
	DRIVER( kof98hh110 ) /* KOF'98 (Combo 2018-05-05)(NGH-2420) */
	DRIVER( kof98hh111 ) /* KOF'98 (Easy Combo King Edition)(NGH-2420) */
	DRIVER( kof98xz01 ) /* KOF'98 (Posture Is Transferred)(NGM-2420) */
	DRIVER( kof98xz02 ) /* KOF'98 (Posture Reversal)(NGM-2420) */
	DRIVER( kof98xz03 ) /* KOF'98 (Enable hidden characters)(NGM-2420) */
	DRIVER( kof98xz04 ) /* KOF'98 (People Change Color 3)(NGM-2420) */
	DRIVER( kof98xz05 ) /* KOF'98 (Enable Choosing Same One V1)(NGM-2420) */
	DRIVER( kof98xz06 ) /* KOF'98 (Enable Choosing Same One V2)(NGM-2420) */
	DRIVER( kof98xz07 ) /* KOF'98 (Throwing Addition Hit)(NGM-2420) */
	DRIVER( kof98xz08 ) /* KOF'98 (New Flash)(NGM-2420) */
	DRIVER( kof98xz09 ) /* KOF'98 (Chinese Translation)(Alt)(Korean board) */
	DRIVER( kof98xz10 ) /* KOF'98 (French Translation)(Alt)(09-27-2002)(Korean board) */
	DRIVER( kof98xz11 ) /* KOF'98 (Korean Translation)(Alt)(2006-04-25)(Korean board) */
	
#endif	/* DRIVER_RECURSIVE */

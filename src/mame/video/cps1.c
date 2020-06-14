/***************************************************************************

The CPS1 system is made of 3 boards: A, B and C. The first two games also exist
a 2-board setups, where the C-board is integrated into the B-board.

There are several revisions of the A-board, but they are functionally equivalent
and interchangeable except for 89626A-4 DASH used by sf2ce which has a 12MHz xtal
replacing the 10MHz one. Note that it's likely that from one point onwards Capcom
simply switched to make only 89626A-4 DASH board, that is all games after a
certain point should use the 12MHz xtal not just sf2ce.

Known A-board revisions:

88617A-4
88617A-5
88617A-7
88617A-7b
89626A-4
89626A-4 DASH

Game                                                         Year  B-board #       B-board PALs       C-board #           CPS-B #          C-board PALs
-----------------------------------------------------------  ----  ---------  ---------------------  -----------  -----------------------  ------------
Forgotten Worlds (World, newer)                              1988  88621B-2   LW621            LWIO  None         CPS-B-01  DL-0411-10001  N/A
Forgotten Worlds (World)                                           88621B-2   LW621            LWIO  None         CPS-B-01  DL-0411-10001  N/A
Forgotten Worlds (USA, B-Board 88618B-2, Rev. A)                   88618B-2   LWCHR            LWIO  None         CPS-B-01  DL-0411-10001  N/A
Forgotten Worlds (USA, B-Board 88618B-2, Rev. AA)                  88618B-2   LWCHR            LWIO  None         CPS-B-01  DL-0411-10001  N/A
Forgotten Worlds (USA, B-Board 88618B-2, Rev. C)                   88618B-2   LWCHR            LWIO  None         CPS-B-01  DL-0411-10001  N/A
Forgotten Worlds (USA, B-Board 88621B-2, Rev. C)                   88621B-2   LW621            LWIO  None         CPS-B-01  DL-0411-10001  N/A
Lost Worlds (Japan Old Ver.)                                       88618B-2   LWCHR            LWIO  None         CPS-B-01  DL-0411-10001  N/A
Lost Worlds (Japan)                                                88618B-2   LWCHR            LWIO  None         CPS-B-01  DL-0411-10001  N/A

Ghouls'n Ghosts (World)                                      1988  88620-B-?  DM620            LWIO  None         CPS-B-01  DL-0411-10001  N/A
Ghouls'n Ghosts (USA)                                              88620-B-2  DM620            LWIO  None         CPS-B-01  DL-0411-10001  N/A
Daimakaimura (Japan)                                               88622B-2   DM22A            LWIO  88622-C-1    CPS-B-01  DL-0411-10001  None
Daimakaimura (Japan Resale Ver.)                                   91634B-2   DAM63B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Strider (USA, B-Board 89624B-2)                              1989  89624B-2   ST24M1           LWIO  88622-C-1/2  CPS-B-01  DL-0411-10001  None
Strider (USA, B-Board 89624B-3)                                    89624B-3   ST24B2           LWIO  88622-C-2    CPS-B-01  DL-0411-10001  None
Strider Hiryu (Japan)                                              88622B-3   ST22B            LWIO  88622-C-2    CPS-B-01  DL-0411-10001  None
Strider Hiryu (Japan Resale Ver.)                                  91634B-2   STH63B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Dynasty Wars (USA, B-Board 88622B-3)                         1989  88622B-3   TK22B            LWIO  88622-C-2    CPS-B-02  DL-0411-10002  None
Dynasty Wars (USA, B-Board 89624B-?)                               89624B-?   TK24B1           LWIO? ?            CPS-B-02  DL-0411-10002
Tenchi wo Kurau (Japan)                                            88622B-3   TK22B            LWIO  88622-C-2    CPS-B-02  DL-0411-10002  None
Tenchi wo Kurau (Japan Resale Ver.)                                91634B-2   TK163B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Willow (World)                                               1989  89624B-3   WL24B            LWIO  88622-C-4    CPS-B-03  DL-0411-10003  None
Willow (USA Old Ver.)                                              89624B-3   WL24B            LWIO  88622-C-2    CPS-B-03  DL-0411-10003  None
Willow (USA)                                                       89624B-3   WL24B            LWIO  88622-C-2/4  CPS-B-03  DL-0411-10003  None
Willow (Japan)                                                     88622B-3   WL22B            LWIO  88622-C-2    CPS-B-03  DL-0411-10003  None

U.N. Squadron (USA)                                          1989  89624B-2   AR24B            LWIO  88622-C-4    CPS-B-11  DL-0411-10004  None
Area 88 (Japan)                                                    88622B-3   AR22B            LWIO  88622-C-4    CPS-B-11  DL-0411-10004  None
Area 88 (Japan Resale Ver.)                                        91634B-2   ARA63B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Final Fight (World, set 1)                                   1989  89624B-3   S224B            IOB1  88622-C-5    CPS-B-04  DL-0411-10005  None
Final Fight (World, set 2)                                         89624B-3   S224B            LWIO  88622-C-5    CPS-B-04  DL-0411-10005  None
Final Fight (USA, set 1)                                           89624B-3   S224B            IOB1  88622-C-5    CPS-B-04  DL-0411-10005  None
Final Fight (USA, set 2)                                           89624B-3   S224B            IOB1  88622-C-5    CPS-B-04  DL-0411-10005  None
Final Fight (USA 900112)                                           89624B-3   S224B            IOB1  88622-C-5    CPS-B-04@ DL-0411-10001  None
Final Fight (USA 900424)                                           89624B-3   S224B            IOB1  88622-C-5    CPS-B-03  DL-0411-10003  None
Final Fight (USA 900613)                                           89624B-3   S224B            IOB1  88622-C-5    CPS-B-05  DL-0411-10006  None
Final Fight (Japan)                                                ?          S222B            ?     ?            CPS-B-04  DL-0411-10005
Final Fight (Japan 900112)                                         89625B-1   S222B            LWIO  88622-C-5    CPS-B-01  DL-0411-10001  None
Final Fight (Japan 900305)                                         88622B-3   S222B            LWIO  88622-C-5    CPS-B-02  DL-0411-10002  None
Final Fight (Japan 900613)                                         89625B-1   S222B            LWIO  88622-C-5    CPS-B-05  DL-0411-10006  None

1941: Counter Attack (World)                                 1990  89624B-3   YI24B            IOB1  88622-C-5    CPS-B-05  DL-0411-10006  None
1941: Counter Attack (World 900227)                                89624B-3   YI24B            IOB1  88622-C-5    CPS-B-05  DL-0411-10006  None
1941: Counter Attack (USA 900227)                                  89624B-3   YI24B            IOB1  88622-C-5    CPS-B-05  DL-0411-10006  None
1941: Counter Attack (Japan)                                       89625B-1   YI22B            LWIO? 88622-C-5    CPS-B-05  DL-0411-10006  None

Mercs (World 900302)                                         1990  89624B-3   O224B            IOB1  90628-C-1    CPS-B-12  DL-0411-10007  C628
Mercs (USA 900302)                                                 89624B-3   O224B            IOB1  90628-C-1/2  CPS-B-12  DL-0411-10007  C628
Mercs (USA 900608)                                                 89624B-3   O224B            IOB1  90628-C-1    CPS-B-12  DL-0411-10007  C628
Senjou no Ookami II (Japan 900302)                                 89625B-1   O222B            LWIO? 90628-C-1    CPS-B-12  DL-0411-10007  C628

Mega Twins (World 900619)                                    1990  89624B-3   CK24B            IOB1  88622-C-5    CPS-B-14  DL-0411-10009  None
Chiki Chiki Boys (Japan 900619)                                    89625B-1   CK22B            ?     ?            CPS-B-14  DL-0411-10009  None

Magic Sword: Heroic Fantasy (World 900623)                   1990  89624B-3   MS24B            IOB1  88622-C-5    CPS-B-13  DL-0411-10008  None
Magic Sword: Heroic Fantasy (World 900725)                         89624B-3   MS24B            IOB1  88622-C-5    CPS-B-13  DL-0411-10008  None
Magic Sword: Heroic Fantasy (USA 900725)                           89624B-3   MS24B            IOB1  88622-C-5    CPS-B-13  DL-0411-10008  None
Magic Sword: Heroic Fantasy (Japan 900623)                         89625B-1   MS22B            IOB1  88622-C-5    CPS-B-13  DL-0411-10008  None

Carrier Air Wing (World 901009)                              1990  89624B-3   CA24B            IOB1  88622-C-5    CPS-B-16  DL-0411-10011  None
Carrier Air Wing (World 901012)                                    89624B-3   CA24B            IOB1  88622-C-5    CPS-B-16  DL-0411-10011  None
Carrier Air Wing (USA 901012)                                      89624B-3   CA24B            IOB1  88622-C-5    CPS-B-16  DL-0411-10011  None
U.S. Navy (Japan 901012)                                           89625B-1   CA22B            IOB1  88622-C-5    CPS-B-16  DL-0411-10011  None

Nemo (World 901109)                                          1990  89624B-3   NM24B            IOB1  88622-C-5    CPS-B-15  DL-0411-10010  None
Nemo (World 901130)                                                89624B-3   NM24B            IOB1  88622-C-5    CPS-B-15  DL-0411-10010  None
Nemo (Japan 901120)                                                89625B-1   NM22B            ?     ?            CPS-B-15  DL-0411-10010

Street Fighter II: The World Warrior (World 910214)          1991  90629B-2   STF29            IOB1  90632C-1     CPS-B-17  DL-0411-10012  C632
Street Fighter II: The World Warrior (World 910228)                90629B-3   STF29            IOB2  90632C-1     CPS-B-18  DL-0411-10013  C632B
Street Fighter II: The World Warrior (World 910318)                90629B-3   STF29            IOB1  90632C-1     CPS-B-05  DL-0411-10006  C632
Street Fighter II: The World Warrior (World 910522)                90629B-3   STF29            IOB1  90632C-1     CPS-B-11  DL-0411-10004  C632
Street Fighter II: The World Warrior (USA 910206)                  90629B-2   STF29            IOB1  90632C-1     CPS-B-17  DL-0411-10012  C632
Street Fighter II: The World Warrior (USA 910214)                  90629B-3   STF29            IOB1  90632C-1     CPS-B-17  DL-0411-10012  C632
Street Fighter II: The World Warrior (USA 910228)                  90629B-3   STF29            IOB2  90632C-1     CPS-B-18  DL-0411-10013  C632B
Street Fighter II: The World Warrior (USA 910306)                  90629B-3   STF29            IOB1  90632C-1     CPS-B-12  DL-0411-10007  C632
Street Fighter II: The World Warrior (USA 910318)                  90629B-3   STF29            IOB1  90632C-1     CPS-B-05  DL-0411-10006  C632
Street Fighter II: The World Warrior (USA 910411)                  90629B-3   STF29            IOB1  90632C-1     CPS-B-15  DL-0411-10010  C632
Street Fighter II: The World Warrior (USA 910522, Rev. G)          90629B-3   STF29            IOB1  90632C-1     CPS-B-11  DL-0411-10004  C632
Street Fighter II: The World Warrior (USA 910522, Rev. I)          90629B-3   STF29            IOB1  90632C-1     CPS-B-14  DL-0411-10009  C632
Street Fighter II: The World Warrior (USA 911101)                  90629B-3   STF29            IOB1  90632C-1     CPS-B-17  DL-0411-10012  C632
Street Fighter II: The World Warrior (Japan 910214)                90629B-2   STF29            IOB1  90632C-1     CPS-B-17  DL-0411-10012  C632
Street Fighter II: The World Warrior (Japan 910306)                90629B-3   STF29            IOB1  90632C-1     CPS-B-12  DL-0411-10007  C632
Street Fighter II: The World Warrior (Japan 910411)                90629B-3   STF29            IOB1  90632C-1     CPS-B-15  DL-0411-10010  C632
Street Fighter II: The World Warrior (Japan 910522)                90629B-3   STF29            IOB1  90632C-1     CPS-B-13  DL-0411-10008  C632
Street Fighter II: The World Warrior (Japan 911210)                90629B-?   STF29            IOB1  ?            CPS-B-13  DL-0411-10008  C632
Street Fighter II: The World Warrior (Japan 920312)                90629B-2   STF29            IOB1  90632C-1     CPS-B-17  DL-0411-10012  C632

Three Wonders* (World 910513)                                1991  89624B-3   RT24B            IOB1  90630C-4     CPS-B-21  DL-0921-10014          IOC1
Three Wonders* (World 910520)                                      89624B-3   RT24B            IOB1  90630C-4     CPS-B-21  DL-0921-10014          IOC1
Three Wonders* (USA 910520)                                        89624B-3   RT24B            IOB1  90630C-4     CPS-B-21  DL-0921-10014          IOC1
Wonder 3* (Japan 910520)                                           89625B-1   RT22B            IOB1  90630C-4     CPS-B-21  DL-0921-10014          IOC1

The King of Dragons* (World 910711)                          1991  90629B-3   KD29B            IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1
The King of Dragons* (World 910805)                                90629B-3   KD29B            IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1
The King of Dragons* (USA 910910)                                  90629B-3   KD29B            IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1
The King of Dragons* (Japan 910805, B-Board 89625B-1)              89625B-1   KD22B            IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1
The King of Dragons* (Japan 910805, B-Board 90629B-3)              90629B-3   KD29B            IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1

Captain Commando* (World 911014)                             1991  91635B-2   CC63B    CCPRG   IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1
Captain Commando* (World 911202)                                   91635B-2   CC63B    CCPRG1  IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632B   IOC1
Captain Commando* (USA 910928)                                     91635B-2   CC63B    CCPRG1  IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1
Captain Commando* (Japan 910928)                                   91634B-2   CC63B    CCPRG   IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1
Captain Commando* (Japan 911202)                                   91634B-2   CC63B    CCPRG1  IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632B   IOC1

Knights of the Round* (World 911127)                         1991  91635B-2   KR63B    BPRG1   IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1
Knights of the Round* (USA 911127)                                 91635B-2   KR63B    BPRG1   IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1
Knights of the Round* (Japan 911127, B-Board 89625B-1)             89625B-1   KR22B            LWIO  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1
Knights of the Round* (Japan 911127, B-Board 91634B-2)             91634B-2   KR63B    BPRG1   IOB1  90631C-5     CPS-B-21  DL-0921-10014  C632    IOC1

Street Fighter II': Champion Edition (World 920313)          1992  91635B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Street Fighter II': Champion Edition (World 920513)                91635B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Street Fighter II': Champion Edition (USA 920313)                  91635B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Street Fighter II': Champion Edition (USA 920513)                  91635B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Street Fighter II': Champion Edition (USA 920803)                  91635B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Street Fighter II': Champion Edition (Japan 920322)                91634B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Street Fighter II': Champion Edition (Japan 920513)                91634B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Street Fighter II': Champion Edition (Japan 920803)                91634B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Adventure Quiz Capcom World 2* (Japan 920611)                1992  89625B-1   Q522B            LWIO  92641C-1     CPS-B-21  DL-0921-10014          IOC1
Adventure Quiz Capcom World 2* (Japan 920611)                      91634B-2   Q563B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
Adventure Quiz Capcom World 2 (Japan 920611)                       90629B-3   Q529B            IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1

Varth: Operation Thunderstorm (World 920612)                 1992  89624B-?   VA24B            IOB1  ?            CPS-B-04  DL-0411-10005
Varth: Operation Thunderstorm (World 920714)                       89624B-3   VA24B            IOB1  88622-C-5    CPS-B-04  DL-0411-10005  None
Varth: Operation Thunderstorm (USA 920612)                         91635B-2   VA63B    BPRG1   IOB1  88622-C-5    CPS-B-04  DL-0411-10005  None
Varth: Operation Thunderstorm* (Japan 920714)                      88622B-3   VA22B            LWIO  92641C-1     CPS-B-21  DL-0921-10014          IOC1
Varth: Operation Thunderstorm* (Japan Resale Ver. 920714)          91634B-2   VA63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1

Quiz & Dragons: Capcom Quiz Game* (USA 920701)               1992  89625B-1   QD22B            IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
Quiz & Dragons: Capcom Quiz Game (Japan Resale Ver. 940921)  1994  91634B-2   QAD63B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Warriors of Fate* (World 921002)                             1992  91635B-2   TK263B   BPRG1   IOB1  ?            CPS-B-21  DL-0921-10014          IOC1
Warriors of Fate* (World 921031)                                   91635B-2   TK263B   BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
Warriors of Fate* (USA 921031)                                     91635B-2   TK263B   BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
Sangokushi II* (Asia 921005)                                       91634B-2   TK263B   BPRG1   IOB1  ?            CPS-B-21  DL-0921-10014          IOC1
Tenchi wo Kurau II: Sekiheki no Tatakai* (Japan 921031)            91634B-2   TK263B   BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1

Street Fighter II': Hyper Fighting (World 921209)            1992  91635B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Street Fighter II': Hyper Fighting (USA 921209)                    91635B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Street Fighter II' Turbo: Hyper Fighting (Japan 921209)            91634B-2   S9263B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Cadillacs and Dinosaurs* (World 930201)                      1993  91635B-2   CD63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
Cadillacs and Dinosaurs* (USA 930201)                              91635B-2   CD63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
Cadillacs: Kyouryuu Shin Seiki* (Japan 930201)                     91634B-2   CD63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1

The Punisher* (World 930422)                                 1993  91635B-2   PS63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
The Punisher* (USA 930422)                                         91635B-2   PS63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
The Punisher* (Hispanic 930422)                                    91635B-2   PS63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
The Punisher* (Japan 930422)                                       91634B-2   PS63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1

Saturday Night Slam Masters* (World 930713)                  1993  91635B-2   MB63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
Saturday Night Slam Masters* (USA 930713)                          91635B-2   MB63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1
Muscle Bomber: The Body Explosion* (Japan 930713)                  91634B-2   MB63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1

Muscle Bomber Duo: Ultimate Team Battle* (World 931206)      1993  91635B-?   MB63B    BPRG1   IOB1  ?            CPS-B-21  DL-0921-10014          IOC1
Muscle Bomber Duo: Heat Up Warriors* (Japan 931206)                91634B-2   MB63B    BPRG1   IOB1  92641C-1     CPS-B-21  DL-0921-10014          IOC1

Ken Sei Mogura: Street Fighter II (Japan 940418, Ver 1.00)   1994  91634B-2   KNM10B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Pnickies (Japan 940608)                                      1994  89625B-1   PKB10B           IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Quiz Tonosama no Yabou 2: Zenkoku-ban (Japan 950123)         1995  90629B-3   TN2292           IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Pang! 3 (Euro 950511)                                        1995  94916-10   CP1B1F,CP1B8K,CP1B9K   92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Pang! 3 (Euro 950601)                                              94916-10   CP1B1F,CP1B8K,CP1B9KA  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Pang! 3: Kaitou Tachi no Karei na Gogo (Japan 950511)              94916-10   CP1B1F,CP1B8K,CP1B9K   92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Mega Man: The Power Battle (CPS1, USA 951006)                1995  91635B-2   RCM63B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Mega Man: The Power Battle (CPS1, Asia 951006)                     91634B-2   RCM63B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1
Rockman: The Power Battle (CPS1, Japan 950922)                     91634B-2   RCM63B   BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1

Ganbare! Marine Kun (Japan 2K0411)                           2000  91634B-2   GBPR2    BPRG1   IOB1  92631C-6     CPS-B-21  DL-0921-10014  C632    IOC1


@the original number (CPS-B-01) was scratched out and "04" stamped over it.
*denotes Suicide Battery

The C628/C632 PALs on some C-boards probably handle the extra inputs (6 buttons/third player).

You can set the suicide CPS-B-21 chips to their default layer register and priority bit values
if you pull pins 45 and 46 high (floating the pins seems to work, too). The default is the same
values as Street Fighter 2 CE/Turbo.



CPS-A Registers
---------------
0x00-0x01     OBJ RAM base (/256)
0x02-0x03     Scroll1 (8x8) RAM base (/256)
0x04-0x05     Scroll2 (16x16) RAM base (/256)
0x06-0x07     Scroll3 (32x32) RAM base (/256)
0x08-0x09     rowscroll RAM base (/256)
0x0a-0x0b     Palette base (/256) after this register is written to, the palette
              is copied from gfxram to the dedicated ram. The palette control
              register (see below) determines how the copy should happen.
              Tests on a msword pcb show that the minimum alignment for the palette
              is 0x400 bytes. The hardware seems to ignore bit 1, while when bit 0
              is set the palette doesn't seem to be copied. However, some games set
              bit 0 during boot (ghouls, strider, 1941) so it still isn't clear
              what bit 0 should actually do.
0x0c-0x0d     Scroll 1 X
0x0e-0x0f     Scroll 1 Y
0x10-0x11     Scroll 2 X
0x12-0x13     Scroll 2 Y
0x14-0x15     Scroll 3 X
0x16-0x17     Scroll 3 Y
0x18-0x19     Starfield 1 X
0x1a-0x1b     Starfield 1 Y
0x1c-0x1d     Starfield 2 X
0x1e-0x1f     Starfield 2 Y
0x20-0x21     start offset for the rowscroll matrix
0x22-0x23     video control. Usually 0x0e.
              bit 0 enables rowscroll on layer 2.
              bit 15 is flip screen.
              ghouls sets bit 14. Purpose unknown.
              1941 uses bits 1-3 by setting them to 0 on screen transitions,
              however it also uses the normal layer control register so there
              doesn't seem to be an obvious effect.

              Games known to use rowscroll:
              SF2
              Mega Twins (underwater, cave)
              Carrier Air Wing (hazy background at beginning of mission 8, put 07 at ff8501 to jump there)
              Magic Sword (fire on floor 3; screen distort after continue)
              Varth (title screen, end of stage 4)
              Captain Commando (end game sequence)

              Tests done on msword at the beginning of gameplay (many thanks to Corrado Tomaselli for these):
              3e  is the default value set by the game (not 0e like most games)
              3c  the last two rows of scroll1 are repeated on the whole screen
              3a  scroll2 is disabled
              36  scroll3 is disabled
              2e  no visible differences
              1e  no visible differences
              one might suspect that bits 4&5 should disable the star layers, but
              Strider sets this register to 0x0e so that's not possible.

              TODO:
              the scroll2/scroll3 disable bits are supported by the emulation,
              while the scroll1 weird effect is not (it doesn't seem to make a
              difference in any game).


CPS-B Registers
---------------
Unlike CPS-A registers, which are at fixed addresses, CPS-B registers move from game to game.
Following example strider

0x66-0x67   Layer control register
            bits 14-15 seem to be unused
                ghouls sets bits 15 in service mode when you press button 2 in
                the input test, with no apparent effect on the pcb.
                qtono2j sets them both at the game over screen.
            bits 6-13 (4 groups of 2 bits) select layer draw order
            bits 1-5 enable the three tilemap layers and the two starfield
                layers (the bit order changes from game to game).
                Only Forgotten Worlds and Strider use the starfield.
            bit 0 could be rowscroll related. It is set by captain commando,
                varth, mtwins, mssword, cawing while rowscroll is active. However
                kodj and sf2 do NOT set this bit while they are using rowscroll.
                Tests on the msword pcb show that even if this bit is not set,
                rowscroll still works. Therefore, the purpose of this bit is unclear.
0x68-0x69   Priority mask \   Tiles in the layer just below sprites can have
0x6a-0x6b   Priority mask |   four priority levels, each one associated with one
0x6c-0x6d   Priority mask |   of these masks. The masks indicate pens in the tile
0x6e-0x6f   Priority mask /   that have priority over sprites.
0x70-0x71   Palette control register. This indicates which palette
            pages to copy when the palette base register is written to.
            There is one CPS2 game (Slammasters II) setting this to 0x2f; all the other
            games normally set it to 0x3f, though in some cases different values are
            used during boot:
            ghouls  0x02 (and palette base is set to 9105; palette base is 9100 normally)
            strider 0x02 (and palette base is set to 9145; palette base is 9140 normally)
            1941    0x02 (and palette base is set to 9145; palette base is 9140 normally)
            unsquad 0x0f
            kod     0x0f
            mtwins  0x0f

            bit 0: copy page 0 (sprites)
            bit 1: copy page 1 (scroll1)
            bit 2: copy page 2 (scroll2)
            bit 3: copy page 3 (scroll3)
            bit 4: copy page 4 (stars1)
            bit 5: copy page 5 (stars2)

            An important quirk is that if the first bits are not set, page 0 in
            gfxram is not skipped but instead is copied to the first enabled page.
            For the other pages, if the bit is not set the gfxram page is skipped.
            Example: 0x0a
            bit 0 is not set so palette page 0 (sprites) is not updated
            bit 1 is set so palette page 1 (scroll1) is updated; since bit 0 was
            not set, it is taken from gfxram page 0
            bit 2 is not set so palette page 2 (scroll2) is not updated; gfxram
            page 1 is skipped
            bit 3 is set so palette page 3 (scroll3) is updated; it is taken from
            gfxram page 2

            bits 0-3 have been verified on a msword pcb, while bits 4-5 are only
            supposed.


A special note has to be made about tile/sprite codes. Even if all graphics are
stored together in the same ROMs, the hardware knows which part of the ROM space
is 8x8 tiles, 16x16 tiles, 16x16 spites, 32x32 tiles, and all games tested only
draw tiles if their code falls in the valid range. If a tile is out of range, it
is replaced by transparent pixels.
Ideally, this shouldn't be important as far as the emulation is concerned, since
games should only request tiles from valid ranges. In practice, many games contain
bugs which make them try to display out of range tiles. The masking applied by
the hardware therefore needs to be emulated properly, otherwise glitches appear.

There are various versions of the ROM board (B-board), so the implementation
details may vary, but in general the tile ranges are controlled by a PAL found
on the B-board (see the table at the top of this file).

The A-board passes 23 bits of address to the B-board when requesting gfx ROM data.
The B-board selects 64 bits of data, that is 16 4bpp pixels, and returns half of
them depending on a signal from the C board.
The 23 address bits are laid out this way (note that the top 3 bits select the
tile type; the purpose of the top bit is unknown):

sprite  000ccccccccccccccccyyyy
scroll1 001?ccccccccccccccccyyy
scroll2 010ccccccccccccccccyyyy
scroll3 011ccccccccccccccyyyyyx
stars   100000000sxxxxxyyyyyyyy (to be verified)

where
c is the tile code
y is the y position in the tile
x is the x position in the tile (only applicable to 32x32 tiles)

E.g. on the 89624B-3 board, used by cawing and others, the top 13 bits of the
address are passed to the 16L8B PAL @1A, which outputs the /OE signal for roms
1,3,5,7 (together), 2,4,6,8 (together), 10,12,14,16,20,22,24,26 (together) or
11,13,15,17,21,23,25,27 (together).
Note that in cawing only sockets 1,3,5,7 are populated, so effectively there is
only one bank.

The above would mean that
1) 8x8 and 16x16 tiles have a 16-bit tile code, while
   32x32 tiles have a 14-bit tile code
2) which ROM bank to use is determined by
   bits 15-7 of a 8x8 tile code,
   bits 15-6 of a 16x16 tile code,
   bits 13-4 of a 32x32 tile code

If the PAL decides that the tile code is out of range and doesn't output any /OE
signal, no ROM is read and pullup resistors force the result to all 1 (which
means a transparent tile).

Note that there are several known cases (nemo, cawing, 3wonders, varth, etc.) where
16x16 tiles are used for BOTH sprites and scroll2.

Ideally, the PALs should be dumped and loaded like the ROMs, and the mapping should
be derived from the loaded PALs at run time.
In practice, this is unlikely to happen, so we'll have to tolerate using hardcoded
maps for every game.


Known Bug List
==============
CPS2:
* CPS2 can do raster effects, certainly used by ssf2 (Cammy, DeeJay, T.Hawk levels),
  msh (lava level, early in attract mode) and maybe others (xmcotaj, vsavj).
  IRQ4 is some sort of scanline interrupt used for that purpose.

* Its unknown what CPS2_OBJ_BASE register (0x400000) does but it is not a object base
  register. The base is 0x7000 for all games even if 0x7080 is written to this register
  (checked on real HW). Maybe it sets the object bank used when cps2_objram_bank is set.

* Sprites are currently lagged by one frame to keep sync with backgrounds. This causes
  sprites to stay on screen one frame longer (visible in VSAV attract mode).

Marvel Vs. Capcom
* Sometimes corrupt gfx are displayed on the 32x32 layer as the screen flashes at the
  start of super combo moves. The problem seems to be due to tiles being fetched before
  the first 32x32 tile offset and results in data coming from 16x16 or 8x8 tiles instead.

CPS1:
SF2
* Missing chain in the foreground in Ken's level, and sign in Chun Li's level.
  Those graphics are in the backmost layer. Probably they are leftover from game
  development and aren't supposed to be visible.

3wonders
* writes to output ports 42, 44, 46.

qad
* layer enable mask incomplete


Unknown issues
==============

There are often some redundant high bits in the scroll layer's attributes.
I think that these are spare bits that the game uses to store additional
information, not used by the hardware.
The games seem to use them to mark platforms, kill zones and no-go areas.

***************************************************************************/

#include "emu.h"
#include "includes/cps1.h"


/********************************************************************

            Configuration table:

********************************************************************/

/* Game specific data */

#define GFXTYPE_SPRITES   (1 << 0)
#define GFXTYPE_SCROLL1   (1 << 1)
#define GFXTYPE_SCROLL2   (1 << 2)
#define GFXTYPE_SCROLL3   (1 << 3)
#define GFXTYPE_STARS     (1 << 4)

#define __not_applicable__	-1, -1, -1, -1, -1, -1, -1


/*			CPSB addr   CPSB value  mult factor1  mult factor2  m_result_lo  m_result_hi  unknown1  unknown2  unknown3  layer_ctrl	    priority masks[4]	  pal_ctrl     layer enable masks[5]		*/
#define CPS_B_01	  -1,	     0x0000,	   -1,		-1,	      -1,	   -1,		-1,	  -1,	    -1,	      0x26,	{0x28, 0x2a, 0x2c, 0x2e},   0x30,    {0x02, 0x04, 0x08, 0x30, 0x30}
#define CPS_B_02     	0x20,	     0x0002,		__not_applicable__, 							      0x2c,	{0x2a, 0x28, 0x26, 0x24},   0x22,    {0x02, 0x04, 0x08, 0x00, 0x00}
#define CPS_B_03      	  -1,	     0x0000,		__not_applicable__, 							      0x30, 	{0x2e, 0x2c, 0x2a, 0x28},   0x26,    {0x20, 0x10, 0x08, 0x00, 0x00}
#define CPS_B_04     	0x20,	     0x0004,		__not_applicable__, 							      0x2e, 	{0x26, 0x30, 0x28, 0x32},   0x2a,    {0x02, 0x04, 0x08, 0x00, 0x00}
#define CPS_B_05     	0x20,	     0x0005,		__not_applicable__, 							      0x28, 	{0x2a, 0x2c, 0x2e, 0x30},   0x32,    {0x02, 0x08, 0x20, 0x14, 0x14}
#define CPS_B_11     	0x32,	     0x0401,		__not_applicable__, 							      0x26, 	{0x28, 0x2a, 0x2c, 0x2e},   0x30,    {0x08, 0x10, 0x20, 0x00, 0x00}
#define CPS_B_12     	0x20,	     0x0402,		__not_applicable__, 							      0x2c, 	{0x2a, 0x28, 0x26, 0x24},   0x22,    {0x02, 0x04, 0x08, 0x00, 0x00}
#define CPS_B_13     	0x2e,	     0x0403,		__not_applicable__, 							      0x22, 	{0x24, 0x26, 0x28, 0x2a},   0x2c,    {0x20, 0x02, 0x04, 0x00, 0x00}
#define CPS_B_14     	0x1e,	     0x0404,		__not_applicable__,							      0x12, 	{0x14, 0x16, 0x18, 0x1a},   0x1c,    {0x08, 0x20, 0x10, 0x00, 0x00}
#define CPS_B_15     	0x0e,	     0x0405,		__not_applicable__, 							      0x02, 	{0x04, 0x06, 0x08, 0x0a},   0x0c,    {0x04, 0x02, 0x20, 0x00, 0x00}
#define CPS_B_16     	0x00,	     0x0406,		__not_applicable__, 							      0x0c, 	{0x0a, 0x08, 0x06, 0x04},   0x02,    {0x10, 0x0a, 0x0a, 0x00, 0x00}
#define CPS_B_17     	0x08,	     0x0407,		__not_applicable__, 							      0x14, 	{0x12, 0x10, 0x0e, 0x0c},   0x0a,    {0x08, 0x14, 0x02, 0x00, 0x00}
#define CPS_B_18     	0x10,	     0x0408,		__not_applicable__, 							      0x1c, 	{0x1a, 0x18, 0x16, 0x14},   0x12,    {0x10, 0x08, 0x02, 0x00, 0x00}

#define CPS_B_21_DEF	0x32,		 -1,	 0x00,	      0x02,	    0x04,	 0x06,	      0x08,	  -1,       -1,	      0x26,	{0x28, 0x2a, 0x2c, 0x2e},   0x30,    {0x02, 0x04, 0x08, 0x30, 0x30}  /* pang3 sets layer enable to 0x26 on startup */
#define CPS_B_21_BT1	0x32,	     0x0800,	 0x0e,	      0x0c,	    0x0a,	 0x08,	      0x06,	0x04,	  0x02,	      0x28,	{0x26, 0x24, 0x22, 0x20},   0x30,    {0x20, 0x04, 0x08, 0x12, 0x12}
#define CPS_B_21_BT2	  -1,		 -1,	 0x1e,	      0x1c,	    0x1a,	 0x18,		-1,	0x0c,	  0x0a,	      0x20,	{0x2e, 0x2c, 0x2a, 0x28},   0x30,    {0x30, 0x08, 0x30, 0x00, 0x00}
#define CPS_B_21_BT3  	  -1,		 -1,	 0x06,	      0x04,	    0x02,	 0x00,	      0x0e,	0x0c,	  0x0a,	      0x20,	{0x2e, 0x2c, 0x2a, 0x28},   0x30,    {0x20, 0x12, 0x12, 0x00, 0x00}
#define CPS_B_21_BT4  	  -1,		 -1,	 0x06,	      0x04,	    0x02,	 0x00,	      0x1e,	0x1c,	  0x1a,	      0x28,	{0x26, 0x24, 0x22, 0x20},   0x30,    {0x20, 0x10, 0x02, 0x00, 0x00}
#define CPS_B_21_BT5 	0x32,		 -1,	 0x0e,	      0x0c,	    0x0a,	 0x08,	      0x1e,	0x1c,	  0x1a,	      0x20,	{0x2e, 0x2c, 0x2a, 0x28},   0x30,    {0x20, 0x04, 0x02, 0x00, 0x00}
#define CPS_B_21_BT6  	  -1,		 -1,	   -1,		-1,	      -1,	   -1,		-1,	  -1,	    -1,	      0x20,	{0x2e, 0x2c, 0x2a, 0x28},   0x30,    {0x20, 0x14, 0x14, 0x00, 0x00}
#define CPS_B_21_BT7  	  -1,		 -1,	   -1,		-1,	      -1,	   -1,		-1,	  -1,	    -1,	      0x2c,	{  -1,   -1,   -1,   -1},   0x12,    {0x14, 0x02, 0x14, 0x00, 0x00}
#define CPS_B_21_QS1  	  -1,		 -1,	   -1,		-1,	      -1,	   -1,		-1,	  -1,	    -1,	      0x22,	{0x24, 0x26, 0x28, 0x2a},   0x2c,    {0x10, 0x08, 0x04, 0x00, 0x00}
#define CPS_B_21_QS2  	  -1,		 -1,	   -1,		-1,	      -1,	   -1,		-1,	0x2e,	  0x20,	      0x0a,	{0x0c, 0x0e, 0x00, 0x02},   0x04,    {0x16, 0x16, 0x16, 0x00, 0x00}
#define CPS_B_21_QS3 	0x0e,	     0x0c00,	   -1,		-1,	      -1,	   -1,	      0x2c,	  -1,	    -1,	      0x12,	{0x14, 0x16, 0x08, 0x0a},   0x0c,    {0x04, 0x02, 0x20, 0x00, 0x00}
#define CPS_B_21_QS4 	0x2e,	     0x0c01,	   -1,		-1,	      -1,	   -1,	      0x1c,	0x1e,	  0x08,	      0x16,	{0x00, 0x02, 0x28, 0x2a},   0x2c,    {0x04, 0x08, 0x10, 0x00, 0x00}
#define CPS_B_21_QS5 	0x1e,	     0x0c02,	   -1,		-1,	      -1,	   -1,	      0x0c,	  -1,	    -1,	      0x2a,	{0x2c, 0x2e, 0x30, 0x32},   0x1c,    {0x04, 0x08, 0x10, 0x00, 0x00}

#define HACK_B_1      	  -1,		 -1,	   -1,		-1,	      -1,	   -1,		-1,	  -1,	    -1,	      0x14,	{0x12, 0x10, 0x0e, 0x0c},   0x0a,    {0x0e, 0x0e, 0x0e, 0x30, 0x30}
#define	HACK_B_2	  -1,		 -1,	 0x0e,	      0x0c,	    0x0a,	 0x08,	      0x06,	0x04,	  0x02,	      0x28,	{0x26, 0x24, 0x22, 0x20},   0x22,    {0x20, 0x04, 0x08, 0x12, 0x12}
#define HACK_H_5	  -1,	     0x0000,		__not_applicable__,							      0x26,	{0x28, 0x2a, 0x2c, 0x2e},   0x30,    {0x40, 0x40, 0x40, 0x00, 0x00}  /* for daimakaib */
#define HACK_SF_JB     	  -1,		 -1,		__not_applicable__,							      0x30,	{0x2e, 0x2c, 0x2a, 0x28},   0x26,    {0x02, 0x04, 0x08, 0x00, 0x00}
#define HACK_WOF_H     	  -1,		 -1,		__not_applicable__,							      0x20,	{0x26, 0x28, 0x2c, 0x2e},   0x2a,    {0x02, 0x04, 0x08, 0x30, 0x30}

// HBMAME extras

#define HACK_H_2      -1,   -1,    -1,  -1,  -1,  -1,   -1,  -1,  -1,   0x20,{ -1,  -1,  -1,  -1 },0x2a, {0x02,0x02,0x02,0x00,0x00} // wofh etc
#define HACK_H_3      -1,   -1,    -1,  -1,  -1,  -1,   -1,  -1,  -1,   0x04,{0x12,0x10,0x0e,0x0c},0x0a, {0x02,0x02,0x02,0x00,0x00} // not used
#define HACK_H_4      -1,   -1,    -1,  -1,  -1,  -1,   -1,  -1,  -1,   0x30,{0x2e,0x2c,0x2a,0x28},0x26, {0x02,0x04,0x08,0x00,0x00} // not used
#define HACK_H_6      -1,   -1,   0x06,0x04,0x02,0x00, 0x1e,0x1c,0x1a,  0x28,{0x26,0x24,0x22,0x20},0x30, {0x40,0x10,0x02,0x00,0x00} // knightsb2
#define HACK_H_7      -1,   -1,   0x06,0x04,0x02,0x00, 0x1e,0x1c,0x1a,  0x26,{0x28,0x2a,0x2c,0x2e},0x30, {0x20,0x10,0x02,0x00,0x00} // knightsha
#define HACK_H_8      -1,   -1,    -1,  -1,  -1,  -1,   -1,  -1,  -1,   0x20,{0x00,0x00,0x00,0x00},0x00, {0x80,0x80,0x80,0x00,0x00}


/*	CPS_B_21_DEF is CPS-B-21 at default settings (no battery)
	CPS_B_21_BTx are various battery configurations
	CPS_B_21_QSx are various battery configurations in Q-Sound games	*/

/*	LWCHR and LW621 are equivalent as far as the game is concerned, though the
   	equations are different		*/

#define mapper_LWCHR	{ 0x8000, 0x8000, 0, 0 }, mapper_LWCHR_table
static const struct gfx_range mapper_LWCHR_table[] =
{
	// verified from PAL dump (PAL16P8B @ 3A):
	// bank 0 = pin 19 (ROMs 1,5,8,12)
	// bank 1 = pin 16 (ROMs 2,6,9,13)
	// pin 12 and pin 14 are always enabled (except for stars)
	// note that allowed codes go up to 0x1ffff but physical ROM is half that size

	/* type            start    end      bank */
	{ GFXTYPE_SPRITES, 0x00000, 0x07fff, 0 },
	{ GFXTYPE_SCROLL1, 0x00000, 0x1ffff, 0 },

	{ GFXTYPE_STARS,   0x00000, 0x1ffff, 1 },
	{ GFXTYPE_SCROLL2, 0x00000, 0x1ffff, 1 },
	{ GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 1 },
	{ 0 }
};

#define mapper_LW621	{ 0x8000, 0x8000, 0, 0 }, mapper_LW621_table
static const struct gfx_range mapper_LW621_table[] =
{
	// verified from PAL dump (PAL @ 1A):
	// bank 0 = pin 18
	// bank 1 = pin 14
	// pins 19, 16, 17, and 12 give an alternate half-size mapping which would
	// allow to use smaller ROMs:
	// pin 19
	// 0 00000-03fff
	// pin 16
	// 0 04000-07fff
	// 1 00000-1ffff
	// pin 17
	// 2 00000-1ffff
	// 3 00000-1ffff
	// 4 00000-1ffff
	// pin 12
	// 3 00000-1ffff
	//
	// note that allowed codes go up to 0x1ffff but physical ROM is half that size

	/* type            start    end      bank */
	{ GFXTYPE_SPRITES, 0x00000, 0x07fff, 0 },
	{ GFXTYPE_SCROLL1, 0x00000, 0x1ffff, 0 },

	{ GFXTYPE_STARS,   0x00000, 0x1ffff, 1 },
	{ GFXTYPE_SCROLL2, 0x00000, 0x1ffff, 1 },
	{ GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 1 },
	{ 0 }
};

// DM620, DM22A and DAM63B are equivalent as far as the game is concerned, though
// the equations are quite different

#define mapper_DM620	{ 0x8000, 0x2000, 0x2000, 0 }, mapper_DM620_table
static const struct gfx_range mapper_DM620_table[] =
{
	// verified from PAL dump (PAL16P8B @ 2A):
	// bank 0 = pin 19 (ROMs  5,6,7,8)
	// bank 1 = pin 16 (ROMs  9,11,13,15,18,20,22,24)
	// bank 2 = pin 14 (ROMs 10,12,14,16,19,21,23,25)
	// pin 12 is never enabled
	// note that bank 0 is enabled whenever banks 1 or 2 are not enabled,
	// which would make it highly redundant, so I'm relying on the table
	// to be scanned top to bottom and using a catch-all clause at the end.

	/* type            start   end     bank */
	{ GFXTYPE_SCROLL3, 0x8000, 0xbfff, 1 },

	{ GFXTYPE_SPRITES, 0x2000, 0x3fff, 2 },

	{ GFXTYPE_STARS | GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 0 },
	{ 0 }
};

#define mapper_DM22A	{ 0x4000, 0x4000, 0x2000, 0x2000 }, mapper_DM22A_table
static const struct gfx_range mapper_DM22A_table[] =
{
	// verified from PAL dump
	// bank 0 = pin 19
	// bank 1 = pin 16
	// bank 2 = pin 14
	// bank 3 = pin 12

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x00000, 0x01fff, 0 },
	{ GFXTYPE_SCROLL1, 0x02000, 0x03fff, 0 },

	{ GFXTYPE_SCROLL2, 0x04000, 0x07fff, 1 },

	{ GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 2 },

	{ GFXTYPE_SPRITES, 0x02000, 0x03fff, 3 },
	{ 0 }
};

#define mapper_DAM63B	{ 0x8000, 0x8000, 0, 0 }, mapper_DAM63B_table
static const struct gfx_range mapper_DAM63B_table[] =
{
	// verified from PAL dump:
	// bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
	// bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
	// pins 12,13,14,15 are always enabled

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x00000, 0x01fff, 0 },
	{ GFXTYPE_SCROLL1, 0x02000, 0x02fff, 0 },
	{ GFXTYPE_SCROLL2, 0x04000, 0x07fff, 0 },

	{ GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 1 },
	{ GFXTYPE_SPRITES, 0x02000, 0x03fff, 1 },
	{ 0 }
};


// ST24M1 and ST22B are equivalent except for the stars range which is
// different. This has no practical effect.

#define mapper_ST24M1	{ 0x8000, 0x8000, 0, 0 }, mapper_ST24M1_table
static const struct gfx_range mapper_ST24M1_table[] =
{
	// verified from PAL dump
	// bank 0 = pin 19 (ROMs 2,4,6,8)
	// bank 1 = pin 16 (ROMs 1,3,5,7)
	// pin 12 and pin 14 are never enabled

	/* type            start    end      bank */
	{ GFXTYPE_STARS,   0x00000, 0x003ff, 0 },
	{ GFXTYPE_SPRITES, 0x00000, 0x04fff, 0 },
	{ GFXTYPE_SCROLL2, 0x04000, 0x07fff, 0 },

	{ GFXTYPE_SCROLL3, 0x00000, 0x07fff, 1 },
	{ GFXTYPE_SCROLL1, 0x07000, 0x07fff, 1 },
	{ 0 }
};

#define mapper_ST22B	{ 0x4000, 0x4000, 0x4000, 0x4000 }, mapper_ST22B_table
static const struct gfx_range mapper_ST22B_table[] =
{
	// verified from PAL dump
	// bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
	// bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
	// bank 2 = pin 14 (ROMs 3,7,11,15,19,21,26,28)
	// bank 3 = pin 12 (ROMS 4,8,12,16,20,22,27,29)

	/* type            start    end      bank */
	{ GFXTYPE_STARS,   0x00000, 0x1ffff, 0 },
	{ GFXTYPE_SPRITES, 0x00000, 0x03fff, 0 },

	{ GFXTYPE_SPRITES, 0x04000, 0x04fff, 1 },
	{ GFXTYPE_SCROLL2, 0x04000, 0x07fff, 1 },

	{ GFXTYPE_SCROLL3, 0x00000, 0x03fff, 2 },

	{ GFXTYPE_SCROLL3, 0x04000, 0x07fff, 3 },
	{ GFXTYPE_SCROLL1, 0x07000, 0x07fff, 3 },
	{ 0 }
};


#define mapper_TK22B	{ 0x4000, 0x4000, 0x4000, 0x4000 }, mapper_TK22B_table
static const struct gfx_range mapper_TK22B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
	// bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
	// bank 2 = pin 14 (ROMs 3,7,11,15,19,21,26,28)
	// bank 3 = pin 12 (ROMS 4,8,12,16,20,22,27,29)

	/* type            start  end      bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x3fff, 0 },

	{ GFXTYPE_SPRITES, 0x4000, 0x5fff, 1 },
	{ GFXTYPE_SCROLL1, 0x6000, 0x7fff, 1 },

	{ GFXTYPE_SCROLL3, 0x0000, 0x3fff, 2 },

	{ GFXTYPE_SCROLL2, 0x4000, 0x7fff, 3 },
	{ 0 }
};


#define mapper_WL24B	{ 0x8000, 0x8000, 0, 0 }, mapper_WL24B_table
static const struct gfx_range mapper_WL24B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 16 (ROMs 1,3,5,7)
	// bank 1 = pin 12 (ROMs 10,12,14,16,20,22,24,26)
	// pin 14 and pin 19 are never enabled

	/* type            start  end      bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x4fff, 0 },
	{ GFXTYPE_SCROLL3, 0x5000, 0x6fff, 0 },
	{ GFXTYPE_SCROLL1, 0x7000, 0x7fff, 0 },

	{ GFXTYPE_SCROLL2, 0x0000, 0x3fff, 1 },
	{ 0 }
};


#define mapper_S224B	{ 0x8000, 0, 0, 0 }, mapper_S224B_table
static const struct gfx_range mapper_S224B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 16 (ROMs 1,3,5,7)
	// pin 12 & pin 14 give an alternate half-size mapping which would allow to
	// populate the 8-bit ROM sockets instead of the 16-bit ones:
	// pin 12
	// 0 00000 - 03fff
	// pin 14
	// 0 04000 - 043ff
	// 1 04400 - 04bff
	// 2 06000 - 07fff
	// 3 04c00 - 05fff
	// pin 19 is never enabled

	/* type            start  end      bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x43ff, 0 },
	{ GFXTYPE_SCROLL1, 0x4400, 0x4bff, 0 },
	{ GFXTYPE_SCROLL3, 0x4c00, 0x5fff, 0 },
	{ GFXTYPE_SCROLL2, 0x6000, 0x7fff, 0 },
	{ 0 }
};


#define mapper_YI24B	{ 0x8000, 0, 0, 0 }, mapper_YI24B_table
static const struct gfx_range mapper_YI24B_table[] =
{
	// verified from JED:
	// bank 0 = pin 16 (ROMs 1,3,5,7)
	// pin 12 & pin 14 give an alternate half-size mapping which would allow to
	// populate the 8-bit ROM sockets instead of the 16-bit ones:
	// pin 12
	// 0 0000-1fff
	// 3 2000-3fff
	// pin 14
	// 1 4000-47ff
	// 2 4800-7fff
	// pin 19 is never enabled

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x1fff, 0 },
	{ GFXTYPE_SCROLL3, 0x2000, 0x3fff, 0 },
	{ GFXTYPE_SCROLL1, 0x4000, 0x47ff, 0 },
	{ GFXTYPE_SCROLL2, 0x4800, 0x7fff, 0 },
	{ 0 }
};


// AR24B and AR22B are equivalent, but since we could dump both PALs we are
// documenting both.

#define mapper_AR24B	{ 0x8000, 0, 0, 0 }, mapper_AR24B_table
static const struct gfx_range mapper_AR24B_table[] =
{
	// verified from JED:
	// bank 0 = pin 16 (ROMs 1,3,5,7)
	// pin 12 & pin 14 give an alternate half-size mapping which would allow to
	// populate the 8-bit ROM sockets instead of the 16-bit ones:
	// pin 12
	// 0 0000-2fff
	// 1 3000-3fff
	// pin 14
	// 2 4000-5fff
	// 3 6000-7fff
	// pin 19 is never enabled

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
	{ GFXTYPE_SCROLL1, 0x3000, 0x3fff, 0 },
	{ GFXTYPE_SCROLL2, 0x4000, 0x5fff, 0 },
	{ GFXTYPE_SCROLL3, 0x6000, 0x7fff, 0 },
	{ 0 }
};

#define mapper_AR22B	{ 0x4000, 0x4000, 0, 0 }, mapper_AR22B_table
static const struct gfx_range mapper_AR22B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
	// bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
	// pins 12 and 14 are tristated

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
	{ GFXTYPE_SCROLL1, 0x3000, 0x3fff, 0 },

	{ GFXTYPE_SCROLL2, 0x4000, 0x5fff, 1 },
	{ GFXTYPE_SCROLL3, 0x6000, 0x7fff, 1 },
	{ 0 }
};


#define mapper_O224B	{ 0x8000, 0x4000, 0, 0 }, mapper_O224B_table
static const struct gfx_range mapper_O224B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 19 (ROMs 2,4,6,8)
	// bank 1 = pin 12 (ROMs 10,12,14,16,20,22,24,26)
	// pin 16 & pin 14 appear to be an alternate half-size mapping for bank 0
	// but scroll1 is missing:
	// pin 16
	// 2 00c00 - 03bff
	// 3 03c00 - 03fff
	// pin 14
	// 3 04000 - 04bff
	// 0 04c00 - 07fff

	/* type            start   end     bank */
	{ GFXTYPE_SCROLL1, 0x0000, 0x0bff, 0 },
	{ GFXTYPE_SCROLL2, 0x0c00, 0x3bff, 0 },
	{ GFXTYPE_SCROLL3, 0x3c00, 0x4bff, 0 },
	{ GFXTYPE_SPRITES, 0x4c00, 0x7fff, 0 },

	{ GFXTYPE_SPRITES, 0x8000, 0xa7ff, 1 },
	{ GFXTYPE_SCROLL2, 0xa800, 0xb7ff, 1 },
	{ GFXTYPE_SCROLL3, 0xb800, 0xbfff, 1 },
	{ 0 }
};


#define mapper_MS24B	{ 0x8000, 0, 0, 0 }, mapper_MS24B_table
static const struct gfx_range mapper_MS24B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 16 (ROMs 1,3,5,7)
	// pin 14 duplicates pin 16 allowing to populate the 8-bit ROM sockets
	// instead of the 16-bit ones.
	// pin 12 is enabled only for sprites:
	// 0 0000-3fff
	// pin 19 is never enabled

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x3fff, 0 },
	{ GFXTYPE_SCROLL1, 0x4000, 0x4fff, 0 },
	{ GFXTYPE_SCROLL2, 0x5000, 0x6fff, 0 },
	{ GFXTYPE_SCROLL3, 0x7000, 0x7fff, 0 },
	{ 0 }
};


#define mapper_CK24B	{ 0x8000, 0, 0, 0 }, mapper_CK24B_table
static const struct gfx_range mapper_CK24B_table[] =
{
	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
	{ GFXTYPE_SCROLL1, 0x3000, 0x3fff, 0 },
	{ GFXTYPE_SCROLL2, 0x4000, 0x6fff, 0 },
	{ GFXTYPE_SCROLL3, 0x7000, 0x7fff, 0 },
	{ 0 }
};


#define mapper_NM24B	{ 0x8000, 0, 0, 0 }, mapper_NM24B_table
static const struct gfx_range mapper_NM24B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 16 (ROMs 1,3,5,7)
	// pin 12 & pin 14 give an alternate half-size mapping which would allow to
	// populate the 8-bit ROM sockets instead of the 16-bit ones:
	// pin 12
	// 0 00000 - 03fff
	// 2 00000 - 03fff
	// pin 14
	// 1 04000 - 047ff
	// 0 04800 - 067ff
	// 2 04800 - 067ff
	// 3 06800 - 07fff
	// pin 19 is never enabled

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x3fff, 0 },
	{ GFXTYPE_SCROLL2, 0x0000, 0x3fff, 0 },
	{ GFXTYPE_SCROLL1, 0x4000, 0x47ff, 0 },
	{ GFXTYPE_SPRITES, 0x4800, 0x67ff, 0 },
	{ GFXTYPE_SCROLL2, 0x4800, 0x67ff, 0 },
	{ GFXTYPE_SCROLL3, 0x6800, 0x7fff, 0 },
	{ 0 }
};


// CA24B and CA22B are equivalent, but since we could dump both PALs we are
// documenting both.

#define mapper_CA24B	{ 0x8000, 0, 0, 0 }, mapper_CA24B_table
static const struct gfx_range mapper_CA24B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 16 (ROMs 1,3,5,7)
	// pin 12 & pin 14 give an alternate half-size mapping which would allow to
	// populate the 8-bit ROM sockets instead of the 16-bit ones:
	// pin 12
	// 0 0000-2fff
	// 2 0000-2fff
	// 3 3000-3fff
	// pin 14
	// 3 4000-4fff
	// 1 5000-57ff
	// 0 5800-7fff
	// 2 5800-7fff
	// pin 19 is never enabled (actually it is always enabled when PAL pin 1 is 1, purpose unknown)

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
	{ GFXTYPE_SCROLL2, 0x0000, 0x2fff, 0 },
	{ GFXTYPE_SCROLL3, 0x3000, 0x4fff, 0 },
	{ GFXTYPE_SCROLL1, 0x5000, 0x57ff, 0 },
	{ GFXTYPE_SPRITES, 0x5800, 0x7fff, 0 },
	{ GFXTYPE_SCROLL2, 0x5800, 0x7fff, 0 },
	{ 0 }
};

#define mapper_CA22B	{ 0x4000, 0x4000, 0, 0 }, mapper_CA22B_table
static const struct gfx_range mapper_CA22B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
	// bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
	// pin 12 and pin 14 are never enabled

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
	{ GFXTYPE_SCROLL2, 0x0000, 0x2fff, 0 },
	{ GFXTYPE_SCROLL3, 0x3000, 0x3fff, 0 },

	{ GFXTYPE_SCROLL3, 0x4000, 0x4fff, 1 },
	{ GFXTYPE_SCROLL1, 0x5000, 0x57ff, 1 },
	{ GFXTYPE_SPRITES, 0x5800, 0x7fff, 1 },
	{ GFXTYPE_SCROLL2, 0x5800, 0x7fff, 1 },
	{ 0 }
};


#define mapper_STF29	{ 0x8000, 0x8000, 0x8000, 0 }, mapper_STF29_table
static const struct gfx_range mapper_STF29_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 19 (ROMs 5,6,7,8)
	// bank 1 = pin 14 (ROMs 14,15,16,17)
	// bank 2 = pin 12 (ROMS 24,25,26,27)

	/* type            start    end      bank */
	{ GFXTYPE_SPRITES, 0x00000, 0x07fff, 0 },

	{ GFXTYPE_SPRITES, 0x08000, 0x0ffff, 1 },

	{ GFXTYPE_SPRITES, 0x10000, 0x11fff, 2 },
	{ GFXTYPE_SCROLL3, 0x02000, 0x03fff, 2 },
	{ GFXTYPE_SCROLL1, 0x04000, 0x04fff, 2 },
	{ GFXTYPE_SCROLL2, 0x05000, 0x07fff, 2 },
	{ 0 }
};


// RT24B and RT22B are equivalent, but since we could dump both PALs we are
// documenting both.

#define mapper_RT24B	{ 0x8000, 0x8000, 0, 0 }, mapper_RT24B_table
static const struct gfx_range mapper_RT24B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 16 (ROMs 1,3,5,7)
	// bank 1 = pin 19 (ROMs 2,4,6,8)
	// pin 12 & pin 14 are never enabled

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x53ff, 0 },
	{ GFXTYPE_SCROLL1, 0x5400, 0x6fff, 0 },
	{ GFXTYPE_SCROLL3, 0x7000, 0x7fff, 0 },

	{ GFXTYPE_SCROLL3, 0x0000, 0x3fff, 1 },
	{ GFXTYPE_SCROLL2, 0x2800, 0x7fff, 1 },
	{ GFXTYPE_SPRITES, 0x5400, 0x7fff, 1 },
	{ 0 }
};

#define mapper_RT22B	{ 0x4000, 0x4000, 0x4000, 0x4000 }, mapper_RT22B_table
static const struct gfx_range mapper_RT22B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
	// bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
	// bank 2 = pin 14 (ROMs 3,7,11,15,19,21,26,28)
	// bank 3 = pin 12 (ROMS 4,8,12,16,20,22,27,29)

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x3fff, 0 },

	{ GFXTYPE_SPRITES, 0x4000, 0x53ff, 1 },
	{ GFXTYPE_SCROLL1, 0x5400, 0x6fff, 1 },
	{ GFXTYPE_SCROLL3, 0x7000, 0x7fff, 1 },

	{ GFXTYPE_SCROLL3, 0x0000, 0x3fff, 2 },
	{ GFXTYPE_SCROLL2, 0x2800, 0x3fff, 2 },

	{ GFXTYPE_SCROLL2, 0x4000, 0x7fff, 3 },
	{ GFXTYPE_SPRITES, 0x5400, 0x7fff, 3 },
	{ 0 }
};


#define mapper_KD29B	{ 0x8000, 0x8000, 0, 0 }, mapper_KD29B_table
static const struct gfx_range mapper_KD29B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 19 (ROMs 1,2,3,4)
	// bank 1 = pin 14 (ROMs 10,11,12,13)
	// pin 12 is never enabled

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x7fff, 0 },

	{ GFXTYPE_SPRITES, 0x8000, 0x8fff, 1 },
	{ GFXTYPE_SCROLL2, 0x9000, 0xbfff, 1 },
	{ GFXTYPE_SCROLL1, 0xc000, 0xd7ff, 1 },
	{ GFXTYPE_SCROLL3, 0xd800, 0xffff, 1 },
	{ 0 }
};


#define mapper_CC63B	{ 0x8000, 0x8000, 0, 0 }, mapper_CC63B_table
static const struct gfx_range mapper_CC63B_table[] =
{
	// verified from PAL dump:
	// bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
	// bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
	// pins 12,13,14,15 are always enabled

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x7fff, 0 },
	{ GFXTYPE_SCROLL2, 0x0000, 0x7fff, 0 },

	{ GFXTYPE_SPRITES, 0x8000, 0xffff, 1 },
	{ GFXTYPE_SCROLL1, 0x8000, 0xffff, 1 },
	{ GFXTYPE_SCROLL2, 0x8000, 0xffff, 1 },
	{ GFXTYPE_SCROLL3, 0x8000, 0xffff, 1 },
	{ 0 }
};


#define mapper_KR63B	{ 0x8000, 0x8000, 0, 0 }, mapper_KR63B_table
static const struct gfx_range mapper_KR63B_table[] =
{
	// verified from PAL dump:
	// bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
	// bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
	// pins 12,13,14,15 are always enabled

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x7fff, 0 },
	{ GFXTYPE_SCROLL2, 0x0000, 0x7fff, 0 },

	{ GFXTYPE_SCROLL1, 0x8000, 0x9fff, 1 },
	{ GFXTYPE_SPRITES, 0x8000, 0xcfff, 1 },
	{ GFXTYPE_SCROLL2, 0x8000, 0xcfff, 1 },
	{ GFXTYPE_SCROLL3, 0xd000, 0xffff, 1 },
	{ 0 }
};


#define mapper_S9263B	{ 0x8000, 0x8000, 0x8000, 0 }, mapper_S9263B_table
static const struct gfx_range mapper_S9263B_table[] =
{
	// verified from PAL dump:
	// FIXME there is some problem with this dump since pin 14 is never enabled
	// instead of being the same as pin 15 as expected
	// bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
	// bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
	// bank2 = pin 15 (ROMs 10,12) & pin 14 (ROMs 11,13)
	// pins 12 and 13 are the same as 14 and 15

	/* type            start    end      bank */
	{ GFXTYPE_SPRITES, 0x00000, 0x07fff, 0 },

	{ GFXTYPE_SPRITES, 0x08000, 0x0ffff, 1 },

	{ GFXTYPE_SPRITES, 0x10000, 0x11fff, 2 },
	{ GFXTYPE_SCROLL3, 0x02000, 0x03fff, 2 },
	{ GFXTYPE_SCROLL1, 0x04000, 0x04fff, 2 },
	{ GFXTYPE_SCROLL2, 0x05000, 0x07fff, 2 },
	{ 0 }
};


// VA22B and VA63B are equivalent, but since we could dump both PALs we are
// documenting both.

#define mapper_VA22B	{ 0x4000, 0x4000, 0, 0 }, mapper_VA22B_table
static const struct gfx_range mapper_VA22B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
	// bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
	// pin 12 and pin 14 are never enabled

	/* type                                                                  start    end      bank */
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x03fff, 0 },
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x04000, 0x07fff, 1 },
	{ 0 }
};


#define mapper_VA63B	{ 0x8000, 0, 0, 0 }, mapper_VA63B_table
static const struct gfx_range mapper_VA63B_table[] =
{
	// verified from PAL dump (PAL # uncertain):
	// bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
	// pins 12,13,14,15,16,17 are never enabled

	/* type                                                                  start    end      bank */
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x07fff, 0 },
	{ 0 }
};


#define mapper_Q522B	{ 0x8000, 0, 0, 0 }, mapper_Q522B_table
static const struct gfx_range mapper_Q522B_table[] =
{
	/* type                              start   end     bank */
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x0000, 0x6fff, 0 },
	{ GFXTYPE_SCROLL3,                   0x7000, 0x77ff, 0 },
	{ GFXTYPE_SCROLL1,                   0x7800, 0x7fff, 0 },
	{ 0 }
};


#define mapper_TK263B	{ 0x8000, 0x8000, 0, 0 }, mapper_TK263B_table
static const struct gfx_range mapper_TK263B_table[] =
{
	// verified from PAL dump:
	// bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
	// bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
	// pins 12,13,14,15 are always enabled

	/* type                                                                  start    end      bank */
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x07fff, 0 },
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x08000, 0x0ffff, 1 },
	{ 0 }
};


#define mapper_CD63B	{ 0x8000, 0x8000, 0, 0 }, mapper_CD63B_table
static const struct gfx_range mapper_CD63B_table[] =
{
	/* type                              start   end     bank */
	{ GFXTYPE_SCROLL1,                   0x0000, 0x0fff, 0 },
	{ GFXTYPE_SPRITES,                   0x1000, 0x7fff, 0 },

	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x8000, 0xdfff, 1 },
	{ GFXTYPE_SCROLL3,                   0xe000, 0xffff, 1 },
	{ 0 }
};


#define mapper_PS63B	{ 0x8000, 0x8000, 0, 0 }, mapper_PS63B_table
static const struct gfx_range mapper_PS63B_table[] =
{
	/* type                              start   end     bank */
	{ GFXTYPE_SCROLL1,                   0x0000, 0x0fff, 0 },
	{ GFXTYPE_SPRITES,                   0x1000, 0x7fff, 0 },

	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x8000, 0xdbff, 1 },
	{ GFXTYPE_SCROLL3,                   0xdc00, 0xffff, 1 },
	{ 0 }
};


#define mapper_MB63B	{ 0x8000, 0x8000, 0x8000, 0 }, mapper_MB63B_table
static const struct gfx_range mapper_MB63B_table[] =
{
	/* type                              start    end      bank */
	{ GFXTYPE_SCROLL1,                   0x00000, 0x00fff, 0 },
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x01000, 0x07fff, 0 },

	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x08000, 0x0ffff, 1 },

	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x10000, 0x167ff, 2 },
	{ GFXTYPE_SCROLL3,                   0x16800, 0x17fff, 2 },
	{ 0 }
};


#define mapper_QD22B	{ 0x4000, 0, 0, 0 }, mapper_QD22B_table
static const struct gfx_range mapper_QD22B_table[] =
{
	// verified from PAL dump:
	// bank 0 = pin 19

	/* type            start   end     bank */
	{ GFXTYPE_SPRITES, 0x0000, 0x3fff, 0 },
	{ GFXTYPE_SCROLL1, 0x0000, 0x3fff, 0 },
	{ GFXTYPE_SCROLL2, 0x0000, 0x3fff, 0 },
	{ GFXTYPE_SCROLL3, 0x0000, 0x3fff, 0 },
	{ 0 }
};


#define mapper_qadj	{ 0x8000, 0, 0, 0 }, mapper_qadj_table
static const struct gfx_range mapper_qadj_table[] =
{
	/* type                              start   end     bank */
	{ GFXTYPE_SCROLL1,                   0x0000, 0x07ff, 0 },
	{ GFXTYPE_SCROLL3,                   0x0800, 0x1fff, 0 },
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x2000, 0x7fff, 0 },
	{ 0 }
};


#define mapper_qtono2j	{ 0x8000, 0x8000, 0, 0 }, mapper_qtono2j_table
static const struct gfx_range mapper_qtono2j_table[] =
{
	/* type                              start   end     bank */
	{ GFXTYPE_SCROLL1,                   0x0000, 0x0fff, 0 },
	{ GFXTYPE_SCROLL3,                   0x1000, 0x3fff, 0 },
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x4000, 0x7fff, 0 },

	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x8000, 0xffff, 1 },
	{ 0 }
};


#define mapper_RCM63B	{ 0x8000, 0x8000, 0x8000, 0x8000 }, mapper_RCM63B_table
static const struct gfx_range mapper_RCM63B_table[] =
{
	// verified from PAL dump:
	// bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
	// bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
	// bank0 = pin 15 (ROMs 10,12) & pin 14 (ROMs 11,13)
	// bank1 = pin 13 (ROMs 14,16) & pin 12 (ROMs 15,17)

	/* type                                                                  start    end      bank */
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x07fff, 0 },
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x08000, 0x0ffff, 1 },
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x10000, 0x17fff, 2 },
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x18000, 0x1ffff, 3 },
	{ 0 }
};


#define mapper_PKB10B	{ 0x8000, 0, 0, 0 }, mapper_PKB10B_table
static const struct gfx_range mapper_PKB10B_table[] =
{
	/* type                              start   end     bank */
	{ GFXTYPE_SCROLL1,                   0x0000, 0x0fff, 0 },
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x1000, 0x5fff, 0 },
	{ GFXTYPE_SCROLL3,                   0x6000, 0x7fff, 0 },
	{ 0 }
};


#define mapper_pang3	{ 0x8000, 0x8000, 0, 0 }, mapper_pang3_table
static const struct gfx_range mapper_pang3_table[] =
{
	/* type                              start   end     bank */
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x0000, 0x7fff, 0 },

	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x8000, 0x9fff, 1 },
	{ GFXTYPE_SCROLL1,                   0xa000, 0xbfff, 1 },
	{ GFXTYPE_SCROLL3,                   0xc000, 0xffff, 1 },
	{ 0 }
};


#define mapper_sfzch	{ 0x20000, 0, 0, 0 }, mapper_sfzch_table
static const struct gfx_range mapper_sfzch_table[] =
{
	/* type                                                                  start    end      bank */
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 0 },
	{ 0 }
};


#define mapper_cps1frog	{ 0x020000, 0, 0, 0 }, mapper_cps1frog_table
static const struct gfx_range mapper_cps1frog_table[] =
{
	{ GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x000001, 0x01ffff, 0 },
	{ 0 }
};

/*	I don't know if CPS2 ROM boards use PALs as well; since all games seem to be
	well behaved, I'll just assume that there is no strong checking of gfx type.
	(sprites are not listed here because they are addressed linearly by the CPS2
	sprite code)	*/

#define mapper_cps2	{ 0x20000, 0x20000, 0, 0 }, mapper_cps2_table
static const struct gfx_range mapper_cps2_table[] =
{
	/* type                                                start    end      bank */
	{ GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 1 },	// 20000-3ffff physical
	{ 0 }
};


static const struct CPS1config cps1_config_table[] =
{
	/* name         CPSB             gfx range     in2  in3  out2  bootleg */
	/*		 ID		 bank mapper   addr addr addr   kludge */
	{"1941",	CPS_B_05,	mapper_YI24B },
	{"1941r1",      CPS_B_05,	mapper_YI24B },
	{"1941u",       CPS_B_05,	mapper_YI24B },
	{"1941j",       CPS_B_05,	mapper_YI24B },					/* wrong, this set uses YI22B, still not dumped */
	//
	{"3wonders",	CPS_B_21_BT1,	mapper_RT24B },
	{"3wondersr1",	CPS_B_21_BT1,	mapper_RT24B },
	{"3wondersu",	CPS_B_21_BT1,	mapper_RT24B },
	{"wonder3",	CPS_B_21_BT1,	mapper_RT22B },					/* equivalent to RT24B */
	{"3wondersb",	CPS_B_21_BT1,	mapper_RT24B,	0x36, 0x00, 0x00, 0x88 },	/* same as 3wonders except some registers are hard wired rather than written to */
	{"3wondersh",	HACK_B_2,	mapper_RT24B },					/* one port is changed from 3wonders, and no protection */
	//
	{"unsquad",	CPS_B_11,	mapper_AR24B },
	{"area88",	CPS_B_11,	mapper_AR22B },					/* equivalent to AR24B */
	{"area88r",	CPS_B_21_DEF,	mapper_AR22B },
	//
	{"captcomm",	CPS_B_21_BT3,	mapper_CC63B,	0x36, 0x38, 0x34 },
	{"captcommr1",	CPS_B_21_BT3,	mapper_CC63B,	0x36, 0x38, 0x34 },
	{"captcommu",	CPS_B_21_BT3,	mapper_CC63B,	0x36, 0x38, 0x34 },
	{"captcommj",	CPS_B_21_BT3,	mapper_CC63B,	0x36, 0x38, 0x34 },
	{"captcommjr1",	CPS_B_21_BT3,	mapper_CC63B,	0x36, 0x38, 0x34 },
	{"captcommb",	CPS_B_21_BT3,	mapper_CC63B,	0x36, 0x38, 0x34, 3 },
	{"captcommb2",	CPS_B_21_BT3,	mapper_CC63B,	0x36, 0x38, 0x34 },
	//
	{"cawing",	CPS_B_16,	mapper_CA24B },
	{"cawingr1",	CPS_B_16,	mapper_CA24B },
	{"cawingu",	CPS_B_16,	mapper_CA24B },
	{"cawingj",	CPS_B_16,	mapper_CA22B },					/* equivalent to CA24B */
	//
	{"cworld2j",	CPS_B_21_BT6,	mapper_Q522B,	0x36, 0x00, 0x34 },		/* (ports 36, 34 probably leftover input code from another game) */
	{"cworld2ja",	CPS_B_21_DEF,	mapper_Q522B },					/* patched set, no battery, could be desuicided */
	{"cworld2jb",	CPS_B_21_BT6,	mapper_Q522B,	0x36, 0x00, 0x34 },
	//
	{"dino",	CPS_B_21_QS2,	mapper_CD63B },					/* layer enable never used */
	{"dinou",	CPS_B_21_QS2,	mapper_CD63B },					/* layer enable never used */
	{"dinoj",	CPS_B_21_QS2,	mapper_CD63B },					/* layer enable never used */
	{"dinopic",	CPS_B_21_QS2,	mapper_CD63B },					/* layer enable never used */
	{"dinopic2",	CPS_B_21_QS2,	mapper_CD63B },					/* layer enable never used */
	{"dinohunt",	CPS_B_21_DEF,	mapper_CD63B },					/* Chinese bootleg */
	{"dinoeh",	CPS_B_21_QS2,	mapper_CD63B },
	{"dinoh",	CPS_B_21_DEF,	mapper_CD63B,	0x36 },
	{"dinohc",	CPS_B_21_DEF,	mapper_CD63B,	0x36 },
	{"dinopic3",	CPS_B_21_QS2,	mapper_CD63B },
	{"dinopic4",	CPS_B_21_QS2,	mapper_CD63B },
	{"dinot",	CPS_B_21_DEF,	mapper_CD63B,	0x36 },
	{"dinotpic",	CPS_B_21_QS2,	mapper_CD63B,	0x00, 0x00, 0x00, 0x0D },
	//
	{"dynwar",	CPS_B_02,	mapper_TK22B },					/* wrong, this set uses TK24B1, dumped but equations still not added */
	{"dynwara",	CPS_B_02,	mapper_TK22B },
	{"dynwarj",	CPS_B_02,	mapper_TK22B },
	{"dynwarjr",	CPS_B_21_DEF,	mapper_TK22B },					/* wrong, this set uses TK163B, still not dumped */
	//
	{"ffight",	CPS_B_04,	mapper_S224B },
	{"ffighta",	CPS_B_04,	mapper_S224B },
	{"ffightj",	CPS_B_04,	mapper_S224B },					/* wrong, this set uses S222B, still non dumped */
	{"ffightj1",	CPS_B_01,	mapper_S224B },					/* wrong, this set uses S222B, still non dumped */
	{"ffightj2",	CPS_B_02,	mapper_S224B },					/* wrong, this set uses S222B, still non dumped */
	{"ffightj3",	CPS_B_05,	mapper_S224B },
	{"ffightjh",	CPS_B_01,	mapper_S224B },					/* wrong, ffightjh hack doesn't even use the S222B PAL, since replaced with a GAL. */
	{"ffightu",	CPS_B_04,	mapper_S224B },
	{"ffightu1",	CPS_B_04,	mapper_S224B },
	{"ffightu2",	CPS_B_04,	mapper_S224B },
	{"ffightua",	CPS_B_01,	mapper_S224B },
	{"ffightub",	CPS_B_03,	mapper_S224B },
	{"ffightuc",	CPS_B_05,	mapper_S224B },
	//
	{"forgottn",	CPS_B_01,	mapper_LW621 },
	{"forgottna",	CPS_B_01,	mapper_LW621 },
	{"forgottnu",	CPS_B_01,	mapper_LW621 },
	{"forgottnu1",	CPS_B_01,	mapper_LWCHR },
	{"forgottnua",	CPS_B_01,	mapper_LWCHR },
	{"forgottnuaa",	CPS_B_01,	mapper_LWCHR },
	{"lostwrld",	CPS_B_01,	mapper_LWCHR },
	{"lostwrldo",	CPS_B_01,	mapper_LWCHR },
	//
	{"ganbare",	CPS_B_21_DEF,	mapper_sfzch },
	//
	{"ghouls",	CPS_B_01,	mapper_DM620 },
	{"ghoulsu",	CPS_B_01,	mapper_DM620 },
	{"daimakai",	CPS_B_01,	mapper_DM22A },					/* equivalent to DM620 */
	{"daimakair",	CPS_B_21_DEF,	mapper_DAM63B },				/* equivalent to DM620, also CPS_B_21_DEF is equivalent to CPS_B_01 */
	{"daimakaib",	HACK_H_5,	mapper_DM22A },
	//
	{"knights",	CPS_B_21_BT4,	mapper_KR63B,	0x36, 0x00, 0x34 },
	{"knightsu",	CPS_B_21_BT4,	mapper_KR63B,	0x36, 0x00, 0x34 },
	{"knightsj",	CPS_B_21_BT4,	mapper_KR63B,	0x36, 0x00, 0x34 },		/* PAL could be different if B-Board is 90629B */
	{"knightsja",	CPS_B_21_BT4,	mapper_KR63B,	0x36, 0x00, 0x34 },
	{"knightsh",	CPS_B_21_DEF,	mapper_KR63B,	0x36, 0x00, 0x34 },
	{"knightsh2",	CPS_B_21_DEF,	mapper_KR63B,	0x36, 0x00, 0x34 },
	{"knightsb",	CPS_B_21_BT4,	mapper_KR63B,	0x36, 0x00, 0x34 },
	{"knightsb2",	CPS_B_21_BT4,	mapper_KR63B,	0x36, 0x00, 0x34, 4 },
	{"knightsb3",	CPS_B_21_DEF,	mapper_KR63B,	0x36, 0x00, 0x34 },
	{"knightsb4",	CPS_B_21_BT4,	mapper_KR63B,	0x36, 0x00, 0x34 },
	//
	{"kod",		CPS_B_21_BT2,	mapper_KD29B,	0x36, 0x00, 0x34 },
	{"kodr1",	CPS_B_21_BT2,	mapper_KD29B,	0x36, 0x00, 0x34 },
	{"kodu",	CPS_B_21_BT2,	mapper_KD29B,	0x36, 0x00, 0x34 },
	{"kodj",	CPS_B_21_BT2,	mapper_KD29B,	0x36, 0x00, 0x34 },
	{"kodja",	CPS_B_21_BT2,	mapper_KD29B,	0x36, 0x00, 0x34 },		/* wrong, this set uses KD22B, still not dumped */
	{"kodb",	CPS_B_21_BT2,	mapper_KD29B,	0x36, 0x00, 0x34 },		/* bootleg, doesn't use multiply protection */
	{"kodda",	CPS_B_21_DEF,	mapper_KD29B,	0x36, 0x00, 0x34 },
	{"kodh",	CPS_B_21_DEF,	mapper_KD29B,	0x36, 0x00, 0x34 },
	//
	{"mbombrd",	CPS_B_21_QS5,	mapper_MB63B },
	{"mbombrdj",	CPS_B_21_QS5,	mapper_MB63B },
	//
	{"megaman",	CPS_B_21_DEF,	mapper_RCM63B },
	{"megamana",	CPS_B_21_DEF,	mapper_RCM63B },
	{"rockmanj",	CPS_B_21_DEF,	mapper_RCM63B },
	//
	{"mercs",	CPS_B_12,	mapper_O224B,	0x36, 0x00, 0x34 },
	{"mercsu",	CPS_B_12,	mapper_O224B,	0x36, 0x00, 0x34 },
	{"mercsur1",	CPS_B_12,	mapper_O224B,	0x36, 0x00, 0x34 },
	{"mercsj",	CPS_B_12,	mapper_O224B,	0x36, 0x00, 0x34 },		/* wrong, this set uses O222B, still non dumped */
	//
	{"msword",	CPS_B_13,	mapper_MS24B },
	{"mswordr1",	CPS_B_13,	mapper_MS24B },
	{"mswordu",	CPS_B_13,	mapper_MS24B },
	{"mswordj",	CPS_B_13,	mapper_MS24B },					/* wrong, this set uses MS22B, still non dumped */
	//
	{"mtwins",	CPS_B_14,	mapper_CK24B },
	{"chikij",	CPS_B_14,	mapper_CK24B },					/* PAL used could be CK22B */
	//
	{"nemo",	CPS_B_15,	mapper_NM24B },
	{"nemoj",	CPS_B_15,	mapper_NM24B },					/* wrong, this set uses NM22B, still non dumped */
	{"nemor1",	CPS_B_15,	mapper_NM24B },
	//
	{"pnickj",	CPS_B_21_DEF,	mapper_PKB10B },
	//
	{"qtono2j",	CPS_B_21_DEF,	mapper_qtono2j,	0x36, 0x38, 0x34 },		/* (ports 36, 38, 34 probably leftover input code from another game) */
	//
	{"pang3",	CPS_B_21_DEF,	mapper_pang3 },					/* EEPROM port is among the CPS registers (handled by DRIVER_INIT) */	// should use one of these three CP1B1F,CP1B8K,CP1B9KA still not dumped
	{"pang3r1",	CPS_B_21_DEF,	mapper_pang3 },
	{"pang3r1a",	CPS_B_21_DEF,	mapper_pang3 },					/* EEPROM port is among the CPS registers (handled by DRIVER_INIT) */	// should use one of these three CP1B1F,CP1B8K,CP1B9KA still not dumped
	{"pang3j",	CPS_B_21_DEF,	mapper_pang3 },					/* EEPROM port is among the CPS registers (handled by DRIVER_INIT) */	// should use one of these three CP1B1F,CP1B8K,CP1B9KA still not dumped
	{"pang3b",	CPS_B_21_DEF,	mapper_pang3 },
	{"pang3b2",	CPS_B_04,	mapper_pang3 },
	{"pang3b3",	CPS_B_04,	mapper_pang3 },
	//
	{"qad",		CPS_B_21_BT7,	mapper_QD22B,	0x36 },				/* TODO: layer enable (port 36 probably leftover input code from another game) */
	{"qadjr",	CPS_B_21_DEF,	mapper_qadj,	0x36, 0x38, 0x34 },		/* (ports 36, 38, 34 probably leftover input code from another game) */
	//
	{"punisher",	CPS_B_21_QS3,	mapper_PS63B },
	{"punisherb",	CPS_B_21_QS3,	mapper_PS63B },
	{"punisheru",	CPS_B_21_QS3,	mapper_PS63B },
	{"punisherh",	CPS_B_21_QS3,	mapper_PS63B },
	{"punisherj",	CPS_B_21_QS3,	mapper_PS63B },
	{"punisherbz",	CPS_B_21_DEF,	mapper_PS63B },					/* Chinese bootleg */
	{"punipic",	CPS_B_21_QS3,	mapper_PS63B },
	{"punipic2",	CPS_B_21_QS3,	mapper_PS63B },
	{"punipic3",	CPS_B_21_QS3,	mapper_PS63B },
	//
	{"slammast",	CPS_B_21_QS4,	mapper_MB63B },
	{"slammastu",	CPS_B_21_QS4,	mapper_MB63B },
	{"mbomberj",	CPS_B_21_QS4,	mapper_MB63B },
	{"slampic",	CPS_B_21_QS4,	mapper_MB63B },
	//
	{"sfzch",	CPS_B_21_DEF,	mapper_sfzch },
	//
	{"strider",	CPS_B_01,	mapper_ST24M1 },
	{"striderua",	CPS_B_01,	mapper_ST24M1 },				/* wrong, this set uses ST24B2, still non dumped */
	{"striderj",	CPS_B_01,	mapper_ST22B },					/* equivalent to ST24M1 */
	{"striderjr",	CPS_B_01,	mapper_ST24M1 },				/* wrong, PAL used could be STH63B, check CPS_B */
	{"strideruc",	CPS_B_17,	mapper_ST24M1 },
	//
	{"willow",	CPS_B_03,	mapper_WL24B },
	{"willowj",	CPS_B_03,	mapper_WL24B },					/* wrong, this set uses WL22B, still non dumped */
	{"willowu",	CPS_B_03,	mapper_WL24B },
	{"willowuo",	CPS_B_03,	mapper_WL24B },
	//
	{"varth",	CPS_B_04,	mapper_VA63B },					/* CPSB test has been patched out (60=0008) register is also written to, possibly leftover from development */	// wrong, this set uses VA24B, still non dumped
	{"varthr1",	CPS_B_04,	mapper_VA63B },					/* CPSB test has been patched out (60=0008) register is also written to, possibly leftover from development */	// wrong, this set uses VA24B, still non dumped
	{"varthu",	CPS_B_04,	mapper_VA63B },					/* CPSB test has been patched out (60=0008) register is also written to, possibly leftover from development */
	{"varthj",	CPS_B_21_BT5,	mapper_VA22B },					/* CPSB test has been patched out (72=0001) register is also written to, possibly leftover from development */
	{"varthjr",	CPS_B_21_BT5,	mapper_VA22B },
	{"varthb",	CPS_B_04,	mapper_VA63B,	0x00, 0x00, 0x00, 0x0F },
	//
	{"wofch",	CPS_B_21_DEF,	mapper_TK263B },
	{"wofchdx",	CPS_B_21_DEF,	mapper_TK263B },
	//
	{"sf2hf",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2hfu",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2hfj",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2hfjb",	HACK_SF_JB,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2hfjb2",	HACK_SF_JB,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	//
	{"wof",		CPS_B_21_QS1,	mapper_TK263B },
	{"wofr1",	CPS_B_21_DEF,	mapper_TK263B },				/* patched set coming from a desuicided board? */
	{"wofa",	CPS_B_21_DEF,	mapper_TK263B },				/* patched set coming from a desuicided board? */
	{"wofu",	CPS_B_21_QS1,	mapper_TK263B },
	{"wofj",	CPS_B_21_QS1,	mapper_TK263B },
	{"wofhfh",	CPS_B_21_DEF,	mapper_TK263B,	0x36 },				/* Chinese bootleg */
	{"wofah",	CPS_B_21_DEF,	mapper_TK263B },
	{"wofaha",	CPS_B_21_DEF,	mapper_TK263B },
	{"wofahb",	CPS_B_21_DEF,	mapper_TK263B },
	{"wofjh",	CPS_B_21_QS1,	mapper_TK263B },
	{"wofb",	CPS_B_21_DEF,	mapper_TK263B },
	{"wofsjb",	CPS_B_21_DEF,	mapper_TK263B,	0x36 },
	{"wof3js",	CPS_B_21_DEF,	mapper_TK263B },
	{"wofh",	HACK_WOF_H,	mapper_TK263B,	0x00, 0x00, 0x00, 0x64 },
	{"wofha",	HACK_WOF_H,	mapper_TK263B,	0x00, 0x00, 0x00, 0x64 },
	{"sgyxz",	HACK_WOF_H,	mapper_TK263B,	0x00, 0x00, 0x00, 0x64 },
	{"wof3jsa",	HACK_WOF_H,	mapper_TK263B,	0x00, 0x00, 0x00, 0x64 },
	{"wofsj",	HACK_WOF_H,	mapper_TK263B,	0x00, 0x00, 0x00, 0x64 },
	{"wofsja",	HACK_WOF_H,	mapper_TK263B,	0x00, 0x00, 0x00, 0x64 },
	{"wof3sj",	HACK_WOF_H,	mapper_TK263B,	0x00, 0x00, 0x00, 0x64 },
	{"wof3sja",	HACK_WOF_H,	mapper_TK263B,	0x00, 0x00, 0x00, 0x64 },
	//
	{"sf2",		CPS_B_11,	mapper_STF29,	0x36 },
	{"sf2eb",	CPS_B_17,	mapper_STF29,	0x36 },
	{"sf2ed",	CPS_B_05,	mapper_STF29,	0x36 },
	{"sf2ee",	CPS_B_18,	mapper_STF29,	0x3c },
	{"sf2ua",	CPS_B_17,	mapper_STF29,	0x36 },
	{"sf2ub",	CPS_B_17,	mapper_STF29,	0x36 },
	{"sf2uc",	CPS_B_12,	mapper_STF29,	0x36 },
	{"sf2ud",	CPS_B_05,	mapper_STF29,	0x36 },
	{"sf2ue",	CPS_B_18,	mapper_STF29,	0x3c },
	{"sf2uf",	CPS_B_15,	mapper_STF29,	0x36 },
	{"sf2ug",	CPS_B_11,	mapper_STF29,	0x36 },
	{"sf2ui",	CPS_B_14,	mapper_STF29,	0x36 },
	{"sf2uk",	CPS_B_17,	mapper_STF29,	0x36 },
	{"sf2j",	CPS_B_13,	mapper_STF29,	0x36 },
	{"sf2ja",	CPS_B_17,	mapper_STF29,	0x36 },
	{"sf2jc",	CPS_B_12,	mapper_STF29,	0x36 },
	{"sf2jf",	CPS_B_15,	mapper_STF29,	0x36 },
	{"sf2jh",	CPS_B_13,	mapper_STF29,	0x36 },
	{"sf2jl",	CPS_B_17,	mapper_STF29,	0x36 },
	{"sf2ebbl",	CPS_B_17,	mapper_STF29,	0x36, 0x00, 0x00, 1 },
	{"sf2ebbl2",	CPS_B_17,	mapper_STF29,	0x36, 0x00, 0x00, 1 },
	{"sf2ebbl3",	CPS_B_17,	mapper_STF29,	0x36, 0x00, 0x00, 1 },
	{"sf2stt",	CPS_B_17,	mapper_STF29,	0x36, 0x00, 0x00, 1 },
	{"sf2qp1",	CPS_B_17,	mapper_STF29,	0x36 },
	{"sf2thndr",	CPS_B_17,	mapper_STF29,	0x36 },
	{"sf2b",	CPS_B_17,	mapper_STF29,	0x36 },
	{"sf2b2",	CPS_B_17,	mapper_STF29,	0x36 },
	{"sf2b3",	CPS_B_17,	mapper_STF29,	0x36 },
	//
	{"sf2ce",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2ceea",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2ceua",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2ceub",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2ceuc",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2ceja",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2cejb",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2cejc",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2bhh",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2red",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2red2",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2acc",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2acca",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2accp2",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2cebltw",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2v004",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2v0042",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2v0043",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2dkot2",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2dongb",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2koryu",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2koryu2",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2koryu3",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2yyc",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2yyc2",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2amf",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },		/* probably wrong but this set is not completely dumped anyway */
	{"sf2amf2",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2amf3",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2amf4",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2amf5",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2amf6",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2amf7",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2amf8",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2cejabl",	HACK_B_1,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2cejab2",	HACK_B_1,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2rb",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2rb2",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2rb3",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2rb4",	HACK_B_1,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2rb5",	HACK_B_1,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2rb6",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2mega",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2mega2",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2sl73a",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2tlona",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2tlonb",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2tlonc",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2ceucbl",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2ceeabl",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2ceeab2",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2md",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2mdt",	CPS_B_21_DEF,	mapper_S9263B,	0x36, 0x00, 0x00, 1 },
	{"sf2mdta",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2mdtb",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2ceuabl",	HACK_B_1,	mapper_S9263B,	0x00, 0x00, 0x00, 2 },
	{"sf2ceuab2",	HACK_B_1,	mapper_S9263B,	0x00, 0x00, 0x00, 2 },
	{"sf2ceuab3",	HACK_B_1,	mapper_S9263B,	0x00, 0x00, 0x00, 2 },
	{"sf2ceuab4",	HACK_B_1,	mapper_S9263B,	0x00, 0x00, 0x00, 2 },
	{"sf2ceuab5",	HACK_B_1,	mapper_S9263B,	0x00, 0x00, 0x00, 2 },
	{"sf2ceuab6",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"sf2ceuab7",	CPS_B_21_DEF,	mapper_S9263B,	0x36 },
	{"cps1frog",	CPS_B_04,     mapper_cps1frog,	0x00, 0x00, 0x00, 0x89 },

	/* CPS2 games */
	{"cps2",	CPS_B_21_DEF,	mapper_cps2 },
	
	/* HBMAME extras */
	{"3wonders01", CPS_B_21_BT1, mapper_RT24B },
	{"3wonders02", CPS_B_21_BT1, mapper_RT24B },
	{"3wondersb01", CPS_B_21_BT1, mapper_RT24B },
	{"3wondrud", CPS_B_21_DEF, mapper_RT24B },
	{"captcomc", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomh", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcommh01", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcommh02", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcommh03", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcommh04", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcommh05", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcommh06", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms01", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms04", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms05", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms07", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms09", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms10", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms11", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms12", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms13", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms14", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms15", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms16", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms17", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms18", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms19", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms20", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms21", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms22", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms23", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms24", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms27", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms29", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms30", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms31", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms32", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms33", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms34", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms35", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms36", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms37", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms38", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms39", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms40", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms41", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms42", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms43", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms44", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms46", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms47", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms48", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms49", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms50", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms51", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms52", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms53", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms54", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms55", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms56", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms57", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms58", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcomms59", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"captcoud", CPS_B_21_DEF, mapper_CC63B, 0x36, 0x38, 0x34 },
	// {"cps1demo", CPS_B_04, mapper_demo, 0, 0, 0, 0x80 },
	// {"cps1frog", CPS_B_04, mapper_frog, 0, 0, 0, 0x80 },
	// {"cps1testm"0
	// {"cps1testma"0
	// {"cps1tests", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	// {"cps1testsa", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"daimakb", HACK_H_5, mapper_DM22A },
	{"dino08h2", CPS_B_21_QS2, mapper_CD63B },
	{"dino08h3", CPS_B_21_QS2, mapper_CD63B },
	{"dino08hp", CPS_B_21_QS2, mapper_CD63B },
	{"dinob", CPS_B_21_QS2, mapper_CD63B, 0, 0, 0, 0x0F },
	{"dinobt", CPS_B_21_QS2, mapper_CD63B },
	{"dinobtpp", CPS_B_21_QS2, mapper_CD63B },
	{"dinocgba", CPS_B_21_QS2, mapper_CD63B },
	{"dinocgbb", CPS_B_21_QS2, mapper_CD63B },
	{"dinocgbc", CPS_B_21_QS2, mapper_CD63B },
	{"dinoeh", CPS_B_21_QS2, mapper_CD63B },
	{"dinoex", CPS_B_21_DEF, mapper_CD63B },
	{"dinoh", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinoha", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinohb", CPS_B_21_QS2, mapper_CD63B, 0, 0, 0, 0x0F },
	{"dinohc", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinohp", CPS_B_21_QS2, mapper_CD63B },
	{"dinohx", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinojp", CPS_B_21_QS2, mapper_CD63B },
	{"dinorp", CPS_B_21_QS2, mapper_CD63B },
	{"dinos01", CPS_B_21_QS2, mapper_CD63B },
	{"dinos02", CPS_B_21_QS2, mapper_CD63B },
	{"dinos03", CPS_B_21_QS2, mapper_CD63B },
	{"dinos04", CPS_B_21_QS2, mapper_CD63B },
	{"dinos05", CPS_B_21_QS2, mapper_CD63B },
	{"dinos06", CPS_B_21_QS2, mapper_CD63B },
	{"dinos07", CPS_B_21_QS2, mapper_CD63B },
	{"dinos08", CPS_B_21_QS2, mapper_CD63B },
	{"dinos09", CPS_B_21_QS2, mapper_CD63B },
	{"dinos10", CPS_B_21_QS2, mapper_CD63B },
	{"dinos100", CPS_B_21_QS2, mapper_CD63B },
	{"dinos101", CPS_B_21_QS2, mapper_CD63B },
	{"dinos102", CPS_B_21_QS2, mapper_CD63B },
	{"dinos103", CPS_B_21_QS2, mapper_CD63B },
	{"dinos104", CPS_B_21_QS2, mapper_CD63B },
	{"dinos105", CPS_B_21_QS2, mapper_CD63B },
	{"dinos106", CPS_B_21_QS2, mapper_CD63B },
	{"dinos107", CPS_B_21_QS2, mapper_CD63B },
	{"dinos108", CPS_B_21_QS2, mapper_CD63B },
	{"dinos109", CPS_B_21_QS2, mapper_CD63B },
	{"dinos11", CPS_B_21_QS2, mapper_CD63B },
	{"dinos110", CPS_B_21_QS2, mapper_CD63B },
	{"dinos111", CPS_B_21_QS2, mapper_CD63B },
	{"dinos112", CPS_B_21_QS2, mapper_CD63B },
	{"dinos113", CPS_B_21_QS2, mapper_CD63B },
	{"dinos114", CPS_B_21_QS2, mapper_CD63B },
	{"dinos115", CPS_B_21_QS2, mapper_CD63B },
	{"dinos116", CPS_B_21_QS2, mapper_CD63B },
	{"dinos117", CPS_B_21_QS2, mapper_CD63B },
	{"dinos118", CPS_B_21_QS2, mapper_CD63B },
	{"dinos119", CPS_B_21_QS2, mapper_CD63B },
	{"dinos12", CPS_B_21_QS2, mapper_CD63B },
	{"dinos120", CPS_B_21_QS2, mapper_CD63B },
	{"dinos121", CPS_B_21_QS2, mapper_CD63B },
	{"dinos122", CPS_B_21_QS2, mapper_CD63B },
	{"dinos123", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinos124", CPS_B_21_QS2, mapper_CD63B },
	{"dinos125", CPS_B_21_QS2, mapper_CD63B },
	{"dinos126", CPS_B_21_QS2, mapper_CD63B },
	{"dinos127", CPS_B_21_QS2, mapper_CD63B },
	{"dinos128", CPS_B_21_QS2, mapper_CD63B },
	{"dinos129", CPS_B_21_QS2, mapper_CD63B },
	{"dinos13", CPS_B_21_QS2, mapper_CD63B },
	{"dinos130", CPS_B_21_QS2, mapper_CD63B },
	{"dinos131", CPS_B_21_QS2, mapper_CD63B },
	{"dinos132", CPS_B_21_QS2, mapper_CD63B },
	{"dinos133", CPS_B_21_QS2, mapper_CD63B },
	{"dinos134", CPS_B_21_QS2, mapper_CD63B },
	{"dinos135", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinos136", CPS_B_21_QS2, mapper_CD63B },
	{"dinos137", CPS_B_21_QS2, mapper_CD63B },
	{"dinos138", CPS_B_21_QS2, mapper_CD63B },
	{"dinos139", CPS_B_21_QS2, mapper_CD63B },
	{"dinos14", CPS_B_21_QS2, mapper_CD63B },
	{"dinos140", CPS_B_21_QS2, mapper_CD63B },
	{"dinos141", CPS_B_21_QS2, mapper_CD63B },
	{"dinos142", CPS_B_21_QS2, mapper_CD63B },
	{"dinos143", CPS_B_21_QS2, mapper_CD63B },
	{"dinos144", CPS_B_21_QS2, mapper_CD63B },
	{"dinos145", CPS_B_21_QS2, mapper_CD63B },
	{"dinos146", CPS_B_21_QS2, mapper_CD63B },
	{"dinos147", CPS_B_21_QS2, mapper_CD63B },
	{"dinos148", CPS_B_21_QS2, mapper_CD63B },
	{"dinos149", CPS_B_21_QS2, mapper_CD63B },
	{"dinos15", CPS_B_21_QS2, mapper_CD63B },
	{"dinos150", CPS_B_21_QS2, mapper_CD63B },
	{"dinos151", CPS_B_21_QS2, mapper_CD63B },
	{"dinos152", CPS_B_21_QS2, mapper_CD63B },
	{"dinos153", CPS_B_21_QS2, mapper_CD63B },
	{"dinos154", CPS_B_21_QS2, mapper_CD63B },
	{"dinos155", CPS_B_21_QS2, mapper_CD63B },
	{"dinos156", CPS_B_21_QS2, mapper_CD63B },
	{"dinos157", CPS_B_21_QS2, mapper_CD63B },
	{"dinos158", CPS_B_21_QS2, mapper_CD63B },
	{"dinos159", CPS_B_21_QS2, mapper_CD63B },
	{"dinos16", CPS_B_21_QS2, mapper_CD63B },
	{"dinos160", CPS_B_21_QS2, mapper_CD63B },
	{"dinos161", CPS_B_21_QS2, mapper_CD63B },
	{"dinos162", CPS_B_21_QS2, mapper_CD63B },
	{"dinos163", CPS_B_21_QS2, mapper_CD63B },
	{"dinos164", CPS_B_21_QS2, mapper_CD63B },
	{"dinos165", CPS_B_21_QS2, mapper_CD63B },
	{"dinos166", CPS_B_21_QS2, mapper_CD63B },
	{"dinos167", CPS_B_21_QS2, mapper_CD63B },
	{"dinos168", CPS_B_21_QS2, mapper_CD63B },
	{"dinos169", CPS_B_21_QS2, mapper_CD63B },
	{"dinos17", CPS_B_21_QS2, mapper_CD63B },
	{"dinos170", CPS_B_21_QS2, mapper_CD63B },
	{"dinos171", CPS_B_21_QS2, mapper_CD63B },
	{"dinos172", CPS_B_21_QS2, mapper_CD63B },
	{"dinos173", CPS_B_21_QS2, mapper_CD63B },
	{"dinos174", CPS_B_21_QS2, mapper_CD63B },
	{"dinos175", CPS_B_21_QS2, mapper_CD63B },
	{"dinos176", CPS_B_21_QS2, mapper_CD63B },
	{"dinos177", CPS_B_21_QS2, mapper_CD63B },
	{"dinos178", CPS_B_21_QS2, mapper_CD63B },
	{"dinos179", CPS_B_21_QS2, mapper_CD63B },
	{"dinos18", CPS_B_21_QS2, mapper_CD63B },
	{"dinos180", CPS_B_21_QS2, mapper_CD63B },
	{"dinos181", CPS_B_21_QS2, mapper_CD63B },
	{"dinos182", CPS_B_21_QS2, mapper_CD63B },
	{"dinos183", CPS_B_21_QS2, mapper_CD63B },
	{"dinos184", CPS_B_21_QS2, mapper_CD63B },
	{"dinos185", CPS_B_21_QS2, mapper_CD63B },
	{"dinos186", CPS_B_21_QS2, mapper_CD63B },
	{"dinos187", CPS_B_21_QS2, mapper_CD63B },
	{"dinos188", CPS_B_21_QS2, mapper_CD63B },
	{"dinos189", CPS_B_21_QS2, mapper_CD63B },
	{"dinos19", CPS_B_21_QS2, mapper_CD63B },
	{"dinos190", CPS_B_21_QS2, mapper_CD63B },
	{"dinos191", CPS_B_21_QS2, mapper_CD63B },
	{"dinos20", CPS_B_21_QS2, mapper_CD63B },
	{"dinos21", CPS_B_21_QS2, mapper_CD63B },
	{"dinos22", CPS_B_21_QS2, mapper_CD63B },
	{"dinos23", CPS_B_21_QS2, mapper_CD63B },
	{"dinos24", CPS_B_21_QS2, mapper_CD63B },
	{"dinos25", CPS_B_21_QS2, mapper_CD63B },
	{"dinos26", CPS_B_21_QS2, mapper_CD63B },
	{"dinos27", CPS_B_21_QS2, mapper_CD63B },
	{"dinos28", CPS_B_21_QS2, mapper_CD63B },
	{"dinos29", CPS_B_21_QS2, mapper_CD63B },
	{"dinos30", CPS_B_21_QS2, mapper_CD63B },
	{"dinos31", CPS_B_21_QS2, mapper_CD63B },
	{"dinos32", CPS_B_21_QS2, mapper_CD63B },
	{"dinos33", CPS_B_21_QS2, mapper_CD63B },
	{"dinos34", CPS_B_21_QS2, mapper_CD63B },
	{"dinos35", CPS_B_21_QS2, mapper_CD63B },
	{"dinos36", CPS_B_21_QS2, mapper_CD63B },
	{"dinos37", CPS_B_21_QS2, mapper_CD63B },
	{"dinos38", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinos40", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinos41", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinos42", CPS_B_21_QS2, mapper_CD63B },
	{"dinos43", CPS_B_21_QS2, mapper_CD63B },
	{"dinos44", CPS_B_21_QS2, mapper_CD63B },
	{"dinos45", CPS_B_21_QS2, mapper_CD63B },
	{"dinos46", CPS_B_21_QS2, mapper_CD63B },
	{"dinos47", CPS_B_21_QS2, mapper_CD63B },
	{"dinos48", CPS_B_21_QS2, mapper_CD63B },
	{"dinos49", CPS_B_21_QS2, mapper_CD63B },
	{"dinos50", CPS_B_21_QS2, mapper_CD63B },
	{"dinos51", CPS_B_21_QS2, mapper_CD63B },
	{"dinos52", CPS_B_21_QS2, mapper_CD63B },
	{"dinos53", CPS_B_21_QS2, mapper_CD63B },
	{"dinos54", CPS_B_21_QS2, mapper_CD63B },
	{"dinos56", CPS_B_21_QS2, mapper_CD63B },
	{"dinos57", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinos58", CPS_B_21_QS2, mapper_CD63B, 0, 0, 0, 0x0F },
	{"dinos59", CPS_B_21_QS2, mapper_CD63B },
	{"dinos60", CPS_B_21_QS2, mapper_CD63B },
	{"dinos61", CPS_B_21_QS2, mapper_CD63B },
	{"dinos62", CPS_B_21_QS2, mapper_CD63B },
	{"dinos63", CPS_B_21_QS2, mapper_CD63B },
	{"dinos64", CPS_B_21_DEF, mapper_CD63B, 0x36 },
	{"dinos65", CPS_B_21_QS2, mapper_CD63B },
	{"dinos66", CPS_B_21_QS2, mapper_CD63B },
	{"dinos67", CPS_B_21_QS2, mapper_CD63B },
	{"dinos68", CPS_B_21_QS2, mapper_CD63B },
	{"dinos69", CPS_B_21_QS2, mapper_CD63B },
	{"dinos70", CPS_B_21_QS2, mapper_CD63B },
	{"dinos71", CPS_B_21_QS2, mapper_CD63B },
	{"dinos72", CPS_B_21_QS2, mapper_CD63B },
	{"dinos73", CPS_B_21_QS2, mapper_CD63B },
	{"dinos74", CPS_B_21_QS2, mapper_CD63B },
	{"dinos75", CPS_B_21_QS2, mapper_CD63B },
	{"dinos91", CPS_B_21_QS2, mapper_CD63B },
	{"dinos92", CPS_B_21_QS2, mapper_CD63B },
	{"dinos93", CPS_B_21_QS2, mapper_CD63B },
	{"dinos94", CPS_B_21_QS2, mapper_CD63B },
	{"dinos95", CPS_B_21_QS2, mapper_CD63B },
	{"dinos96", CPS_B_21_QS2, mapper_CD63B },
	{"dinos97", CPS_B_21_QS2, mapper_CD63B },
	{"dinos98", CPS_B_21_QS2, mapper_CD63B },
	{"dinos99", CPS_B_21_QS2, mapper_CD63B },
	{"dinosf2", CPS_B_21_QS2, mapper_CD63B }, 
	{"dinoslice", CPS_B_21_QS2, mapper_CD63B },
	{"dinouphp", CPS_B_21_QS2, mapper_CD63B },
	{"dinoz", CPS_B_21_QS2, mapper_CD63B },
	{"ffightb", CPS_B_01,     mapper_S224B },
	{"ffightj1s01", CPS_B_01,     mapper_S224B },
	{"ffightj2s01", CPS_B_02, mapper_S224B },
	{"ffightj2s02", CPS_B_02, mapper_S224B },
	{"ffightjh01", CPS_B_02, mapper_S224B },
	{"ffights01", CPS_B_04, mapper_S224B },
	{"ffights02", CPS_B_04, mapper_S224B },
	{"knight21", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsa", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh", CPS_B_21_DEF, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh01", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh02", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh03", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh04", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh05", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh06", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh07", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh08", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh09", CPS_B_21_DEF, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh10", CPS_B_21_DEF, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh11", CPS_B_21_DEF, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh12", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh13", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsh14", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsha", HACK_H_7,     mapper_KR63B, 0x36, 0, 0x34 },
	{"knightshb2", HACK_H_6, mapper_KR63B, 0x36, 0, 0x34, 0x44 }, 
	{"knightsjb", CPS_B_21_DEF, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsjs01", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightsro", CPS_B_21_BT4, mapper_KR63B, 0x36, 0, 0x34 },
	{"knightud", CPS_B_21_DEF, mapper_KR63B, 0x36, 0, 0x34 },
	{"kodd", CPS_B_01, mapper_KD29B, 0x36, 0, 0x34 },
	{"kodh", CPS_B_21_DEF, mapper_KD29B, 0x36, 0, 0x34 },
	{"kodsp", CPS_B_21_BT2, mapper_KD29B, 0x36, 0, 0x34 },
	{"kodud", CPS_B_01, mapper_KD29B, 0x36, 0, 0x34 },
	{"koduhc01", CPS_B_21_BT2, mapper_KD29B, 0x36, 0, 0x34 },
	{"koduhc02", CPS_B_21_BT2, mapper_KD29B, 0x36, 0, 0x34 },
	{"koduhc03", CPS_B_21_BT2, mapper_KD29B, 0x36, 0, 0x34 },
	{"mbombrds01", CPS_B_21_QS5, mapper_MB63B },
	{"mbombrds02", CPS_B_21_QS5, mapper_MB63B },
	{"mbombrds03", CPS_B_21_QS5, mapper_MB63B },
	{"mbombrds04", CPS_B_21_QS5, mapper_MB63B },
	{"mercjs01", CPS_B_12, mapper_O224B, 0x36, 0, 0x34 },
	{"mercs01", CPS_B_12, mapper_O224B, 0x36, 0, 0x34 },
	{"pnicku", CPS_B_21_DEF, mapper_PKB10B },
	{"punisherb", CPS_B_21_QS3, mapper_PS63B, 0, 0, 0, 0x0E },
	{"punisherbzs01", CPS_B_21_QS3, mapper_PS63B },
	{"punisherf", CPS_B_21_QS3, mapper_PS63B },
	{"punisherje1", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjh", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjh1", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjha", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs01", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs02", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs03", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs04", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs05", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs06", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs07", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs08", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs09", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs10", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs11", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs12", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs13", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs14", CPS_B_21_QS3, mapper_PS63B },
	{"punishers01", CPS_B_21_QS3, mapper_PS63B },
	{"punishers02", CPS_B_21_QS3, mapper_PS63B },
	{"punishers03", CPS_B_21_QS3, mapper_PS63B },
	{"punishers04", CPS_B_21_QS3, mapper_PS63B },
	{"punishers05", CPS_B_21_QS3, mapper_PS63B },
	{"punishers06", CPS_B_21_QS3, mapper_PS63B },
	{"punisherud1", CPS_B_21_DEF, mapper_PS63B },
	{"punisherud2", CPS_B_21_DEF, mapper_PS63B },
	{"sf2bhj", CPS_B_12,     mapper_STF29,  0x36 },
	{"sf2c", CPS_B_13,     mapper_STF29,  0x36 },
	{"sf2ced", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ceda", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2cehp", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2cejem", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces01", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces02", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces03", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces04", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces05", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces06", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces07", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces08", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces09", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces10", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces11", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2ces12", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2h10", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2h11", HACK_B_1,     mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2h11s01", HACK_B_1,     mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2h12", HACK_B_1,     mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2h13", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2h9", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2hfus01", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2hfus02", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2hfus03", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2hfus04", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2jbh", CPS_B_13,     mapper_STF29,  0x36 },
	{"sf2js01", CPS_B_11, mapper_STF29, 0x36 },
	{"sf2js02", CPS_B_11, mapper_STF29, 0x36 },
	{"sf2koryuh", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2koryus01", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2koryus02", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2koryus03", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2m7s01", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2pun", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2puns01", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2reds01", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2reds02", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2reds03", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2reds04", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2s01", CPS_B_11, mapper_STF29, 0x36 },
	{"sf2s02", CPS_B_13,     mapper_STF29,  0x36 },
	{"sf2s03", CPS_B_11, mapper_STF29, 0x36 },
	{"sf2s04", CPS_B_11, mapper_STF29, 0x36 },
	{"sf2s05", CPS_B_11, mapper_STF29, 0x36 },
	{"sf2sl73a", CPS_B_21_DEF, mapper_S9263B, 0x36 }, // Need testing!
	{"sf2th", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2tha", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2tlona", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2tlonas01", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2tlonas02", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2tlonas03", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2tlonas04", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2tlonb", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2tlonc", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2turyu", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2yyc3d5", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2yyc3g", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sf2yyc6", CPS_B_21_DEF, mapper_S9263B, 0x36, 0, 0, 0x41 },
	{"sfzchs01", CPS_B_21_DEF, mapper_sfzch },
	{"sfzchs02", CPS_B_21_DEF, mapper_sfzch },
	{"sfzchs03", CPS_B_21_DEF, mapper_sfzch },
	{"sfzchs04", CPS_B_21_DEF, mapper_sfzch },
	{"sfzchs05", CPS_B_21_DEF, mapper_sfzch },
	{"sfzchs06", CPS_B_21_DEF, mapper_sfzch },
	{"sk2h101", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h101q", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h102", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h102q", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h103", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h104q", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h105q", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h106q", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h107", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h108", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h114", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h115", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h116", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h117", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h118", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk2h12", CPS_B_21_DEF, mapper_TK263B },
	{"sk2h13", CPS_B_21_DEF, mapper_TK263B },
	{"sk2h14", CPS_B_21_DEF, mapper_TK263B },
	{"sk2h16", CPS_B_21_DEF, mapper_TK263B },
	{"sk2h17", CPS_B_21_DEF, mapper_TK263B },
	{"sk2h18", CPS_B_21_DEF, mapper_TK263B },
	{"sk2h21", CPS_B_21_QS1, mapper_TK263B }, //sk2h21.key, need testing!
	{"sk2h22", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h23", CPS_B_21_DEF, mapper_TK263B },
	{"sk2h31", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h31q", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h32", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h32q", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h33", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h33q", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h34", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h34q", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h35", CPS_B_21_QS1, mapper_TK263B }, //sk2h21.key, need testing!
	{"sk2h41", CPS_B_21_QS1, mapper_TK263B }, //sk2h21.key, need testing!
	{"sk2h42", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h43", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h45", CPS_B_21_QS1, mapper_TK263B }, //sk2h21.key, need testing!
	{"sk2h46", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, sk2h32.key, need testing!
	{"sk2h51", CPS_B_21_DEF, mapper_TK263B },
	{"sk2h52", CPS_B_21_DEF, mapper_TK263B },
	{"sk2h53", CPS_B_21_DEF, mapper_TK263B },
	{"sk2h54", CPS_B_21_DEF, mapper_TK263B },
	{"sk3h1", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk3h2", HACK_WOF_H, mapper_TK263B, 0x00, 0x00, 0x00, 0x64 }, // old value, need testing!
	{"sk3p1", CPS_B_21_DEF, mapper_TK263B },
	{"sk3p10", CPS_B_21_DEF, mapper_TK263B },
	{"sk3p2", CPS_B_21_DEF, mapper_TK263B },
	{"sk3p3", CPS_B_21_DEF, mapper_TK263B },
	{"sk3p4", CPS_B_21_DEF, mapper_TK263B },
	{"sk3p5", CPS_B_21_DEF, mapper_TK263B },
	{"sk3p6", CPS_B_21_DEF, mapper_TK263B },
	{"sk3p7", CPS_B_21_DEF, mapper_TK263B },
	{"sk3p8", CPS_B_21_DEF, mapper_TK263B },
	{"sk3p9", CPS_B_21_DEF, mapper_TK263B },
	{"slammasts01", CPS_B_21_QS4, mapper_MB63B },
	{"slammasts02", CPS_B_21_QS4, mapper_MB63B },
	{"slammasts03", CPS_B_21_QS4, mapper_MB63B },
	{"slammasts04", CPS_B_21_QS4, mapper_MB63B },
	{"slammasts05", CPS_B_21_QS4, mapper_MB63B },
	{"slammastud", CPS_B_21_DEF, mapper_MB63B },
	{"stridergf", CPS_B_01,     mapper_ST24M1 },
	{"stridergh", CPS_B_01,     mapper_ST24M1 },
	{"striders01", CPS_B_01,     mapper_ST24M1 },
	{"tk2c1", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c10", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c11", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c12", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c13", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c14", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c15", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c16", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c17", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c18", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c19", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c2", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c20", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c21", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c22", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c23", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c3", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c4", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c5", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c6", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c7", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c8", CPS_B_21_QS1, mapper_TK263B },
	{"tk2c9", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h1", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h10", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h100", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h101", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h102", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h103", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h104", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h105", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h106", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h107", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h108", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h109", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h11", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h110", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h111", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h112", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h113", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h114", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h115", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h116", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h118", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h119", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h12", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h120", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h121", CPS_B_21_QS1, mapper_TK263B }, //sk2h21.key, need testing!
	{"tk2h122", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h123", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h124", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h125", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h126", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h127", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h128", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h129", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h13", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h130", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h131", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h132", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h133", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h134", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h135", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h136", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h137", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h138", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h139", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h14", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h15", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h16", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h17", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h18", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h19", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h2", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h20", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h21", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h22", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h23", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h24", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h25", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h26", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h27", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h28", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h29", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h3", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h30", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h31", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h32", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h33", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h35", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h37", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h38", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h39", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h4", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h40", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h41", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h42", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h43", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h44", CPS_B_21_QS1, mapper_TK263B }, //sk2h21.key, need testing!
	{"tk2h45", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h46", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h47", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h48", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h49", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h5", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h50", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h51", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h52", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h53", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h54", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h55", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h56", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h57", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h58", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h59", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h6", CPS_B_21_DEF, mapper_TK263B },
	{"tk2h60", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h61", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h62", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h63", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h64", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h65", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h66", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h67", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h68", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h69", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h7", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h70", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h71", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h72", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h73", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h74", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h75", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h76", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h77", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h78", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h79", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h8", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h80", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h81", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h82", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h83", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h84", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h85", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h86", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h87", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h88", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h89", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h9", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h90", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h91", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h92", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h93", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h94", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h95", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h96", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h97", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h98", CPS_B_21_QS1, mapper_TK263B },
	{"tk2h99", CPS_B_21_QS1, mapper_TK263B },
	{"tk2p02", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p03", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p04", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p05", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p07", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p08", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p09", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p10", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p11", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p12", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p13", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p14", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p15", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p18", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p19", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p20", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p21", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p22", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p23", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p24", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p25", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p26", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p27", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p28", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p29", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p30", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p31", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p33", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p34", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p36", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p37", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p38", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p39", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p41", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p42", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p43", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p44", CPS_B_21_DEF, mapper_TK263B },
	{"tk2p45", CPS_B_21_DEF, mapper_TK263B },
	{"varths01", CPS_B_04, mapper_VA63B },
	{"varths02", CPS_B_04, mapper_VA63B },
	{"willows01", CPS_B_03, mapper_WL24B },
	{"wofb", CPS_B_21_DEF, mapper_TK263B },
	{"woffr", CPS_B_21_DEF, mapper_TK263B },
	{"wofs00", CPS_B_21_QS1, mapper_TK263B },
	{"wofs01", CPS_B_21_DEF, mapper_TK263B },
	{"wofs02", CPS_B_21_QS1, mapper_TK263B }, //sk2h21.key, need testing!
	{"wofs03", CPS_B_21_QS1, mapper_TK263B }, //sk2h21.key, need testing!
	{"wofs04", CPS_B_21_QS1, mapper_TK263B }, //sk2h21.key, need testing!
	{"wofs05", CPS_B_21_DEF, mapper_TK263B },
	{"wofs06", CPS_B_21_DEF, mapper_TK263B },
	{"wofs07", CPS_B_21_DEF, mapper_TK263B },
	{"wofs08", CPS_B_21_DEF, mapper_TK263B },
	{"wofsf2", CPS_B_21_QS1, mapper_TK263B, 0x36 },
	{"wofud", CPS_B_21_DEF, mapper_TK263B },
//HBMAME 0.211
	{"captcomms60", CPS_B_21_BT3, mapper_CC63B, 0x36, 0x38, 0x34 },
	{"dinos192", CPS_B_21_QS2, mapper_CD63B },
	{"dinos193", CPS_B_21_QS2, mapper_CD63B },
	{"punishers07", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs15", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs16", CPS_B_21_QS3, mapper_PS63B },
	{"punisherjs17", CPS_B_21_QS3, mapper_PS63B },
	
	{ NULL, 0 }		/* End of table */
};


/* Offset of each palette entry */
#define cps1_palette_entries (32 * 6)  /* Number colour schemes in palette */

/* CPS-A registers */
#define CPS1_OBJ_BASE           (0x00 / 2)    /* Base address of objects */
#define CPS1_SCROLL1_BASE       (0x02 / 2)    /* Base address of scroll 1 */
#define CPS1_SCROLL2_BASE       (0x04 / 2)    /* Base address of scroll 2 */
#define CPS1_SCROLL3_BASE       (0x06 / 2)    /* Base address of scroll 3 */
#define CPS1_OTHER_BASE         (0x08 / 2)    /* Base address of other video */
#define CPS1_PALETTE_BASE       (0x0a / 2)    /* Base address of palette */
#define CPS1_SCROLL1_SCROLLX    (0x0c / 2)    /* Scroll 1 X */
#define CPS1_SCROLL1_SCROLLY    (0x0e / 2)    /* Scroll 1 Y */
#define CPS1_SCROLL2_SCROLLX    (0x10 / 2)    /* Scroll 2 X */
#define CPS1_SCROLL2_SCROLLY    (0x12 / 2)    /* Scroll 2 Y */
#define CPS1_SCROLL3_SCROLLX    (0x14 / 2)    /* Scroll 3 X */
#define CPS1_SCROLL3_SCROLLY    (0x16 / 2)    /* Scroll 3 Y */
#define CPS1_STARS1_SCROLLX     (0x18 / 2)    /* Stars 1 X */
#define CPS1_STARS1_SCROLLY     (0x1a / 2)    /* Stars 1 Y */
#define CPS1_STARS2_SCROLLX     (0x1c / 2)    /* Stars 2 X */
#define CPS1_STARS2_SCROLLY     (0x1e / 2)    /* Stars 2 Y */
#define CPS1_ROWSCROLL_OFFS     (0x20 / 2)    /* base of row scroll offsets in other RAM */
#define CPS1_VIDEOCONTROL       (0x22 / 2)    /* flip screen, rowscroll enable */

/* CPS1 VIDEO RENDERER */
#define CPS2_OBJ_BASE	0x00	/* Unknown (not base address of objects). Could be bass address of bank used when object swap bit set? */
#define CPS2_OBJ_UK1	0x02	/* Unknown (nearly always 0x807d, or 0x808e when screen flipped) */
#define CPS2_OBJ_PRI	0x04	/* Layers priorities */
#define CPS2_OBJ_UK2	0x06	/* Unknown (usually 0x0000, 0x1101 in ssf2, 0x0001 in 19XX) */
#define CPS2_OBJ_XOFFS	0x08	/* X offset (usually 0x0040) */
#define CPS2_OBJ_YOFFS	0x0a	/* Y offset (always 0x0010) */

static void cps1_build_palette(running_machine *machine, const UINT16* const palette_base);

static MACHINE_RESET( cps )
{
	cps_state *state = machine->driver_data<cps_state>();
	const char *gamename = machine->gamedrv->name;
	const struct CPS1config *pCFG = &cps1_config_table[0];

	while (pCFG->name)
	{
		if (strcmp(pCFG->name, gamename) == 0) break;
		pCFG++;
	}

	state->game_config = pCFG;

	if (!state->game_config->name)
	{
		gamename = "cps2";
		pCFG = &cps1_config_table[0];

		while (pCFG->name)
		{
			if (strcmp(pCFG->name, gamename) == 0) break;
			pCFG++;
		}

		state->game_config = pCFG;
	}

	/* specific game_init */
	state->force_screen_flip_flag = 0;	// For: Cadillacs and Dinosaurs bootleg set 4 with PIC16c57
	state->bootleg_sf2rb2 = 0;		// For: Street Fighter II': Champion Edition Rainbow set 1 / 2
	state->spec_gameflag = 0;		// For: Tag specific games

	if (strcmp(gamename, "dinopic4") == 0)
		state->force_screen_flip_flag = 1;
	else if (strcmp(gamename, "sf2rb") == 0)
	{
		/* Patch out protection check */
		UINT16 *rom = (UINT16 *)memory_region(machine, "maincpu");
		rom[0xe5464 / 2] = 0x6012;
	}
	else if (strcmp(gamename, "sf2rb2") == 0)
	{
		/* Patch out protection check */
		UINT16 *rom = (UINT16 *)memory_region(machine, "maincpu");
		rom[0xe5332 / 2] = 0x6014;

		state->bootleg_sf2rb2 = 1;
	}

	if (strcmp(machine->gamedrv->name, "pzloop2") == 0 || strcmp(machine->gamedrv->parent, "pzloop2") == 0)
		state->spec_gameflag |= 0x01;	// if it's 'pzloop2' or 'pzloop2j', set the BIT 0 of spec_gameflag to 1.
	else if (strcmp(machine->gamedrv->name, "mmatrix") == 0 || strcmp(machine->gamedrv->parent, "mmatrix") == 0)
		state->spec_gameflag |= 0x02;	// if it's 'mmatrix', set the BIT 1 of spec_gameflag to 1.
}


INLINE UINT16 *cps1_base( running_machine *machine, int offset, int boundary )
{
	cps_state *state = machine->driver_data<cps_state>();
	int base = state->cps_a_regs[offset] * 256;

/*	The scroll RAM must start on a 0x4000 boundary.
    	Some games do not do this.
    	For example:
		Captain commando    - continue screen will not display
		Muscle bomber games - will animate garbage during gameplay
		Mask out the irrelevant bits. */

	base &= ~(boundary - 1);

	return &state->gfxram[(base & 0x03ffff) / 2];
}


WRITE16_HANDLER( cps1_cps_a_w )
{
	cps_state *state = space->machine->driver_data<cps_state>();
	data = COMBINE_DATA(&state->cps_a_regs[offset]);

/*	The main CPU writes the palette to gfxram, and the CPS-B custom copies it
    	to the real palette RAM, which is separated from gfxram.
    	This is done ONLY after the palette base register is written to. It is not
    	known what the exact timing should be, how long it should take and when it
    	should happen. We are assuming that the copy happens immediately, since it
    	fixes glitches in the ghouls intro, but it might happen at next vblank.	    */
	if (offset == CPS1_PALETTE_BASE)
		cps1_build_palette(space->machine, cps1_base(space->machine, CPS1_PALETTE_BASE, state->palette_align));

	/* pzloop2 write to register 24 on startup. This is probably just a bug. */
	if (state->cps_version == 2)
		if (offset == 0x24 / 2)
			return;
}


READ16_HANDLER( cps1_cps_b_r )
{
	cps_state *state = space->machine->driver_data<cps_state>();

	/* Some games interrogate a couple of registers on bootup. */
	/* These are CPS1 board B self test checks. They wander from game to game. */
	if (offset == state->game_config->cpsb_addr / 2)
		return state->game_config->cpsb_value;

	/* Extra input ports (on C-board) */
	if (offset == state->game_config->in2_addr / 2)
		return input_port_read(space->machine, "IN2");

	/* Player 4 controls (on C-board) ("Captain Commando") */
	if (offset == state->game_config->in3_addr / 2)
		return input_port_read(space->machine, "IN3");

	/* some games use as a protection check the ability to do 16-bit multiplications */
	/* with a 32-bit result, by writing the factors to two ports and reading the result from two other ports. */
	if (offset == state->game_config->mult_result_lo / 2)
		return (state->cps_b_regs[state->game_config->mult_factor1 / 2] *
			state->cps_b_regs[state->game_config->mult_factor2 / 2]) & 0xffff;

	if (offset == state->game_config->mult_result_hi / 2)
		return (state->cps_b_regs[state->game_config->mult_factor1 / 2] *
			state->cps_b_regs[state->game_config->mult_factor2 / 2]) >> 16;

	if (state->cps_version == 2)
	{
		/* UNKNOWN--only mmatrix appears to read this, and I'm not sure if the result is actually used */
		if (offset == 0x10 / 2)
			return state->cps_b_regs[0x10 / 2];
		else if (offset == 0x12 / 2)
			return state->cps_b_regs[0x12 / 2];
	}

	return 0xffff;
}


WRITE16_HANDLER( cps1_cps_b_w )
{
	cps_state *state = space->machine->driver_data<cps_state>();
	data = COMBINE_DATA(&state->cps_b_regs[offset]);

	if (state->cps_version == 2)
	{
		switch (offset)		/* To mark scanlines for raster effects */
		{
			case 0x0e / 2: return;	/* UNKNOWN */
			case 0x10 / 2: state->scanline1 = (data & 0x01ff); return;
			case 0x12 / 2: state->scanline2 = (data & 0x01ff); return;
		}
	}

	/* additional outputs on C-board */
	if (offset == state->game_config->out2_addr / 2)
	{
		if (ACCESSING_BITS_0_7)
		{
			if (state->game_config->cpsb_value == 0x0402)	/* Mercs (CN2 connector) */
			{
				coin_lockout_w(space->machine, 2, ~data & 0x01);
				set_led_status(space->machine, 0, data & 0x02);
				set_led_status(space->machine, 1, data & 0x04);
				set_led_status(space->machine, 2, data & 0x08);
			}
			else						/* kod, captcomm, knights */
			{
				coin_lockout_w(space->machine, 2, ~data & 0x02);
				coin_lockout_w(space->machine, 3, ~data & 0x08);
			}
		}
	}
}


INLINE int cps2_port( running_machine *machine, int offset )
{
	cps_state *state = machine->driver_data<cps_state>();
	return state->output[offset / 2];
}


static void cps1_gfx_decode( running_machine *machine )
{
	UINT8 *cps1_gfx = memory_region(machine, "gfx");
	INT32 gfxsize = memory_region_length(machine, "gfx") / 4;

	for (UINT32 i = 0; i < gfxsize; i++)
	{
		UINT32 src = cps1_gfx[4 * i] + (cps1_gfx[4 * i + 1] << 8) + (cps1_gfx[4 * i + 2] << 16) + (cps1_gfx[4 * i + 3] << 24);
		UINT32 dwval = 0;

		for (UINT32 j = 0; j < 8; j++)
		{
			INT32 n = 0;
			UINT32 mask = (0x80808080 >> j) & src;

			if (mask & 0x000000ff) n |= 1;
			if (mask & 0x0000ff00) n |= 2;
			if (mask & 0x00ff0000) n |= 4;
			if (mask & 0xff000000) n |= 8;

			dwval |= n << (j * 4);
		}
		cps1_gfx[4 * i + 0] = dwval >>  0;
		cps1_gfx[4 * i + 1] = dwval >>  8;
		cps1_gfx[4 * i + 2] = dwval >> 16;
		cps1_gfx[4 * i + 3] = dwval >> 24;
	}
}


static void unshuffle( UINT64 *buf, int len )
{
	UINT64 t;

	if (len == 2)
		return;

	assert(len % 4 == 0);   /* must not happen */

	len /= 2;

	unshuffle(buf, len);
	unshuffle(buf + len, len);

	int length = len / 2;

	for (UINT32 i = 0; i < length; i++)
	{
		t = buf[length + i];
		buf[length + i] = buf[len + i];
		buf[len + i] = t;
	}
}


static void cps2_gfx_decode( running_machine *machine )
{
	INT32 size = memory_region_length(machine, "gfx");

	for (UINT32 i = 0; i < size; i += 0x200000)
		unshuffle((UINT64 *)(memory_region(machine, "gfx") + i), 0x200000 / 8);

	cps1_gfx_decode(machine);
}


DRIVER_INIT( cps1 )
{
	cps_state *state = machine->driver_data<cps_state>();

	cps1_gfx_decode(machine);

	state->scanline1 = 0;
	state->scanline2 = 0;
	state->scancalls = 0;
	state->last_sprite_offset = 0;
	state->pri_ctrl = 0;
	state->objram_bank = 0;
}


DRIVER_INIT( cps2_video )
{
	cps_state *state = machine->driver_data<cps_state>();

	cps2_gfx_decode(machine);

	state->scanline1 = 262;
	state->scanline2 = 262;
	state->scancalls = 0;
	state->last_sprite_offset = 0;
	state->cps2_last_sprite_offset = 0;
	state->pri_ctrl = 0;
	state->objram_bank = 0;
}


void cps1_get_video_base( running_machine *machine )
{
	cps_state *state = machine->driver_data<cps_state>();
	INT32 layercontrol, videocontrol, scroll1xoff, scroll2xoff, scroll3xoff;

	/* Re-calculate the VIDEO RAM base */
	if (state->scroll1 != cps1_base(machine, CPS1_SCROLL1_BASE, state->scroll_size))
	{
		state->scroll1 = cps1_base(machine, CPS1_SCROLL1_BASE, state->scroll_size);
		tilemap_mark_all_tiles_dirty(state->bg_tilemap[0]);
	}
	if (state->scroll2 != cps1_base(machine, CPS1_SCROLL2_BASE, state->scroll_size))
	{
		state->scroll2 = cps1_base(machine, CPS1_SCROLL2_BASE, state->scroll_size);
		tilemap_mark_all_tiles_dirty(state->bg_tilemap[1]);
	}
	if (state->scroll3 != cps1_base(machine, CPS1_SCROLL3_BASE, state->scroll_size))
	{
		state->scroll3 = cps1_base(machine, CPS1_SCROLL3_BASE, state->scroll_size);
		tilemap_mark_all_tiles_dirty(state->bg_tilemap[2]);
	}

	/* Some of the sf2 hacks use only sprite port 0x9100 and the scroll layers are offset */
	switch ( state->game_config->bootleg_kludge )
	{
		default:
		case 0x00:
			scroll1xoff = 0x00;
			scroll2xoff = 0x00;
			scroll3xoff = 0x00;
		break;
		case 0x01:
			state->cps_a_regs[CPS1_OBJ_BASE] = 0x9100;
			scroll1xoff = -0x0c;
			scroll2xoff = -0x0e;
			scroll3xoff = -0x10;
		break;
		case 0x02:
			state->cps_a_regs[CPS1_OBJ_BASE] = 0x9100;
			scroll1xoff = -0x0c;
			scroll2xoff = -0x10;
			scroll3xoff = -0x10;
		break;
		case 0x03:
			scroll1xoff = -0x08;
			scroll2xoff = -0x0b;
			scroll3xoff = -0x0c;
		break;
		case 0x0D:
			scroll1xoff = -0x40;
			scroll2xoff = -0x40;
			scroll3xoff = -0x40;
		break;
		case 0x0F:
			scroll1xoff = 0xffc0;
			scroll2xoff = 0xffc0;
			scroll3xoff = 0xffc0;
		break;
		case 0x64:			// This kludge flag is only used for SGYXZ and it's similar roms
			scroll1xoff = 0xffc0;
			scroll2xoff = 0xffc0;
			scroll3xoff = 0xffc0;	// layer_mask_reg is an array for bootleg video config, it will only be called by bootleg videoupdate.
			state->cps_b_regs[state->layer_mask_reg[1] / 2] = state->mainram[0x639a / 2];
			state->cps_b_regs[state->layer_mask_reg[2] / 2] = state->mainram[0x639c / 2];
			state->cps_b_regs[state->layer_mask_reg[3] / 2] = state->mainram[0x639e / 2];
		break;
		case 0x88:
			scroll1xoff = 0x04;
			scroll2xoff = 0x06;
			scroll3xoff = 0x0a;
			state->cps_b_regs[0x30 / 2] = 0x3f;
			state->cps_a_regs[CPS1_VIDEOCONTROL] = 0x3e;
			state->cps_a_regs[CPS1_SCROLL2_BASE] = 0x90c0;
			state->cps_a_regs[CPS1_SCROLL3_BASE] = 0x9100;
			state->cps_a_regs[CPS1_PALETTE_BASE] = 0x9140;
		break;
	}
	state->obj = cps1_base(machine, CPS1_OBJ_BASE, state->obj_size);
	state->other = cps1_base(machine, CPS1_OTHER_BASE, state->other_size);

	/* Get scroll values */
	state->scroll1x = state->cps_a_regs[CPS1_SCROLL1_SCROLLX] + scroll1xoff;
	state->scroll1y = state->cps_a_regs[CPS1_SCROLL1_SCROLLY];
	state->scroll2x = state->cps_a_regs[CPS1_SCROLL2_SCROLLX] + scroll2xoff;
	state->scroll2y = state->cps_a_regs[CPS1_SCROLL2_SCROLLY];
	state->scroll3x = state->cps_a_regs[CPS1_SCROLL3_SCROLLX] + scroll3xoff;
	state->scroll3y = state->cps_a_regs[CPS1_SCROLL3_SCROLLY];
	state->stars1x  = state->cps_a_regs[CPS1_STARS1_SCROLLX];
	state->stars1y  = state->cps_a_regs[CPS1_STARS1_SCROLLY];
	state->stars2x  = state->cps_a_regs[CPS1_STARS2_SCROLLX];
	state->stars2y  = state->cps_a_regs[CPS1_STARS2_SCROLLY];

	/* Get layer enable bits */
	layercontrol = state->cps_b_regs[state->game_config->layer_control / 2];
	videocontrol = state->cps_a_regs[CPS1_VIDEOCONTROL];

	tilemap_set_enable(state->bg_tilemap[0], layercontrol & state->game_config->layer_enable_mask[0]);
	tilemap_set_enable(state->bg_tilemap[1], (layercontrol & state->game_config->layer_enable_mask[1]) && (videocontrol & 0x04));
	tilemap_set_enable(state->bg_tilemap[2], (layercontrol & state->game_config->layer_enable_mask[2]) && (videocontrol & 0x08));

	state->stars_enabled[0] = layercontrol & state->game_config->layer_enable_mask[3];
	state->stars_enabled[1] = layercontrol & state->game_config->layer_enable_mask[4];
}


WRITE16_HANDLER( cps1_gfxram_w )
{
	cps_state *state = space->machine->driver_data<cps_state>();

	int page = (offset >> 7) & 0x03c0;
	COMBINE_DATA(&state->gfxram[offset]);
	UINT32 index = offset / 2 & 0x0fff;

	if (page == (state->cps_a_regs[CPS1_SCROLL1_BASE] & 0x3c0))
		tilemap_mark_tile_dirty(state->bg_tilemap[0], index);

	if (page == (state->cps_a_regs[CPS1_SCROLL2_BASE] & 0x3c0))
		tilemap_mark_tile_dirty(state->bg_tilemap[1], index);

	if (page == (state->cps_a_regs[CPS1_SCROLL3_BASE] & 0x3c0))
		tilemap_mark_tile_dirty(state->bg_tilemap[2], index);
}


static int gfxrom_bank_mapper( running_machine *machine, int type, int code )
{
	cps_state *state = machine->driver_data<cps_state>();

	const struct gfx_range *range = state->game_config->bank_mapper;
	int shift = 0;

	assert(range);

	switch (type)
	{
		case GFXTYPE_SPRITES: shift = 1; break;
		case GFXTYPE_SCROLL1: shift = 0; break;
		case GFXTYPE_SCROLL2: shift = 1; break;
		case GFXTYPE_SCROLL3: shift = 3; break;
	}

	code <<= shift;

	while (range->type)
	{
		if (code >= range->start && code <= range->end)
			if (range->type & type)
			{
				INT32 base = 0;
				for (INT32 i = 0; i < range->bank; ++i)
					base += state->game_config->bank_sizes[i];

				return (base + (code & (state->game_config->bank_sizes[range->bank] - 1))) >> shift;
			}
		++range;
	}
	return -1;
}


/***************************************************************************

  Start the video hardware emulation.

***************************************************************************/

static TILEMAP_MAPPER( tilemap0_scan )
{
	/* logical (col,row) -> memory offset */
	return (row & 0x1f) + ((col & 0x3f) << 5) + ((row & 0x20) << 6);
}

static TILEMAP_MAPPER( tilemap1_scan )
{
	/* logical (col,row) -> memory offset */
	return (row & 0x0f) + ((col & 0x3f) << 4) + ((row & 0x30) << 6);
}

static TILEMAP_MAPPER( tilemap2_scan )
{
	/* logical (col,row) -> memory offset */
	return (row & 0x07) + ((col & 0x3f) << 3) + ((row & 0x38) << 6);
}

static TILE_GET_INFO( get_tile0_info )
{
	cps_state *state = machine->driver_data<cps_state>();
	int code = state->scroll1[2 * tile_index];
	int attr = state->scroll1[2 * tile_index + 1];
	int gfxset;

	code = gfxrom_bank_mapper(machine, GFXTYPE_SCROLL1, code);

/*	allows us to reproduce a problem seen with a ffight board where USA and Japanese
        roms have been mixed to be reproduced (ffightua) -- it looks like each column
        should alternate between the left and right side of the 16x16 tiles */
	gfxset = (tile_index & 0x20) >> 5;

	SET_TILE_INFO( 	gfxset, code, (attr & 0x1f) + 0x20,
			TILE_FLIPYX((attr & 0x60) >> 5));
			tileinfo->group = (attr & 0x0180) >> 7;

/*	for out of range tiles, switch to fully transparent data
	(but still call SET_TILE_INFO, otherwise problems might occur on boot e.g. unsquad) */
	if (code == -1)
		tileinfo->pen_data = state->empty_tile8x8;
}

static TILE_GET_INFO( get_tile1_info )
{
	cps_state *state = machine->driver_data<cps_state>();
	int code = state->scroll2[2 * tile_index];
	int attr = state->scroll2[2 * tile_index + 1];

	code = gfxrom_bank_mapper(machine, GFXTYPE_SCROLL2, code);

	SET_TILE_INFO(	2, code, (attr & 0x1f) + 0x40,
			TILE_FLIPYX((attr & 0x60) >> 5));
			tileinfo->group = (attr & 0x0180) >> 7;

/*	for out of range tiles, switch to fully transparent data */
	if (code == -1)
		tileinfo->pen_data = state->empty_tile;
}

static TILE_GET_INFO( get_tile2_info )
{
	cps_state *state = machine->driver_data<cps_state>();
	int code = state->scroll3[2 * tile_index] & 0x3fff;
	int attr = state->scroll3[2 * tile_index + 1];

	code = gfxrom_bank_mapper(machine, GFXTYPE_SCROLL3, code);

	SET_TILE_INFO( 	3, code, (attr & 0x1f) + 0x60,
			TILE_FLIPYX((attr & 0x60) >> 5));
			tileinfo->group = (attr & 0x0180) >> 7;

/*	for out of range tiles, switch to fully transparent data
	(but still call SET_TILE_INFO, otherwise problems might occur on boot e.g. unsquad) */
	if (code == -1)
		tileinfo->pen_data = state->empty_tile;
}


static void cps1_update_transmasks( running_machine *machine )
{
	cps_state *state = machine->driver_data<cps_state>();

	for (UINT32 i = 0; i < 4; i++)
	{
		/* Get transparency registers */
		INT32 mask = ( state->game_config->priority[i] != -1 ) ? state->cps_b_regs[state->game_config->priority[i] / 2] ^ 0xffff : 0xffff;   /* completely transparent if priority masks not defined (qad) */

		tilemap_set_transmask(state->bg_tilemap[0], i, mask, 0x8000);
		tilemap_set_transmask(state->bg_tilemap[1], i, mask, 0x8000);
		tilemap_set_transmask(state->bg_tilemap[2], i, mask, 0x8000);
	}
}

static STATE_POSTLOAD( cps_postload )
{
	cps1_get_video_base(machine);
}

static VIDEO_START( cps )
{
	cps_state *state = machine->driver_data<cps_state>();

	MACHINE_RESET_CALL(cps);

	/* Put in some const */
	state->scroll_size    = 0x4000;					/* scroll1, scroll2, scroll3 */
	state->obj_size       = 0x0800;
	state->cps2_obj_size  = 0x2000;
	state->other_size     = 0x0800;
	state->palette_align  = 0x0400;					/* minimum alignment is a single palette page (512 colors). Verified on pcb. */
	state->palette_size   = cps1_palette_entries * 32;		/* Size of palette RAM */
	state->stars_rom_size = 0x2000;					/* first 0x4000 of gfx ROM are used, but 0x0000-0x1fff is == 0x2000-0x3fff */

	/* create tilemaps */
	state->bg_tilemap[0] = tilemap_create(machine, get_tile0_info, tilemap0_scan,  8,  8, 64, 64);
	state->bg_tilemap[1] = tilemap_create(machine, get_tile1_info, tilemap1_scan, 16, 16, 64, 64);
	state->bg_tilemap[2] = tilemap_create(machine, get_tile2_info, tilemap2_scan, 32, 32, 64, 64);

	/* create empty tiles */
	memset( state->empty_tile8x8, 0x0f, sizeof(state->empty_tile8x8) );
	memset( state->empty_tile, 0xff, sizeof(state->empty_tile) );	/* 16x16 and 32x32 use packed graphics, 8x8 does not */

	/* front masks will change at runtime to handle sprite occluding */
	cps1_update_transmasks(machine);

	for (UINT32 i = 0; i < cps1_palette_entries * 16; i++)
		palette_set_color( machine, i, MAKE_RGB(0, 0, 0) );

	state->buffered_obj = auto_alloc_array_clear(machine, UINT16, state->obj_size / 2);

	if (state->cps_version == 2)
		state->cps2_buffered_obj = auto_alloc_array_clear(machine, UINT16, state->cps2_obj_size / 2);

	/* clear RAM regions */
	memset(state->gfxram, 0, state->gfxram_size);			/* Clear GFX RAM */
	memset(state->cps_a_regs, 0, 0x40);				/* Clear CPS-A registers */
	memset(state->cps_b_regs, 0, 0x40);				/* Clear CPS-B registers */

	if (state->cps_version == 2)
	{
		memset(state->objram1, 0, state->cps2_obj_size);
		memset(state->objram2, 0, state->cps2_obj_size);
	}

	/* Put in some defaults */
	state->cps_a_regs[CPS1_OBJ_BASE]     = 0x9200;
	state->cps_a_regs[CPS1_SCROLL1_BASE] = 0x9000;
	state->cps_a_regs[CPS1_SCROLL2_BASE] = 0x9040;
	state->cps_a_regs[CPS1_SCROLL3_BASE] = 0x9080;
	state->cps_a_regs[CPS1_OTHER_BASE]   = 0x9100;

	/* This should never be hit, since game_config is set in MACHINE_RESET */
	assert_always(state->game_config, "state_game_config hasn't been set up yet");

	/* Set up old base */
	state->scroll1 = NULL;
	state->scroll2 = NULL;
	state->scroll3 = NULL;
	state->obj = NULL;
	state->other = NULL;
	cps1_get_video_base(machine);					/* Calculate base pointers */
	cps1_get_video_base(machine);					/* Calculate old base pointers */

	/* state save register */
	state_save_register_global(machine, state->scanline1);
	state_save_register_global(machine, state->scanline2);
	state_save_register_global(machine, state->scancalls);
	state_save_register_global(machine, state->last_sprite_offset);
	state_save_register_global(machine, state->pri_ctrl);
	state_save_register_global(machine, state->objram_bank);

	state_save_register_global_pointer(machine, state->buffered_obj, state->obj_size / 2);
	if (state->cps_version == 2)
	{
		state_save_register_global(machine, state->cps2_last_sprite_offset);
		state_save_register_global_pointer(machine, state->cps2_buffered_obj, state->cps2_obj_size / 2);
	}
	state_save_register_postload(machine, cps_postload, NULL);
}

VIDEO_START( cps1 )
{
	cps_state *state = machine->driver_data<cps_state>();

	state->cps_version = 1;
	VIDEO_START_CALL(cps);
}

VIDEO_START( cps2 )
{
	cps_state *state = machine->driver_data<cps_state>();

	state->cps_version = 2;
	VIDEO_START_CALL(cps);
}

/***************************************************************************

  Build palette from palette RAM

  12 bit RGB with a 4 bit brightness value.

***************************************************************************/

static void cps1_build_palette(running_machine *machine, const UINT16* const palette_base)
{
	cps_state *state = machine->driver_data<cps_state>();
	const UINT16 *palette_ram = palette_base;
	INT32 ctrl = state->cps_b_regs[state->game_config->palette_control / 2];

/*	The palette is copied only for pages that are enabled in the ctrl
	register. Note that if the first palette pages are skipped, all
	the following pages are scaled down. */
	UINT32 r, g, b, bright, palette, var;
	for (UINT32 page = 0; page < 6; ++page)
	{
		if (BIT(ctrl, page))
		{
			for (UINT32 offset = 0; offset < 0x200; ++offset)
			{
				palette = *(palette_ram++);

				/* from my understanding of the schematics, when the 'brightness'
				   component is set to 0 it should reduce brightness to 1/3 */

				bright = 0x0f + ((palette >> 12) << 1);
				var = bright * 0x11 / 0x2d;

				r = ((palette >> 8) & 0x0f) * var;
				g = ((palette >> 4) & 0x0f) * var;
				b = ((palette >> 0) & 0x0f) * var;

				palette_set_color (machine, 0x200 * page + offset, MAKE_RGB(r, g, b));
			}
		}
		else
		{
			// skip page in gfxram, but only if we have already copied at least one page
			if (palette_ram != palette_base)
				palette_ram += 0x200;
		}
	}
}



/***************************************************************************

                                Sprites
                                =======

  Sprites are represented by a number of 8 byte values

  xx xx yy yy nn nn aa aa

  where xxxx = x position
        yyyy = y position
        nnnn = tile number
        aaaa = attribute word
                    0x0001  colour
                    0x0002  colour
                    0x0004  colour
                    0x0008  colour
                    0x0010  colour
                    0x0020  X Flip
                    0x0040  Y Flip
                    0x0080  X & Y offset toggle (used in Marvel vs. Capcom.)
                    0x0100  X block size (in sprites)
                    0x0200  X block size
                    0x0400  X block size
                    0x0800  X block size
                    0x1000  Y block size (in sprites)
                    0x2000  Y block size
                    0x4000  Y block size
                    0x8000  Y block size

  The end of the table (may) be marked by an attribute value of 0xff00.

***************************************************************************/

static void cps1_find_last_sprite( running_machine *machine )		/* Find the offset of last sprite */
{
	cps_state *state = machine->driver_data<cps_state>();

	INT32 offset, size = state->obj_size / 2;

	if (state->game_config->bootleg_kludge == 3)
	{
		/* Locate the end of table marker */
		for (offset = 0; offset < size; offset += 4)
		{
			if ( state->buffered_obj[offset + 1] >= 0x8000 )
			{
				/* Marker found. This is the last sprite. */
				state->last_sprite_offset = offset - 4;
				return;
			}
		}
	}
	else
	{
		for (offset = 0; offset < size; offset += 4)
		{
			if ( (state->buffered_obj[offset + 3] & 0xff00) == 0xff00 )
			{
				state->last_sprite_offset = offset - 4;
				return;
			}
		}
	}
	/* Sprites must use full sprite RAM */
	state->last_sprite_offset = size - 4;
}


static void cps1_render_sprites( running_machine *machine, bitmap_t *bitmap, const rectangle *cliprect )
{
	cps_state *state = machine->driver_data<cps_state>();

#define DRAWSPRITE( CODE, COLOR, FLIPX, FLIPY, SX, SY )							 \
{													 \
	if (flip_screen_get(machine))									 \
		pdrawgfx_transpen( bitmap, cliprect, machine->gfx[2],					 \
				CODE, COLOR, !(FLIPX), !(FLIPY),					 \
				511 - 16 - (SX), 255 - 16 - (SY), machine->priority_bitmap, 0x02, 0x0f); \
	else												 \
		pdrawgfx_transpen( bitmap, cliprect, machine->gfx[2],					 \
				CODE, COLOR, FLIPX, FLIPY,						 \
				SX, SY,				  machine->priority_bitmap, 0x02, 0x0f); \
}
	UINT16 *base = state->buffered_obj;
	UINT32 code, colour, col;
	INT32 x, y, baseadd = 4;

	/* some sf2 hacks draw the sprites in reverse order */
	if (state->game_config->bootleg_kludge)
	{
		if (state->game_config->bootleg_kludge < 5)
		{
			base += state->last_sprite_offset;
			baseadd = -4;
		}
	}

	for (INT32 i = state->last_sprite_offset; i >= 0; i -= 4, base += baseadd)
	{
		x = *(base + 0);
		y = *(base + 1);
		code = *(base + 2);
		colour = *(base + 3);
		col = colour & 0x1f;
		code = gfxrom_bank_mapper(machine, GFXTYPE_SPRITES, code);

		if (code != -1)
		{
			if (colour & 0xff00 )
			{
				/* handle blocked sprites */
				UINT32 nx = ((colour & 0x0f00) >> 8) + 1;
				UINT32 ny = ((colour & 0xf000) >> 12) + 1;

				if (colour & 0x40)
				{
					/* Y flip */
					if (colour & 0x20)
					{
						for (UINT32 nys = 0; nys < ny; nys++)
							for (UINT32 nxs = 0; nxs < nx; nxs++)
								DRAWSPRITE( (code & ~0x0f) + ((code + nx - nxs - 1) & 0x0f) + 0x10 * (ny - 1 - nys),
									    col, 0x01, 0x01, (x + nxs * 16) & 0x01ff, (y + nys * 16) & 0x01ff);
					}
					else
					{
						for (UINT32 nys = 0; nys < ny; nys++)
							for (UINT32 nxs = 0; nxs < nx; nxs++)
								DRAWSPRITE( (code & ~0x0f) + ((code + nxs) & 0x0f) + 0x10 * (ny - 1 - nys),
									    col, 0x00, 0x01, (x + nxs * 16) & 0x01ff, (y + nys * 16) & 0x01ff);
					}
				}
				else
				{
					if (colour & 0x20)
					{
						for (UINT32 nys = 0; nys < ny; nys++)
							for (UINT32 nxs = 0; nxs < nx; nxs++)
								DRAWSPRITE( (code & ~0x0f) + ((code + nx - nxs - 1) & 0x0f) + 0x10 * nys,
									    col, 0x01, 0x00, (x + nxs * 16) & 0x01ff, (y + nys * 16) & 0x01ff);
					}
					else
					{
						for (UINT32 nys = 0; nys < ny; nys++)
							for (UINT32 nxs = 0; nxs < nx; nxs++)
								DRAWSPRITE( (code & ~0x0f) + ((code + nxs) & 0x0f) + 0x10 * nys, /* fix 00406: qadj: When playing as the ninja, there is one broekn frame in his animation loop when walking. */
									    col, 0x00, 0x00, (x + nxs * 16) & 0x01ff, (y + nys * 16) & 0x01ff);
					}
				}
			}
			else
				DRAWSPRITE( code, col, colour & 0x20, colour & 0x40, x & 0x01ff, y & 0x01ff );	/* Simple case... 1 sprite */
		}
	}
#undef DRAWSPRITE
}


WRITE16_HANDLER( cps2_objram_bank_w )
{
	if (ACCESSING_BITS_0_7)
	{
		cps_state *state = space->machine->driver_data<cps_state>();
		state->objram_bank = data & 1;
	}
}

READ16_HANDLER( cps2_objram1_r )
{
	cps_state *state = space->machine->driver_data<cps_state>();

	return (state->objram_bank & 0x01) ? state->objram2[offset] : state->objram1[offset];
}

READ16_HANDLER( cps2_objram2_r )
{
	cps_state *state = space->machine->driver_data<cps_state>();

	return (state->objram_bank & 0x01) ? state->objram1[offset] : state->objram2[offset];
}

WRITE16_HANDLER( cps2_objram1_w )
{
	cps_state *state = space->machine->driver_data<cps_state>();

	if (state->objram_bank & 0x01)
		COMBINE_DATA(&state->objram2[offset]);
	else
		COMBINE_DATA(&state->objram1[offset]);
}

WRITE16_HANDLER( cps2_objram2_w )
{
	cps_state *state = space->machine->driver_data<cps_state>();

	if (state->objram_bank & 0x01)
		COMBINE_DATA(&state->objram1[offset]);
	else
		COMBINE_DATA(&state->objram2[offset]);
}

static UINT16 *cps2_objbase( running_machine *machine )
{
	cps_state *state = machine->driver_data<cps_state>();
	int baseptr = 0x7000;

	if (state->objram_bank & 0x01)
		baseptr ^= 0x0080;

	return (baseptr == 0x7000) ? state->objram1 : state->objram2;
}


static void cps2_find_last_sprite( running_machine *machine )		/* Find the offset of last sprite */
{
	cps_state *state = machine->driver_data<cps_state>();
	UINT16 *base = state->cps2_buffered_obj;
	INT32 size = state->cps2_obj_size / 2;

	for (UINT32 offset = 0; offset < size; offset += 4)		/* Locate the end of table marker */
	{
		if (base[offset + 1] >= 0x8000 || base[offset + 3] >= 0xff00)
		{
			state->cps2_last_sprite_offset = offset - 4;	/* Marker found. This is the last sprite. */
			return;
		}
	}
	state->cps2_last_sprite_offset = size - 4;			/* Sprites must use full sprite RAM */
}


static void cps2_render_sprites( running_machine *machine, bitmap_t *bitmap, const rectangle *cliprect, int *primasks )
{
	cps_state *state = machine->driver_data<cps_state>();

#define DRAWSPRITE(CODE, COLOR, FLIPX, FLIPY, SX, SY)									\
{															\
	if (flip_screen_get(machine))											\
		pdrawgfx_transpen( bitmap, cliprect, machine->gfx[2],							\
				CODE, COLOR, !(FLIPX), !(FLIPY),							\
				511 - 16 - (SX), 255 - 16 - (SY), machine->priority_bitmap, primasks[priority], 0x0f);	\
	else														\
		pdrawgfx_transpen( bitmap, cliprect, machine->gfx[2],							\
				CODE, COLOR, FLIPX, FLIPY,								\
				SX, SY,				  machine->priority_bitmap, primasks[priority], 0x0f);	\
}
	UINT16 *base = state->cps2_buffered_obj;
	UINT32 col, code, colour, priority;
	INT32 xoffs = 64 - cps2_port(machine, CPS2_OBJ_XOFFS), x;
	INT32 yoffs = 16 - cps2_port(machine, CPS2_OBJ_YOFFS), y;

	for (INT32 i = state->cps2_last_sprite_offset; i >= 0; i -= 4)
	{
		x = base[i + 0];
		y = base[i + 1];
		priority = (x >> 13) & 0x07;
		code = base[i + 2] + ((y & 0x6000) << 3);
		colour = base[i + 3];
		col = colour & 0x1f;

		if (colour & 0x80)
		{
			x += cps2_port(machine, CPS2_OBJ_XOFFS);  /* fix the offset of some games */
			y += cps2_port(machine, CPS2_OBJ_YOFFS);  /* like Marvel vs. Capcom ending credits */
		}

		if (colour & 0xff00)
		{
			/* handle blocked sprites */
			UINT32 nx = ((colour & 0x0f00) >> 8) + 1;
			UINT32 ny = ((colour & 0xf000) >> 12) + 1;
			INT32 x_coord = x + xoffs, y_coord = y + yoffs;

			if (colour & 0x40)
			{
				if (colour & 0x20)	/* Y flip */
				{
					for (UINT32 nys = 0; nys < ny; nys++)
						for (UINT32 nxs = 0; nxs < nx; nxs++)
							DRAWSPRITE( code + (nx - 1) - nxs + 0x10 * (ny - 1 - nys), col, 0x01, 0x01,
									(x_coord + nxs * 16) & 0x03ff, (y_coord + nys * 16) & 0x03ff );
				}
				else
				{
					for (UINT32 nys = 0; nys < ny; nys++)
						for (UINT32 nxs = 0; nxs < nx; nxs++)
							DRAWSPRITE( code + nxs + 0x10 * (ny - 1 - nys), col, 0x00, 0x01,
									(x_coord + nxs * 16) & 0x03ff, (y_coord + nys * 16) & 0x03ff );
				}
			}
			else
			{
				if (colour & 0x20)
				{
					for (UINT32 nys = 0; nys < ny; nys++)
						for (UINT32 nxs = 0; nxs < nx; nxs++)
							DRAWSPRITE( code + (nx - 1) - nxs + 0x10 * nys, col, 0x01, 0x00,
									(x_coord + nxs * 16) & 0x03ff, (y_coord + nys * 16) & 0x03ff );
				}
				else
				{
					for (UINT32 nys = 0; nys < ny; nys++)
						for (UINT32 nxs = 0; nxs < nx; nxs++)
							DRAWSPRITE( (code & ~0x0f) + ((code + nxs) & 0x0f) + 0x10 * nys,/* pgear fix */col, 0x00, 0x00,
									(x_coord + nxs * 16) & 0x03ff, (y_coord + nys * 16) & 0x03ff );
				}
			}
		}
		else
			DRAWSPRITE( code, col, colour & 0x20, colour & 0x40, (x + xoffs) & 0x03ff, (y + yoffs) & 0x03ff);	/* Simple case... 1 sprite */
	}
}


static void cps1_render_stars( screen_device *screen, bitmap_t *bitmap, const rectangle *cliprect )
{
	cps_state *state = screen->machine->driver_data<cps_state>();
	UINT8 *stars_rom = memory_region(screen->machine, "stars");

	if (!stars_rom && (state->stars_enabled[0] || state->stars_enabled[1])) return;

	INT32 offs, col, sx, sy, size = state->stars_rom_size / 2;

	if (state->stars_enabled[0])
	{
		for (offs = 0; offs < size; offs++)
		{
			col = stars_rom[8 * offs + 4];
			if (col != 0x0f)
			{
				sx = ((offs >> 3) - state->stars2x + (col & 0x1f)) & 0x01ff;
				sy = ((offs & 0xff) - state->stars2y) & 0xff;
				if (flip_screen_get(screen->machine))
				{
					sx = 511 - sx;
					sy = 255 - sy;
				}

				col = ((col & 0xe0) >> 1) + (screen->frame_number() / 16 & 0x0f);

				if (sx >= cliprect->min_x && sx <= cliprect->max_x)
					if (sy >= cliprect->min_y && sy <= cliprect->max_y)
						*BITMAP_ADDR16(bitmap, sy, sx) = 0x0a00 + col;
			}
		}
	}

	if (state->stars_enabled[1])
	{
		for (offs = 0; offs < size; offs++)
		{
			col = stars_rom[8 * offs];
			if (col != 0x0f)
			{
				sx = ((offs >> 3) - state->stars1x + (col & 0x1f)) & 0x01ff;
				sy = ((offs & 0xff) - state->stars1y) & 0xff;
				if (flip_screen_get(screen->machine))
				{
					sx = 511 - sx;
					sy = 255 - sy;
				}

				col = ((col & 0xe0) >> 1) + (screen->frame_number() / 16 & 0x0f);

				if (sx >= cliprect->min_x && sx <= cliprect->max_x)
					if (sy >= cliprect->min_y && sy <= cliprect->max_y)
						*BITMAP_ADDR16(bitmap, sy, sx) = 0x0800 + col;
			}
		}
	}
}


static void cps1_render_layer( running_machine *machine, bitmap_t *bitmap, const rectangle *cliprect, int layer, int primask )
{
	cps_state *state = machine->driver_data<cps_state>();
	switch (layer)
	{
		case 0: cps1_render_sprites(machine, bitmap, cliprect); break;
		case 1:
		case 2:
		case 3: tilemap_draw(bitmap, cliprect, state->bg_tilemap[layer - 1], TILEMAP_DRAW_LAYER1, primask); break;
	}
}

static void cps1_render_high_layer( running_machine *machine, bitmap_t *bitmap, const rectangle *cliprect, int layer )
{
	cps_state *state = machine->driver_data<cps_state>();
	switch (layer)
	{
		case 0: break; /* there are no high priority sprites */
		case 1:
		case 2:
		case 3: tilemap_draw(NULL, cliprect, state->bg_tilemap[layer - 1], TILEMAP_DRAW_LAYER0, 1); break;
	}
}


/***************************************************************************

    Refresh screen

***************************************************************************/

VIDEO_UPDATE( cps1 )
{
	cps_state *state = screen->machine->driver_data<cps_state>();

	INT32 videocontrol = state->cps_a_regs[CPS1_VIDEOCONTROL];
	INT32 flipflag = state->force_screen_flip_flag ? 0 : videocontrol & 0x8000;

	flip_screen_set(screen->machine, flipflag);

	/* Get video memory base registers */
	cps1_get_video_base(screen->machine);
	/* Find the offset of the last sprite in the sprite table */
	if (state->cps_version == 2)
		cps2_find_last_sprite(screen->machine);
	else
		cps1_find_last_sprite(screen->machine);

	cps1_update_transmasks(screen->machine);

	tilemap_set_scrollx(state->bg_tilemap[0], 0, state->scroll1x);
	tilemap_set_scrolly(state->bg_tilemap[0], 0, state->scroll1y);

	if (videocontrol & 0x01)	/* linescroll enable */
	{
		tilemap_set_scroll_rows(state->bg_tilemap[1], 1024);

		INT32 scrly = -state->scroll2y;
		INT32 otheroffs = state->cps_a_regs[CPS1_ROWSCROLL_OFFS];

		for (UINT32 i = 0; i < 256; )
		{
			tilemap_set_scrollx(state->bg_tilemap[1], (i - scrly) & 0x03ff, state->scroll2x + state->other[(i + otheroffs) & 0x03ff]); i++;
			tilemap_set_scrollx(state->bg_tilemap[1], (i - scrly) & 0x03ff, state->scroll2x + state->other[(i + otheroffs) & 0x03ff]); i++;
			tilemap_set_scrollx(state->bg_tilemap[1], (i - scrly) & 0x03ff, state->scroll2x + state->other[(i + otheroffs) & 0x03ff]); i++;
			tilemap_set_scrollx(state->bg_tilemap[1], (i - scrly) & 0x03ff, state->scroll2x + state->other[(i + otheroffs) & 0x03ff]); i++;
		}
	}
	else
	{
		tilemap_set_scroll_rows(state->bg_tilemap[1], 1);
		tilemap_set_scrollx(state->bg_tilemap[1], 0, state->scroll2x);
	}
	tilemap_set_scrolly(state->bg_tilemap[1], 0, state->scroll2y);
	tilemap_set_scrollx(state->bg_tilemap[2], 0, state->scroll3x);
	tilemap_set_scrolly(state->bg_tilemap[2], 0, state->scroll3y);

	/* Blank screen */
	if (state->cps_version == 1)
	{
/*		CPS1 games use pen 0xbff as background color; this is used in 3wonders,
		mtwins (explosion during attract), mercs (intermission). */
		bitmap_fill(bitmap, cliprect, 0x0bff);
		cps1_render_stars(screen, bitmap, cliprect);
	}
	else
	{
/*		CPS2 apparently always force the background to black. Several games would
		should a blue screen during boot if we used the same code as CPS1.
		Maybe Capcom changed the background handling due to the problems that
		it caused on several monitors (because the background extended into the
		blanking area instead of going black, causing the monitor to clip). */
		bitmap_fill(bitmap, cliprect, get_black_pen(screen->machine));
	}

	bitmap_fill(screen->machine->priority_bitmap, cliprect, 0);

	/* Draw layers (0 = sprites, 1-3 = tilemaps) */
	INT32 layercontrol = state->cps_b_regs[state->game_config->layer_control / 2];

	INT32 l0 = (layercontrol >> 0x06) & 0x03;
	INT32 l1 = (layercontrol >> 0x08) & 0x03;
	INT32 l2 = (layercontrol >> 0x0a) & 0x03;
	INT32 l3 = (layercontrol >> 0x0c) & 0x03;

	if (state->cps_version == 1)
	{
		if (state->game_config->bootleg_kludge > 0x87)				/* - for cps1frog / fixed 3wondersb */
			cps1_build_palette(screen->machine, cps1_base(screen->machine, CPS1_PALETTE_BASE, state->palette_align));

		cps1_render_layer(screen->machine, bitmap, cliprect, l0, 0);
		if (l1 == 0) cps1_render_high_layer(screen->machine, bitmap, cliprect, l0); /* prepare mask for sprites */

		cps1_render_layer(screen->machine, bitmap, cliprect, l1, 0);
		if (l2 == 0) cps1_render_high_layer(screen->machine, bitmap, cliprect, l1); /* prepare mask for sprites */

		cps1_render_layer(screen->machine, bitmap, cliprect, l2, 0);
		if (l3 == 0) cps1_render_high_layer(screen->machine, bitmap, cliprect, l2); /* prepare mask for sprites */

		cps1_render_layer(screen->machine, bitmap, cliprect, l3, 0);
	}
	else
	{
		INT32 l0pri = (state->pri_ctrl >> 4 * l0) & 0x0f;
		INT32 l1pri = (state->pri_ctrl >> 4 * l1) & 0x0f;
		INT32 l2pri = (state->pri_ctrl >> 4 * l2) & 0x0f;
		INT32 l3pri = (state->pri_ctrl >> 4 * l3) & 0x0f;

		/* take out the CPS1 sprites layer */
		if (l0 == 0) { l0 = l1; l1 = 0; l0pri = l1pri; }
		if (l1 == 0) { l1 = l2; l2 = 0; l1pri = l2pri; }
		if (l2 == 0) { l2 = l3; l3 = 0; l2pri = l3pri; }

		INT32 primasks[8];
		{
			INT32 mask0 = 0xaa, mask1 = 0xcc;
			if (l0pri > l1pri) mask0 &= ~0x88;
			if (l0pri > l2pri) mask0 &= ~0xa0;
			if (l1pri > l2pri) mask1 &= ~0xc0;

			primasks[0] = 0xff;

			for (UINT32 i = 1; i < 8; i++)
			{
				if (i <= l0pri)
					if (i <= l1pri && i <= l2pri)
					{
						primasks[i] = 0xfe;
						continue;
					}

				primasks[i] = 0;

				if (i <= l0pri) primasks[i] |= mask0;
				if (i <= l1pri) primasks[i] |= mask1;
				if (i <= l2pri) primasks[i] |= 0xf0;
			}
		}
		cps1_render_layer(screen->machine, bitmap, cliprect, l0, 1);
		cps1_render_layer(screen->machine, bitmap, cliprect, l1, 2);
		cps1_render_layer(screen->machine, bitmap, cliprect, l2, 4);
		cps2_render_sprites(screen->machine, bitmap, cliprect, primasks);
	}

	return 0;
}


VIDEO_EOF( cps1 )
{
	cps_state *state = machine->driver_data<cps_state>();
	/* Get video memory base registers */
	cps1_get_video_base(machine);

	/* CPS1 sprites have to be delayed one frame */
	if (state->cps_version == 1)
		memcpy(state->buffered_obj, state->obj, state->obj_size);
}

void cps2_set_sprite_priorities( running_machine *machine )
{
	cps_state *state = machine->driver_data<cps_state>();
	state->pri_ctrl = cps2_port(machine, CPS2_OBJ_PRI);
}

void cps2_objram_latch( running_machine *machine )
{
	cps_state *state = machine->driver_data<cps_state>();
	cps2_set_sprite_priorities(machine);
	memcpy(state->cps2_buffered_obj, cps2_objbase(machine), state->cps2_obj_size);
}

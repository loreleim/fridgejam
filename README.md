# Fridge Jam
 onion piano! conductive soundscapes w/arduino

<img align="center" alt="Cardboard fridge with onion keyboard" width="500px" src="https://raw.githubusercontent.com/loreleim/fridgejam/main/images/image9.jpg" />

## Table of Contents
1. [Abstract](#abstract)
1. [ACM Standards](#acm-standards)
1. [Inspiration](#inspiration)
1. [User Research](#user-research)
1. [Schematic](#schematic)
1. [RC522](#rc522)
1. [MPR121](#mpr121)
1. [Reflection](#reflection)
1. [Bibliography](#bibliography)

## Abstract
Designed similarly to MIDI devices such as soundboards and launchpads, Fridge Jam utilizes conductive switches and NFC data frames to explore ranges of audio in a closed system soundscape. These soundscapes are defined and dictated by NFC datacards. Where the NFC functionality passports a user to various types of audio libraries. Utilization of conductive switches allows user agency in formatting their unique compositions. Wherein, Fridge Jam promotes autonomy by allowing users to decide their tools to navigate environments of pre-made audio.

[back to top](#table-of-contents)

## ACM Standards
* B.4.1: Input/Output Devices: Utilization of Arduino modules such as the MPR121 Capacitive Touch Sensor and the RC522 Radio Frequency Identification aim to function as input devices for data systems. Speakers and computing audio are utilized as forms of output devices.
* B.4.3: Interconnections (Subsystems): Fridge Jam is designed as a closed loop system. This loop starts and ends with the power button -- where at start -- users are prompted to utilize NFC UIDs to change various sound libraries within the device. This loop continues through various opportunities of interaction, including utilization of non-switch  buttons to play respective audio scales, unique identifiers and audio libraries.
* E.2: Data Storage Representations: Data in this device is represented by various forms of Hexadecimal, Binary, and 8 bit information. Hexadecimal and Binary data are handled on the NFC layers. Where 8 bit info has been handled on the audio output layer.
* H.5.5: Sound and Music Computing: Conversion of .mp3 files to 8-bit data structures to allow arduino to call on and manipulate audio via a speaker module.

[back to top](#table-of-contents)

## Inspiration

<img align="center" alt="early 2000s leapfrog tablet blue and green folder" width="500px" src="https://raw.githubusercontent.com/loreleim/fridgejam/main/images/image1.jpg" />

TL;DR
Fridge Jam’s design follows influence from the interaction flow used in the early 2000s Leapfrog tablets, LeapPad. These tablets utilized NFC technology to read pages of a book out loud to a child interacting with it. 

<img align="center" alt="4 people in a coffee shop around a table" width="500px" src="https://raw.githubusercontent.com/loreleim/fridgejam/main/images/image5.png" />

TL;DR
Similarly, capacitive interaction models have also been built in coffee tables. A group at the Chalmers University of Technology in Sweden designed an Interactive Coffee Table. This table was a musical device that promoted modes of co-creation between strangers in a coffee shop.

[back to top](#table-of-contents)

## User Research
In user experience considerations, we put ourselves into the shoes of the lowest knowledgeable subject. In the case of music development, this would be considered the music enthusiast. The enthusiast, upon display of the 66 key electronic keyboard feels overwhelmed by the sheer number of keys available. Or when given the child’s recorder, the enthusiast feels unaccustomed to a woodwind’s affordance of holes. Those holes, in the enthusiast’s mind, apparently must be covered in order to make certain notes. But which notes, and which way must one’s hand cover certain holes? To say the least, musical devices that require forms of multitasking or subset knowledge, create onboarding experiences that drive users away, instead of inviting them in.

Primary goals of interaction:
- [ ] Autonomous electroacoustic performances
- [ ] Instrument augmentation through considerations on musical scales & environment sampling
- [ ] Capture users’ mental models of buttons to further implement affordances of buttons for capacitive interfaces.
- [ ] Utilize HCI guidelines to reinforce feedback detection and promote user agency

[back to top](#table-of-contents)

## Schematic

<img align="center" alt="microcontroller schematic of wires and breadboard" width="500px" src="https://raw.githubusercontent.com/loreleim/fridgejam/main/images/image3.jpg" />

Fridge Jam consists of two input devices, and one output device. The input is handled by an RC522 NFC/RFID reader and a MPR121 capacitive touch module. On a complex addition, a LCD 16x02 screen may also be included. Pending time constraints, consideration of this module can be utilized flexibly. 

[back to top](#table-of-contents)

## RC522

The RC522 functions as the NFC reader in this schematic. The RC522 allows reading of hexadecimal data that can then be compared to a written c++ library.  This library would further contain data for audio PCM files. 

[back to top](#table-of-contents)

## MPR121

The MPR121 has been included to allow users to define unique types of buttons within their space. (See paragraph 2.3 for more technical info about the MPR121 module).

[back to top](#table-of-contents)

## Reflection
Fridge Jam works for both musical experts and casual users. On a domestic level, Fridge Jam is a device that can be utilized in a bedroom or household environment. As buttons can be whatever a user choses, the reliability of the build is as the user defines. Buttons can be as large or as small as desired. As such, this customizability allows this device to work for a wide age range. As smaller buttons may hold ingestion or breakability dangers when used by younger children. Buttons can be replaced by plush toys or even food items. Inviting interactivity or teaching tactility and response to developing toddlers. 

On a larger scale, this conductivity capacitance can be utilized in a guerilla context. When Fridge Jam is connected to commonly touched surfaces such as buttons in an elevator, trash can handles, car doors, or even bus seats -- the mundane gets transformed into public, interactive soundscapes. Wherein, there is opportunity for surprise. Users of those mundane interactions don’t experience auditory feedback. That unexpected element promotes a sense of community, as many individuals are seemingly experiencing the same out of the ordinary phenomenon of musical bus seats. Fridge Jam affords opportunities for musical co-creation in the public domain. 

<img align="center" alt="microcontroller schematic of wires and breadboard" width="500px" src="https://raw.githubusercontent.com/loreleim/fridgejam/main/images/image2.jpg" />

[back to top](#table-of-contents)

## Bibliography

Bowden, Zac. Retro review: Microsoft’s 2008 Surface ‘coffee table’ in 2017. Windows Central. 15 February 2017. Web. Date accessed 11 December 2020.

Museum of Obsolete Media. LeapPad (1999-2008). N.d. Date accessed 11 December 2020. 

NXP B.V. MFRC522: Standard performance MIFARE and NTAG frontend. 27 April 2016. Datasheet. Date accessed 11 December 2020.

NXP B.V. MIFARE Classic EV1 1K - Mainstream contactless smart card IC for fast and easy solution development. 23 May 2018. Datasheet. Date accessed 11 December 2020. 

Paragon ID. Do you have a hole in your business model that could be filled by Radio frequency identification (RFID) technology? N.d. Date accessed 11 December 2020.

Robert Fohlin, Peter Kun, Laura Rebolo, Markus Jansson, Niels Swinkels. “Music co-creation in public spaces via interactive coffee tables.” Department of Applied IT Chalmers University of Technology, Sweden. N.d. Scientific Journal. Date accessed 11 December 2020. 

[back to top](#table-of-contents)

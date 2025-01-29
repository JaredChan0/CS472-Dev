/*
 *  testframes.h
 *
 *  PUT SAMPLE FRAMES CAPTURED FROM WIRESHARK HERE.  Note below the arrays that we
 *  will be processing i have included a few samples and also capture the wireshark
 *  decoded values and the wireshark binary capture.  Right-Click on the wireshark
 *  decoded frame and hit Copy-> then all visible items
 */

#include <stdint.h>

typedef struct test_packet{
    uint8_t     *raw_packet;
    uint64_t    packet_len;
}test_packet_t;

#define MAKE_PACKET(p) {p, sizeof(p)}

uint8_t raw_packet_arp_frame78[] = {
  0xc8, 0x89, 0xf3, 0xea, 0x93, 0x14, 0xa0, 0x36,
  0xbc, 0x62, 0xed, 0x50, 0x08, 0x06, 0x00, 0x01,
  0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0xa0, 0x36,
  0xbc, 0x62, 0xed, 0x50, 0xc0, 0xa8, 0x32, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xa8,
  0x32, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};
/*
Frame 78: 60 bytes on wire (480 bits), 60 bytes captured (480 bits) on interface en0, id 0
    Section number: 1
    Interface id: 0 (en0)
    Encapsulation type: Ethernet (1)
    Arrival Time: Sep 24, 2023 09:57:27.654257000 EDT
    [Time shift for this packet: 0.000000000 seconds]
    Epoch Time: 1695563847.654257000 seconds
    [Time delta from previous captured frame: 0.474723000 seconds]
    [Time delta from previous displayed frame: 0.000000000 seconds]
    [Time since reference or first frame: 3.263589000 seconds]
    Frame Number: 78
    Frame Length: 60 bytes (480 bits)
    Capture Length: 60 bytes (480 bits)
    [Frame is marked: False]
    [Frame is ignored: False]
    [Protocols in frame: eth:ethertype:arp]
    [Coloring Rule Name: ARP]
    [Coloring Rule String: arp]
Ethernet II, Src: ASUSTekC_62:ed:50 (a0:36:bc:62:ed:50), Dst: Apple_ea:93:14 (c8:89:f3:ea:93:14)
    Destination: Apple_ea:93:14 (c8:89:f3:ea:93:14)
    Source: ASUSTekC_62:ed:50 (a0:36:bc:62:ed:50)
    Type: ARP (0x0806)
    Padding: 000000000000000000000000000000000000
Address Resolution Protocol (request)
    Hardware type: Ethernet (1)
    Protocol type: IPv4 (0x0800)
    Hardware size: 6
    Protocol size: 4
    Opcode: request (1)
    Sender MAC address: ASUSTekC_62:ed:50 (a0:36:bc:62:ed:50)
    Sender IP address: 192.168.50.1
    Target MAC address: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Target IP address: 192.168.50.99

0000   c8 89 f3 ea 93 14 a0 36 bc 62 ed 50 08 06 00 01
0010   08 00 06 04 00 01 a0 36 bc 62 ed 50 c0 a8 32 01
0020   00 00 00 00 00 00 c0 a8 32 63 00 00 00 00 00 00
0030   00 00 00 00 00 00 00 00 00 00 00 00


*/


//This is an ICMP ping request message
uint8_t raw_packet_icmp_frame362[] = {
  0xa0, 0x36, 0xbc, 0x62, 0xed, 0x50, 0xc8, 0x89,
  0xf3, 0xea, 0x93, 0x14, 0x08, 0x00, 0x45, 0x00,
  0x00, 0x54, 0x2a, 0xec, 0x00, 0x00, 0x40, 0x01,
  0x89, 0x31, 0xc0, 0xa8, 0x32, 0x63, 0x90, 0x76,
  0x43, 0x0a, 0x08, 0x00, 0x7b, 0xda, 0x48, 0x59,
  0x00, 0x00, 0x65, 0x0e, 0x01, 0xee, 0x00, 0x00,
  0xe1, 0xcc, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d,
  0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
  0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d,
  0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,
  0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d,
  0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35,
  0x36, 0x37
};

/*
WIRESHARK DECODED:

Frame 362: 98 bytes on wire (784 bits), 98 bytes captured (784 bits) on interface en0, id 0
Ethernet II, Src: Apple_ea:93:14 (c8:89:f3:ea:93:14), Dst: ASUSTekC_62:ed:50 (a0:36:bc:62:ed:50)
Internet Protocol Version 4, Src: 192.168.50.99, Dst: 144.118.67.10
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
    Total Length: 84
    Identification: 0x2aec (10988)
    000. .... = Flags: 0x0
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 64
    Protocol: ICMP (1)
    Header Checksum: 0x8931 [validation disabled]
    [Header checksum status: Unverified]
    Source Address: 192.168.50.99
    Destination Address: 144.118.67.10
Internet Control Message Protocol
    Type: 8 (Echo (ping) request)
    Code: 0
    Checksum: 0x7bda [correct]
    [Checksum Status: Good]
    Identifier (BE): 18521 (0x4859)
    Identifier (LE): 22856 (0x5948)
    Sequence Number (BE): 0 (0x0000)
    Sequence Number (LE): 0 (0x0000)
    [Response frame: 363]
    Timestamp from icmp data: Sep 22, 2023 17:06:54.057804000 EDT
    [Timestamp from icmp data (relative): 0.034783000 seconds]
    Data (48 bytes)

    BINARY WINDOW:

    0000   a0 36 bc 62 ed 50 c8 89 f3 ea 93 14 08 00 45 00
    0010   00 54 2a ec 00 00 40 01 89 31 c0 a8 32 63 90 76
    0020   43 0a 08 00 7b da 48 59 00 00 65 0e 01 ee 00 00
    0030   e1 cc 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15
    0040   16 17 18 19 1a 1b 1c 1d 1e 1f 20 21 22 23 24 25
    0050   26 27 28 29 2a 2b 2c 2d 2e 2f 30 31 32 33 34 35
    0060   36 37
*/

uint8_t raw_packet_icmp_frame198[] = {
  0xc8, 0x89, 0xf3, 0xea, 0x93, 0x14, 0xa0, 0x36,
  0xbc, 0x62, 0xed, 0x50, 0x08, 0x00, 0x45, 0xc0,
  0x00, 0x50, 0xa8, 0xfa, 0x00, 0x00, 0x40, 0x01,
  0xeb, 0x3d, 0xc0, 0xa8, 0x32, 0x01, 0xc0, 0xa8,
  0x32, 0x63, 0x0b, 0x00, 0xbb, 0xbd, 0x00, 0x00,
  0x00, 0x00, 0x45, 0x00, 0x00, 0x34, 0xea, 0x3b,
  0x00, 0x00, 0x01, 0x11, 0x08, 0xf2, 0xc0, 0xa8,
  0x32, 0x63, 0x90, 0x76, 0x43, 0x0a, 0xea, 0x3a,
  0x82, 0x9b, 0x00, 0x20, 0xcc, 0x4b, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/*
Frame 198: 94 bytes on wire (752 bits), 94 bytes captured (752 bits) on interface en0, id 0
Ethernet II, Src: ASUSTekC_62:ed:50 (a0:36:bc:62:ed:50), Dst: Apple_ea:93:14 (c8:89:f3:ea:93:14)
Internet Protocol Version 4, Src: 192.168.50.1, Dst: 192.168.50.99
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0xc0 (DSCP: CS6, ECN: Not-ECT)
    Total Length: 80
    Identification: 0xa8fa (43258)
    000. .... = Flags: 0x0
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 64
    Protocol: ICMP (1)
    Header Checksum: 0xeb3d [validation disabled]
    [Header checksum status: Unverified]
    Source Address: 192.168.50.1
    Destination Address: 192.168.50.99
Internet Control Message Protocol
    Type: 11 (Time-to-live exceeded)
    Code: 0 (Time to live exceeded in transit)
    Checksum: 0xbbbd [correct]
    [Checksum Status: Good]
    Unused: 00000000
    Internet Protocol Version 4, Src: 192.168.50.99, Dst: 144.118.67.10
        0100 .... = Version: 4
        .... 0101 = Header Length: 20 bytes (5)
        Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
        Total Length: 52
        Identification: 0xea3b (59963)
        000. .... = Flags: 0x0
        ...0 0000 0000 0000 = Fragment Offset: 0
        Time to Live: 1
        Protocol: UDP (17)
        Header Checksum: 0x08f2 [validation disabled]
        [Header checksum status: Unverified]
        Source Address: 192.168.50.99
        Destination Address: 144.118.67.10
    User Datagram Protocol, Src Port: 59962, Dst Port: 33435
Data (24 bytes)


0000   c8 89 f3 ea 93 14 a0 36 bc 62 ed 50 08 00 45 c0
0010   00 50 a8 fa 00 00 40 01 eb 3d c0 a8 32 01 c0 a8
0020   32 63 0b 00 bb bd 00 00 00 00 45 00 00 34 ea 3b
0030   00 00 01 11 08 f2 c0 a8 32 63 90 76 43 0a ea 3a
0040   82 9b 00 20 cc 4b 00 00 00 00 00 00 00 00 00 00
0050   00 00 00 00 00 00 00 00 00 00 00 00 00 00

*/

uint8_t my_raw_request_icmp_frame[] = {
  0xb8, 0xf8, 0x53, 0x55, 0xa8, 0x1a, 0x84, 0xfd,
  0xd1, 0xca, 0x8f, 0x3c, 0x08, 0x00, 0x45, 0x00,
  0x00, 0x54, 0x08, 0xfa, 0x00, 0x00, 0x80, 0x01,
  0x5f, 0x0c, 0xc0, 0xa8, 0x01, 0xeb, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x00, 0x43, 0xff, 0x00, 0x02,
  0x00, 0x10, 0x67, 0x9a, 0x63, 0x2d, 0x00, 0x00,
  0x00, 0x00, 0xb5, 0x28, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
  0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d,
  0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,
  0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d,
  0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35,
  0x36, 0x37
};

/*
Frame 553: 98 bytes on wire (784 bits), 98 bytes captured (784 bits) on interface \Device\NPF_{F7328786-5D5F-4B80-A349-62B5E4403717}, id 0
Ethernet II, Src: Intel_ca:8f:3c (84:fd:d1:ca:8f:3c), Dst: Arcadyan_55:a8:1a (b8:f8:53:55:a8:1a)
Internet Protocol Version 4, Src: 192.168.1.235, Dst: 8.8.8.8
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
    Total Length: 84
    Identification: 0x08fa (2298)
    000. .... = Flags: 0x0
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 128
    Protocol: ICMP (1)
    Header Checksum: 0x5f0c [validation disabled]
    [Header checksum status: Unverified]
    Source Address: 192.168.1.235
    Destination Address: 8.8.8.8
    [Stream index: 6]
Internet Control Message Protocol
    Type: 8 (Echo (ping) request)
    Code: 0
    Checksum: 0x43ff [correct]
    [Checksum Status: Good]
    Identifier (BE): 2 (0x0002)
    Identifier (LE): 512 (0x0200)
    Sequence Number (BE): 16 (0x0010)
    Sequence Number (LE): 4096 (0x1000)
    [Response frame: 554]
    Timestamp from icmp data: Jan 29, 2025 17:19:41.141493000 Eastern Standard Time
    [Timestamp from icmp data (relative): 0.000463000 seconds]
    Data (40 bytes)
        Data: 101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f3031323334353637
        [Length: 40]


0000   b8 f8 53 55 a8 1a 84 fd d1 ca 8f 3c 08 00 45 00
0010   00 54 08 fa 00 00 80 01 5f 0c c0 a8 01 eb 08 08
0020   08 08 08 00 43 ff 00 02 00 10 67 9a 63 2d 00 00
0030   00 00 b5 28 02 00 00 00 00 00 10 11 12 13 14 15
0040   16 17 18 19 1a 1b 1c 1d 1e 1f 20 21 22 23 24 25
0050   26 27 28 29 2a 2b 2c 2d 2e 2f 30 31 32 33 34 35
0060   36 37
*/

uint8_t my_raw_reply_icmp_frame[] = {
  0x84, 0xfd, 0xd1, 0xca, 0x8f, 0x3c, 0xb8, 0xf8,
  0x53, 0x55, 0xa8, 0x1a, 0x08, 0x00, 0x45, 0x60,
  0x00, 0x54, 0x00, 0x00, 0x00, 0x00, 0x77, 0x01,
  0x70, 0xa6, 0x08, 0x08, 0x08, 0x08, 0xc0, 0xa8,
  0x01, 0xeb, 0x00, 0x00, 0x4b, 0xff, 0x00, 0x02,
  0x00, 0x10, 0x67, 0x9a, 0x63, 0x2d, 0x00, 0x00,
  0x00, 0x00, 0xb5, 0x28, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
  0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d,
  0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,
  0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d,
  0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35,
  0x36, 0x37
};

/*
Frame 554: 98 bytes on wire (784 bits), 98 bytes captured (784 bits) on interface \Device\NPF_{F7328786-5D5F-4B80-A349-62B5E4403717}, id 0
Ethernet II, Src: Arcadyan_55:a8:1a (b8:f8:53:55:a8:1a), Dst: Intel_ca:8f:3c (84:fd:d1:ca:8f:3c)
Internet Protocol Version 4, Src: 8.8.8.8, Dst: 192.168.1.235
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x60 (DSCP: CS3, ECN: Not-ECT)
    Total Length: 84
    Identification: 0x0000 (0)
    000. .... = Flags: 0x0
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 119
    Protocol: ICMP (1)
    Header Checksum: 0x70a6 [validation disabled]
    [Header checksum status: Unverified]
    Source Address: 8.8.8.8
    Destination Address: 192.168.1.235
    [Stream index: 6]
Internet Control Message Protocol
    Type: 0 (Echo (ping) reply)
    Code: 0
    Checksum: 0x4bff [correct]
    [Checksum Status: Good]
    Identifier (BE): 2 (0x0002)
    Identifier (LE): 512 (0x0200)
    Sequence Number (BE): 16 (0x0010)
    Sequence Number (LE): 4096 (0x1000)
    [Request frame: 553]
    [Response time: 7.008 ms]
    Timestamp from icmp data: Jan 29, 2025 17:19:41.141493000 Eastern Standard Time
    [Timestamp from icmp data (relative): 0.007471000 seconds]
    Data (40 bytes)
        Data: 101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f3031323334353637
        [Length: 40]

0000   84 fd d1 ca 8f 3c b8 f8 53 55 a8 1a 08 00 45 60
0010   00 54 00 00 00 00 77 01 70 a6 08 08 08 08 c0 a8
0020   01 eb 00 00 4b ff 00 02 00 10 67 9a 63 2d 00 00
0030   00 00 b5 28 02 00 00 00 00 00 10 11 12 13 14 15
0040   16 17 18 19 1a 1b 1c 1d 1e 1f 20 21 22 23 24 25
0050   26 27 28 29 2a 2b 2c 2d 2e 2f 30 31 32 33 34 35
0060   36 37
*/

uint8_t my_raw_arp_frame[] = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5a, 0x59,
  0x6b, 0x05, 0xd1, 0x63, 0x08, 0x06, 0x00, 0x01,
  0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x5a, 0x59,
  0x6b, 0x05, 0xd1, 0x63, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x36,
  0x10, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

/*
Frame 3: 52 bytes on wire (416 bits), 52 bytes captured (416 bits) on interface \Device\NPF_{F7328786-5D5F-4B80-A349-62B5E4403717}, id 0
    Section number: 1
    Interface id: 0 (\Device\NPF_{F7328786-5D5F-4B80-A349-62B5E4403717})
    Encapsulation type: Ethernet (1)
    Arrival Time: Jan 29, 2025 16:59:45.353052000 Eastern Standard Time
    UTC Arrival Time: Jan 29, 2025 21:59:45.353052000 UTC
    Epoch Arrival Time: 1738187985.353052000
    [Time shift for this packet: 0.000000000 seconds]
    [Time delta from previous captured frame: 0.006562000 seconds]
    [Time delta from previous displayed frame: 0.000000000 seconds]
    [Time since reference or first frame: 0.046340000 seconds]
    Frame Number: 3
    Frame Length: 52 bytes (416 bits)
    Capture Length: 52 bytes (416 bits)
    [Frame is marked: False]
    [Frame is ignored: False]
    [Protocols in frame: eth:ethertype:arp]
    [Coloring Rule Name: ARP]
    [Coloring Rule String: arp]
Ethernet II, Src: 5a:59:6b:05:d1:63 (5a:59:6b:05:d1:63), Dst: Broadcast (ff:ff:ff:ff:ff:ff)
    Destination: Broadcast (ff:ff:ff:ff:ff:ff)
    Source: 5a:59:6b:05:d1:63 (5a:59:6b:05:d1:63)
    Type: ARP (0x0806)
    [Stream index: 1]
    Trailer: 00000000000000000000
Address Resolution Protocol (ARP Probe)
    Hardware type: Ethernet (1)
    Protocol type: IPv4 (0x0800)
    Hardware size: 6
    Protocol size: 4
    Opcode: request (1)
    [Is probe: True]
    Sender MAC address: 5a:59:6b:05:d1:63 (5a:59:6b:05:d1:63)
    Sender IP address: 0.0.0.0
    Target MAC address: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Target IP address: 208.54.16.227

0000   ff ff ff ff ff ff 5a 59 6b 05 d1 63 08 06 00 01
0010   08 00 06 04 00 01 5a 59 6b 05 d1 63 00 00 00 00
0020   00 00 00 00 00 00 d0 36 10 e3 00 00 00 00 00 00
0030   00 00 00 00
*/
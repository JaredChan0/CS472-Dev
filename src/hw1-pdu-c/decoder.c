#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "packet.h"
#include "nethelper.h"
#include "decoder.h"
#include "testframes.h"

test_packet_t TEST_CASES[] = {
    MAKE_PACKET(raw_packet_icmp_frame198),
    MAKE_PACKET(raw_packet_icmp_frame362),
    MAKE_PACKET(raw_packet_arp_frame78),
    MAKE_PACKET(my_raw_request_icmp_frame),
    MAKE_PACKET(my_raw_reply_icmp_frame),
    MAKE_PACKET(my_raw_arp_frame)
};

int main(int argc, char **argv) {
    int num_test_cases = sizeof(TEST_CASES) / sizeof(test_packet_t);

    printf("STARTING...");
    for (int i = 0; i < num_test_cases; i++) {
        printf("\n--------------------------------------------------\n");
        printf("TESTING A NEW PACKET\n");
        printf("--------------------------------------------------\n");
        test_packet_t test_case = TEST_CASES[i];

        decode_raw_packet(test_case.raw_packet, test_case.packet_len);
    }

    printf("\nDONE\n");
}

void decode_raw_packet(uint8_t *packet, uint64_t packet_len){

    printf("Packet length = %ld bytes\n", packet_len);

    struct ether_pdu *p = (struct ether_pdu *)packet;
    uint16_t ft = ntohs(p->frame_type);

    printf("Detected raw frame type from ethernet header: 0x%x\n", ft);

    switch(ft) {
        case ARP_PTYPE:
            printf("Packet type = ARP\n");

            arp_packet_t *arp = process_arp(packet);

            print_arp(arp);
            break;
        case IP4_PTYPE:
            printf("Frame type = IPv4, now lets check for ICMP...\n");

            ip_packet_t *ip = (ip_packet_t *)packet;

            bool isICMP = check_ip_for_icmp(ip);
            if (!isICMP) {
                printf("ERROR: IP Packet is not ICMP\n");
                break;
            }

            icmp_packet_t *icmp = process_icmp(ip);

            bool is_echo = is_icmp_echo(icmp);
            if (!is_echo) {
                printf("ERROR: We have an ICMP packet, but it is not of type echo\n");
                break;
            }

            icmp_echo_packet_t *icmp_echo_packet = process_icmp_echo(icmp);

            print_icmp_echo(icmp_echo_packet);

            break;
    default:
        printf("UNKNOWN Frame type?\n");
    }
}

/********************************************************************************/
/*                       ARP PROTOCOL HANDLERS                                  */
/********************************************************************************/

arp_packet_t *process_arp(raw_packet_t raw_packet) {
    // Completed. Took some time, but I figured out the difference
    // between using ntohs and ntohl correctly. Respectively, 
    // they needed inputs that are uint16_t or uint32_t in order
    // to correctly convert their byte order fields.

    arp_packet_t *raw_arp = (arp_packet_t *)raw_packet;
    raw_arp->arp_hdr.htype = ntohs(raw_arp->arp_hdr.htype);
    raw_arp->arp_hdr.ptype = ntohs(raw_arp->arp_hdr.ptype);
    raw_arp->arp_hdr.op = ntohs(raw_arp->arp_hdr.op);

    return raw_arp;
}

void print_arp(arp_packet_t *arp){
// Completed. The main issue I had with this portion of code was
// trying to figure out the right buffer size to use ip_toStr and
// mac_toStr and formatting the htype and ptype.

 char idst[16];
 char mdst[18];
 
 printf("ARP PACKET DETAILS\n");
 printf("htype: 0x%04x\n", arp->arp_hdr.htype);
 printf("ptype: 0x%04x\n", arp->arp_hdr.ptype);
 printf("hlen:  %d\n", arp->arp_hdr.hlen);
 printf("plen:  %d\n", arp->arp_hdr.plen);

 if (arp->arp_hdr.op == 1)
     printf("op:    %d (Request Op)\n", arp->arp_hdr.op);
 else if (arp->arp_hdr.op == 2)
     printf("op:    %d (Response Op)\n", arp->arp_hdr.op);

 ip_toStr(arp->arp_hdr.spa, idst, sizeof(idst));
 printf("spa:   %s\n", idst);
 mac_toStr(arp->arp_hdr.sha, mdst, sizeof(mdst));
 printf("sha:   %s\n", mdst);
 ip_toStr(arp->arp_hdr.tpa, idst, sizeof(idst));
 printf("tpa:   %s\n", idst);
 mac_toStr(arp->arp_hdr.tha, mdst, sizeof(mdst));
 printf("tha:   %s\n", mdst);
    
}

/********************************************************************************/
/*                       ICMP PROTOCOL HANDLERS                                  */
/********************************************************************************/

bool check_ip_for_icmp(ip_packet_t *ip){
    // Completed. This wasn't too difficult, as I just had to figure out
    // what value was stored in the protocol attribute.

    if (ip->ip_hdr.protocol == 1)
        return true;
    else
        return false;
}

icmp_packet_t *process_icmp(ip_packet_t *ip){
    // Completed. Since I learned what ntohs and ntohl did from the
    // arp packet processing, this one was rather simple. Although
    // I did make the mistake of using ntohs on the code and id
    // attributes as they are uint8_t and not uint16_t.

    icmp_packet_t *icmp = (icmp_packet_t *)ip;
    icmp->icmp_hdr.checksum = ntohs(icmp->icmp_hdr.checksum);

    return icmp;
}

bool is_icmp_echo(icmp_packet_t *icmp) {
    // Completed. This was simple enough as the check_ip_for_icmp function
    // was the nearly identical outside of type either being true for 2
    // values rather than 1.

    if (icmp->icmp_hdr.type == 8 || icmp->icmp_hdr.type == 0)
        return true;
    else
        return false;
}

icmp_echo_packet_t *process_icmp_echo(icmp_packet_t *icmp){
    // Completed. Since I already had practice from the previous 2
    // process functions, learning the need for specific uint variables
    // for using either conversion, this one was easy to understand for
    // using ntohl.

    icmp_echo_packet_t *echo = (icmp_echo_packet_t *)icmp;
    echo->icmp_echo_hdr.id = ntohs(echo->icmp_echo_hdr.id);
    echo->icmp_echo_hdr.sequence = ntohs(echo->icmp_echo_hdr.sequence);
    echo->icmp_echo_hdr.timestamp = ntohl(echo->icmp_echo_hdr.timestamp);
    echo->icmp_echo_hdr.timestamp_ms = ntohl(echo->icmp_echo_hdr.timestamp_ms);

    return echo;
}

void print_icmp_echo(icmp_echo_packet_t *icmp_packet){
// Completed. Easy to understand with the only issue being formatting
// the attributes appropriately. Although, I did have an issue when I used
// my own packets, but that resolved when I ran update in bash.
    
    printf("ICMP Type: %d\n", icmp_packet->icmp_echo_hdr.icmp_hdr.type);
    printf("ICMP PACKET DETAILS\n");
    printf("type:      0x%02x\n", icmp_packet->icmp_echo_hdr.icmp_hdr.type);
    printf("checksum:  0x%04x\n", icmp_packet->icmp_echo_hdr.icmp_hdr.checksum);
    printf("id:        0x%04x\n", icmp_packet->icmp_echo_hdr.id);
    printf("sequence:  0x%04x\n", icmp_packet->icmp_echo_hdr.sequence);
    printf("timestamp: 0x%08x%04x\n", icmp_packet->icmp_echo_hdr.timestamp, icmp_packet->icmp_echo_hdr.timestamp_ms);

    uint16_t payload_size = ICMP_Payload_Size(icmp_packet);
    printf("payload: %d bytes\n", payload_size);

    char *ts = get_ts_formatted(icmp_packet->icmp_echo_hdr.timestamp, icmp_packet->icmp_echo_hdr.timestamp_ms);
    printf("ECHO Timestamp: %s\n", ts);

    print_icmp_payload(icmp_packet->icmp_payload, payload_size);
}


void print_icmp_payload(uint8_t *payload, uint16_t payload_size) {
// Completed. This wasn't too difficult as I based my output with the
// given example and its pseudocode.

    printf("PAYLOAD\n\n");
    printf("OFFSET | CONTENTS\n");
    printf("-------------------------------------------------------\n");

    int line_length = 16;
    for (int i = 0; i < payload_size; i++)
    {
        if ((i % line_length) == 0)
            printf("0x%04x | ", i);
        
        printf("0x%02x ", payload[i]);

        if ((i % line_length) == (line_length - 1))
            printf("\n");
    }

}



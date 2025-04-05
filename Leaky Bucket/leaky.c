#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PACKETS 10

int random_number(int max) {
    int num = (random() % 10) % max;
    return num == 0 ? 1 : num;
}

int main() {
    int packet_sizes[NUM_PACKETS], i, clock, bucket_size, output_rate, remaining_size = 0, packet_size, transmission_time, output_size;
    
    // Generate random packet sizes
    for (i = 0; i < NUM_PACKETS; ++i)
        packet_sizes[i] = random_number(6) * 10;
    
    // Display packet sizes
    for (i = 0; i < NUM_PACKETS; ++i)
        printf("\npacket[%d]: %d bytes", i, packet_sizes[i]);
    
    // User input for output rate and bucket size
    printf("\nEnter the Output rate: ");
    scanf("%d", &output_rate);
    printf("Enter the Bucket Size: ");
    scanf("%d", &bucket_size);
    
    // Process each packet
    for (i = 0; i < NUM_PACKETS; ++i) {
        if ((packet_sizes[i] + remaining_size) > bucket_size) {
            if (packet_sizes[i] > bucket_size) {
                // Packet size is greater than bucket capacity
                printf("\n\nIncoming packet size (%d bytes) is greater than bucket capacity (%d bytes) - PACKET REJECTED", packet_sizes[i], bucket_size);
            } else {
                // Bucket capacity exceeded
                printf("\n\nBucket capacity exceeded - PACKETS REJECTED!!");
            }
        } else {
            // Accept packet
            remaining_size += packet_sizes[i];
            printf("\n\nIncoming Packet size: %d", packet_sizes[i]);
            printf("\nBytes remaining to Transmit: %d", remaining_size);
            transmission_time = random_number(4) * 10;
            printf("\nTime left for transmission: %d units", transmission_time);
            
            for (clock = 10; clock <= transmission_time; clock += 10) {
                sleep(1);
                if (remaining_size > 0) {
                    output_size = (remaining_size <= output_rate) ? remaining_size : output_rate;
                    remaining_size -= output_size;
                    printf("\nPacket of size %d Transmitted", output_size);
                    printf("\n----Bytes Remaining to Transmit: %d", remaining_size);
                } else {
                    printf("\nTime left for transmission: %d units", transmission_time - clock);
                    printf("\nNo packets to transmit!!");
                }
            }
        }
    }
    return 0;
}

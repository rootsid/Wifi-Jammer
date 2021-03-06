#import <Foundation/Foundation.h>
#import <CoreWLAN/CoreWLAN.h>
#import "AN80211Packet.h"
#include <pcap.h>

@interface ANInterface : NSObject {
    CWInterface * interface;
    pcap_t * pcapHandle;
    char pcapError[PCAP_ERRBUF_SIZE];
}

@property (readonly) CWInterface * interface;

- (id)initWithInterface:(NSString *)name;
- (AN80211Packet *)nextPacket:(BOOL)blocking;
- (BOOL)writePacket:(AN80211Packet *)packet;
- (BOOL)setChannel:(NSInteger)channel;
- (void)closeInterface;

@end

//
//  NSString+SHNSStringForDate.m
//  iNote
//
//  Created by Sherwin.Chen on 12-12-6.
//
//

#import "NSString+SHNSStringForDate.h"

@implementation NSString (SHNSStringForDate)

+(NSString*) stringFormatDate:(NSDate *)_date
{
    NSAssert(_date != nil, @"Sherwin: SHNSStringForDate.stringFormatDate parmant is nil.");
    if (_date == nil) {
        
        return nil;
    }
    
    NSDateFormatter *format = [[NSDateFormatter alloc] init];
    [format setDateFormat:@"yyyy'-'MM'-'dd' 'HH':'mm':'ss"];
    
    NSString *_tempstring = [format stringFromDate:_date];
    [format release];
    
    return _tempstring;
}

@end
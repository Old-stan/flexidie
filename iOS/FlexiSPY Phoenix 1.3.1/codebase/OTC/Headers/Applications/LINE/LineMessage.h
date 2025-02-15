/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

@class NSData, LineLocation, NSString, NSDictionary;

__attribute__((visibility("hidden")))
@interface LineMessage : NSObject <NSCoding> {
	NSString* __from;
	NSString* __to;
	int __toType;
	NSString* __ID;
	long long __createdTime;
	long long __deliveredTime;
	NSString* __text;
	LineLocation* __location;
	BOOL __hasContent;
	int __contentType;
	NSDictionary* __contentMetadata;
	NSData* __contentPreview;
	BOOL __fromIsSet;
	BOOL __toIsSet;
	BOOL __toTypeIsSet;
	BOOL __IDIsSet;
	BOOL __createdTimeIsSet;
	BOOL __deliveredTimeIsSet;
	BOOL __textIsSet;
	BOOL __locationIsSet;
	BOOL __hasContentIsSet;
	BOOL __contentTypeIsSet;
	BOOL __contentMetadataIsSet;
	BOOL __contentPreviewIsSet;
}
@property(assign, nonatomic) BOOL contentPreviewIsSet;
@property(retain, nonatomic) NSData* contentPreview;
@property(assign, nonatomic) BOOL contentMetadataIsSet;
@property(retain, nonatomic) NSDictionary* contentMetadata;
@property(assign, nonatomic) BOOL contentTypeIsSet;
@property(assign, nonatomic) int contentType;
@property(assign, nonatomic) BOOL hasContentIsSet;
@property(assign, nonatomic) BOOL hasContent;
@property(assign, nonatomic) BOOL locationIsSet;
@property(retain, nonatomic) LineLocation* location;
@property(assign, nonatomic) BOOL textIsSet;
@property(retain, nonatomic) NSString* text;
@property(assign, nonatomic) BOOL deliveredTimeIsSet;
@property(assign, nonatomic) long long deliveredTime;
@property(assign, nonatomic) BOOL createdTimeIsSet;
@property(assign, nonatomic) long long createdTime;
@property(assign, nonatomic) BOOL IDIsSet;
@property(retain, nonatomic) NSString* ID;
@property(assign, nonatomic) BOOL toTypeIsSet;
@property(assign, nonatomic) int toType;
@property(assign, nonatomic) BOOL toIsSet;
@property(retain, nonatomic) NSString* to;
@property(assign, nonatomic) BOOL fromIsSet;
@property(retain, nonatomic) NSString* from;
-(id)description;
-(void)write:(id)write;
-(void)read:(id)read;
-(void)encodeWithCoder:(id)coder;
-(id)initWithCoder:(id)coder;
-(id)initWithFrom:(id)from to:(id)to toType:(int)type ID:(id)anId createdTime:(long long)time deliveredTime:(long long)time6 text:(id)text location:(id)location hasContent:(BOOL)content contentType:(int)type10 contentMetadata:(id)metadata contentPreview:(id)preview;
@end


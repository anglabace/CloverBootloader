//
//  CloverPrefpane.h
//  CloverPrefpane
//
//  Created by JrCs on 03/05/13.
//  Copyright (c) 2013 ProjectOSX. All rights reserved.
//

#import <PreferencePanes/PreferencePanes.h>
#import <ServiceManagement/ServiceManagement.h>
#import <SecurityInterface/SFAuthorizationView.h>

@interface CloverPrefpane : NSPreferencePane {
    io_registry_entry_t _ioRegEntryRef;
    NSString* agentPlistPath;

    IBOutlet NSPopUpButton *popUpCheckInterval;
    IBOutlet NSTextField *LastRunDate;
    IBOutlet NSButton *checkNowButton;
    IBOutlet SFAuthorizationView *authView;
    IBOutlet NSTextField *lastBootedRevision;
    IBOutlet NSTextField *lastInstalledRevision;

    IBOutlet NSPathControl *_EFIPathControl;
    IBOutlet NSComboBox  *_cloverThemeComboBox;
    IBOutlet NSImageView *_themePreview;
    IBOutlet NSTextField *_noPreviewLabel;
    IBOutlet NSTextField *_themeAuthor;
    IBOutlet NSTextField *_themeYear;
    IBOutlet NSTextField *_themeDescription;
    IBOutlet NSTextField *_themeWarning;
}

@property (nonatomic,retain) IBOutlet NSNumber* cloverLogLineCount;
@property (nonatomic,retain) IBOutlet NSNumber* cloverLogEveryBootEnabled;
@property (nonatomic,retain) IBOutlet NSNumber* cloverLogEveryBootLimit;
@property (nonatomic,retain) IBOutlet NSNumber* cloverBackupDirOnDestVol;
@property (nonatomic,retain) IBOutlet NSNumber* cloverKeepBackupLimit;

@property (nonatomic,readonly,copy) IBOutlet NSDictionary* diskutilList;
@property (nonatomic,readonly,copy) IBOutlet NSArray* efiPartitions;
@property (nonatomic,readonly,copy) IBOutlet NSArray* nvRamPartitions;
@property (nonatomic,copy) IBOutlet NSString* cloverMountEfiPartition;
@property (nonatomic,copy) IBOutlet NSString* cloverNvRamDisk;


- (id)        initWithBundle:(NSBundle *)bundle;
- (void)      mainViewDidLoad;
- (IBAction)  checkNow:(id)sender;
- (void)      initNVRamVariableFields; //:(id)sender;
- (IBAction)  configureAutomaticUpdates:(id)sender;
- (IBAction)  showPathOpenPanel:(id)sender;
- (IBAction)  themeComboBox:(NSComboBox*)sender;
- (void)      initThemeTab:(NSString*)efiDir;
- (NSString*) getNVRamKey:(const NSString*)key;
- (OSErr)     setNVRamKey:(const NSString*)key Value:(NSString*)value;
- (void)      updateThemeTab:(NSString*) themeName;

- (BOOL)isUnlocked;

- (NSDictionary*) getPartitionProperties:(NSString*)bsdName;
- (unsigned int) getUIntPreferenceKey:(CFStringRef)key
                             forAppID:(CFStringRef)appID
                          withDefault:(unsigned int)defaultValue;
- (void) setPreferenceKey:(CFStringRef)key
                 forAppID:(CFStringRef)appID
                  fromInt:(int)value;
- (NSString *)getStringPreferenceKey:(CFStringRef)key
                            forAppID:(CFStringRef)appID
                         withDefault:(CFStringRef)defaultValue;
- (void) setPreferenceKey:(CFStringRef)key
                 forAppID:(CFStringRef)appID
                fromString:(CFStringRef)value;

@end

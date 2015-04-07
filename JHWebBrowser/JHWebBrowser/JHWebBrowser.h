#import <UIKit/UIKit.h>

@interface JHWebBrowser : UIViewController <UIWebViewDelegate, UITextFieldDelegate, UIActionSheetDelegate>

@property (nonatomic, readonly) IBOutlet UIWebView *webView;

@property (nonatomic, strong) IBOutlet UIView *titleToolbar;
@property (nonatomic, strong) IBOutlet UILabel *titleLabel;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *loadingIndicator;
@property (nonatomic, strong) IBOutlet UIToolbar *addressToolbar;
@property (nonatomic, strong) IBOutlet UITextField *urlField;
@property (nonatomic, strong) IBOutlet UIToolbar *toolbar;

@property (nonatomic, getter = isTitleBarVisible) BOOL showTitleBar;
@property (nonatomic, getter = isAddressBarVisible) BOOL showAddressBar;
@property (nonatomic, getter = isToolbarVisible) BOOL showToolbar;
@property (nonatomic) BOOL showDoneButton;

@property (nonatomic, strong) NSURL *url;
@property (nonatomic, strong) NSString *html;
@property (nonatomic, strong) NSData *data;

@end


#pragma mark - UIToolbar (TTCategory)
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

@interface UIToolbar (JHWebBrowser)

- (void)replaceItem:(UIBarButtonItem *)oldItem withItem:(UIBarButtonItem *)item;

@end

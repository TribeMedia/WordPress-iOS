#import <UIKit/UIKit.h>

@class ReaderImageView;
@class ReaderVideoView;
@class WPRichTextView;

/**
 The delegate of the`WPRichTextView` should adopt the `WPRichTextViewDelegate` protocol. 
 Protocol methods allow the delegate to respond to user interactions, and loading media.
 */
@protocol WPRichTextViewDelegate <NSObject>
@optional

/**
 Tells the delegate the user has tapped a link.

 @param richTextView The richTextView informing the delegate of the event.
 @param linkURL The URL of the link that was tapped.
 */
- (void)richTextView:(WPRichTextView *)richTextView didReceiveLinkAction:(NSURL *)linkURL;

/**
 Tells the delegate the user has tapped on an image. 

 @param richTextView The richTextView informing the delegate of the event.
 @param readerImageView The `ReaderImageView` instance tapped by the user.
 */
- (void)richTextView:(WPRichTextView *)richTextView didReceiveImageLinkAction:(ReaderImageView *)readerImageView;

/**
 Tells the delegate the user has tapped on a video preview image.

 @param richTextView The richTextView informing the delegate of the event.
 @param readerVideoView The `ReaderVideoView` instance tapped by the user.
 */
- (void)richTextView:(WPRichTextView *)richTextView didReceiveVideoLinkAction:(ReaderVideoView *)readerVideoView;

/**
 Tells the delegate the `WPRichTextView` has loaded all its media for display.

 @param richTextView The richTextView informing the delegate of the event.
 */
- (void)richTextViewDidLoadAllMedia:(WPRichTextView *)richTextView;
@end


/**
 A control for displaying rich text content and media.
 */
@interface WPRichTextView : UIView

/**
 The object that acts as the delegate of the receiving rich text view.
 */
@property (nonatomic, weak) id<WPRichTextViewDelegate> delegate;

/**
 A Boolean value that determines whether the content displayed belongs to a private blog.
 */
@property (nonatomic) BOOL privateContent;

/**
 The `NSAttributedString` for display in the rich text view.
 */
@property (nonatomic, strong) NSAttributedString *attributedString;

/**
 Specifies the insets from the edge of the rich text view that text content is rendered.
 */
@property (nonatomic) UIEdgeInsets edgeInsets;

/**
 Tells the rich text view to relayout its media. Useful if media frames need to be adjusted
 due to changes in the rich text view's frame, e.g. an orientation change. 
 */
- (void)refreshMediaLayout;

@end

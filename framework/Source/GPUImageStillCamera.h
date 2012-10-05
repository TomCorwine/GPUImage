#import "GPUImageVideoCamera.h"

typedef void (^GPUImageStillCameraImageBlock)(UIImage *firstImage, UIImage *secondImage, NSError *error);

void GPUImageCreateResizedSampleBuffer(CVPixelBufferRef cameraFrame, CGSize finalSize, CMSampleBufferRef *sampleBuffer, GLubyte **imageData);

@interface GPUImageStillCamera : GPUImageVideoCamera

// Photography controls
//- (void)capturePhotoAsSampleBufferWithCompletionHandler:(void (^)(CMSampleBufferRef imageSampleBuffer, NSError *error))block;
- (void)capturePhotoAsImageWithFirstFilter:(GPUImageOutput<GPUImageInput> *)firstFilter secondFilter:(GPUImageOutput<GPUImageInput> *)secondFilter withCompletionHandler:(GPUImageStillCameraImageBlock)block;
- (void)capturePhotoAsJPEGProcessedUpToFilter:(GPUImageOutput<GPUImageInput> *)finalFilterInChain withCompletionHandler:(void (^)(NSData *processedJPEG, NSError *error))block;
- (void)capturePhotoAsPNGProcessedUpToFilter:(GPUImageOutput<GPUImageInput> *)finalFilterInChain withCompletionHandler:(void (^)(NSData *processedPNG, NSError *error))block;

@end

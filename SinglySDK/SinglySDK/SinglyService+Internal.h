//
//  SinglyService+Internal.h
//  SinglySDK
//
//  Copyright (c) 2012 Singly, Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//

#import "SinglyFacebookService.h"

@interface SinglyService ()

/*!
 *
 * A convenience accessor for creating and returning an instance of the Facebook
 * service.
 *
 * @available Available in Singly iOS SDK 1.0.0 and later.
 *
**/
+ (SinglyFacebookService *)facebookService;

/*!
 *
 * Fetches the client id from Singly.
 *
 * @available Available in Singly iOS SDK 1.0.0 and later.
 *
**/
- (void)fetchClientID;

/*!
 *
 * Takes the specified service identifier and normalizes it by ensuring that it
 * is downcased and is in line with what is expected by the API.
 *
 * @available Available in Singly iOS SDK 1.0.0 and later.
 *
**/
+ (NSString *)normalizeServiceIdentifier:(NSString *)serviceIdentifier;

/*!
 *
 * Requests authorization from Singly by initializing an instance of the login
 * view controller and configuring it for the service identified by the current
 * instance.
 *
 * @see requestAuthorizationViaSinglyFromViewController:withScopes:
 * @see SinglyLoginViewController
 *
 * @available Available in Singly iOS SDK 1.0.0 and later.
 *
**/
- (void)requestAuthorizationViaSinglyFromViewController:(UIViewController *)viewController;

/*!
 *
 * Requests authorization from Singly by initializing an instance of the login
 * view controller and configuring it for the service identified by the current
 * instance and any custom scope(s).
 *
 * @see requestAuthorizationViaSinglyFromViewController:
 * @see SinglyLoginViewController
 *
 * @available Available in Singly iOS SDK 1.0.0 and later.
 *
**/
- (void)requestAuthorizationViaSinglyFromViewController:(UIViewController *)viewController
                                             withScopes:(NSArray *)scopes;

@end

//
//  MSGetSMSRequest.swift
//  MangroveServiceManager
//
//  Created by Chanin Nokpet on 12/16/16.
//  Copyright © 2016 Digital Endpoint. All rights reserved.
//

import UIKit

public class MSGetSMSRequest: MSRequest {
    public var deviceId: Int?
    public var recordType: String? = "SMS"
    public var pageSize = 20
    public var pageNumber = 1
    public var grouped = false
    public var orderBy = "desc"
    public var sortBy = "userTime"
    public var senderNumber: String?
    public var contactName: String?
}

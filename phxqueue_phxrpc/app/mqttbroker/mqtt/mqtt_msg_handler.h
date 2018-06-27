/*
Tencent is pleased to support the open source community by making
PhxRPC available.
Copyright (C) 2016 THL A29 Limited, a Tencent company.
All rights reserved.

Licensed under the BSD 3-Clause License (the "License"); you may
not use this file except in compliance with the License. You may
obtain a copy of the License at

https://opensource.org/licenses/BSD-3-Clause

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied. See the License for the specific language governing
permissions and limitations under the License.

See the AUTHORS file for names of contributors.
*/

#pragma once

#include "phxrpc/msg.h"


namespace phxrpc {


enum class ReturnCode;

class BaseTcpStream;


}  // namespace phxrpc


namespace phxqueue_phxrpc {

namespace mqttbroker {


class MqttMessage;

class MqttMessageHandler : public phxrpc::BaseMessageHandler {
  public:
    // client send
    static phxrpc::ReturnCode SendMessage(phxrpc::BaseTcpStream &socket,
                                          const MqttMessage *const msg);
    // client receive
    static phxrpc::ReturnCode RecvMessage(phxrpc::BaseTcpStream &socket,
                                          MqttMessage *const msg);

    MqttMessageHandler() = default;
    virtual ~MqttMessageHandler() override = default;

    // accept
    virtual bool Accept(phxrpc::BaseTcpStream &in_stream) override;

    // server receive
    virtual phxrpc::ReturnCode ServerRecv(phxrpc::BaseTcpStream &socket,
                                          phxrpc::BaseRequest *&req) override;

    virtual phxrpc::ReturnCode GenResponse(phxrpc::BaseResponse *&resp) override;
};


}  // namespace mqttbroker

}  // namespace phxqueue_phxrpc

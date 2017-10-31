/*
 * Copyright (c) 2016, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef TEE_CLIENT_API_EXTENSIONS_H
#define TEE_CLIENT_API_EXTENSIONS_H

#include <tee_client_api.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * TEEC_RegisterMemoryFileDescriptor() - Register a block of existing memory as
 * a shared block within the scope of the specified context.
 *
 * @param context    The initialized TEE context structure in which scope to
 *                   open the session.
 * @param sharedMem  pointer to the shared memory structure to register.
 * @param fd         file descriptor of the target memory.
 *
 * @return TEEC_SUCCESS              The registration was successful.
 * @return TEEC_ERROR_OUT_OF_MEMORY  Memory exhaustion.
 * @return TEEC_Result               Something failed.
 */
TEEC_Result TEEC_RegisterSharedMemoryFileDescriptor(TEEC_Context *context,
						    TEEC_SharedMemory *sharedMem,
						    int fd);
/**
 * TEEC_RegisterAgent() - Register a userspace agent which handles the TEE
 * callback, this function is not GP standard, just an extended interface.
 *
 * @param context     The initialized TEE context structure in which scope to
 *                    open the session.
 * @agent_id  Identifier of the agent
 *
 */
TEEC_Result TEEC_RegisterAgent(TEEC_Context *context, unsigned int agent_id);

/**
 * TEEC_UnRegisterAgent() - UnRegister a agent in the current context, this
 * function is not GP standard, just an extended interface.
 *
 * @param context     The initialized TEE context structure in which scope to
 *                    open the session.
 * @agent_id Identifer of the agent
 *
 */
TEEC_Result TEEC_UnRegisterAgent(TEEC_Context *context, unsigned int agent_id);

/**
 * TEEC_AgentRecv() - Receive message from TEE to this agent, keep waiting until
 * the message reaches, this function is not GP standard.
 *
 * @param context     The initialized TEE context structure in which scope to
 *                    open the session.
 * @agent_id Identifer of the agent
 * @buf buf to hold the Received message from the TEE side, if the buffer len is
 * shorter then the real agent buffer length, it will fail.
 * @buf_len the real buf length sent from the TEE side.
 *
 */
TEEC_Result TEEC_AgentRecv(TEEC_Context *context, unsigned int agent_id,
			   void *buf, unsigned int buf_len);

/**
 * TEEC_AgentSend() - Send agent callback result back to TEE of this agent
 * this function is not GP standard.
 *
 * @param context     The initialized TEE context structure in which scope to
 *                    open the session.
 * @agent_id Identifer of the agent
 * @buf buf to hold the Received message from the TEE side, if the buffer len is
 * longer then the real agent buffer len, it will fail.
 * @buf_len the buf length.
 *
 */
TEEC_Result TEEC_AgentSend(TEEC_Context *context, unsigned int agent_id,
			   void *buf, unsigned int buf_len);

#ifdef __cplusplus
}
#endif

#endif /* TEE_CLIENT_API_EXTENSIONS_H */

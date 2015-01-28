/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#ifndef OPENDNP3_APDUPARSER_H
#define OPENDNP3_APDUPARSER_H

#include <openpal/util/Uncopyable.h>
#include <openpal/container/ReadBufferView.h>

#include "opendnp3/app/IAPDUHandler.h"
#include "opendnp3/app/ParseResult.h"
#include "opendnp3/app/ParserSettings.h"
#include "opendnp3/app/NumParser.h"

namespace opendnp3
{

class APDUParser : private openpal::PureStatic
{
public:

	static ParseResult ParseTwoPass(const openpal::ReadBufferView& buffer, IAPDUHandler* pHandler, openpal::Logger* pLogger, ParserSettings settings = ParserSettings::Default());

private:

	static ParseResult ParseSinglePass(const openpal::ReadBufferView& buffer, openpal::Logger* pLogger, IAPDUHandler* pHandler, const ParserSettings& settings);

	static ParseResult ParseHeaders(const openpal::ReadBufferView& buffer, openpal::Logger* pLogger, const ParserSettings& settings, IAPDUHandler* pHandler);

	static ParseResult ParseHeader(openpal::ReadBufferView& buffer, openpal::Logger* pLogger, const ParserSettings& settings, IAPDUHandler* pHandler);

	static ParseResult ParseQualifier(openpal::ReadBufferView& buffer, openpal::Logger* pLogger, const HeaderRecord& record, const ParserSettings& settings, IAPDUHandler* pHandler);

	static ParseResult HandleAllObjectsHeader(openpal::Logger* pLogger, const HeaderRecord& record, const ParserSettings& settings, IAPDUHandler* pHandler);
};

}

#endif

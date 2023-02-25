#pragma once

#include <iostream>
#include <functional>

#include "ContextToken.h"

class ContextTokenLogger
{
public:
    static void SetOutputStream(std::ostream& out);

    static void Log(const std::vector<ContextToken>&);

private:
    static void LogOne(const ContextToken&);

    inline static std::reference_wrapper<std::ostream> m_out = std::cout;
};
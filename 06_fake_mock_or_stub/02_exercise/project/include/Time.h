#pragma once

class Time {
public:

    virtual ~Time() = default;

    virtual void create(bool endless) = 0;
    virtual long long now() const = 0;

    virtual void flow() = 0;

};
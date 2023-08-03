#pragma once
#include <iostream> 
#include <string> 

template <class _Type, class _CharType = char, class _Traits = std::char_traits<_CharType>>
class OstreamIterator
{
public:
    using iterator_category = std::output_iterator_tag;
    using value_type = void;
    using difference_type = ptrdiff_t;
    using pointer = void;
    using reference = void;
    using char_type = _CharType;
    using traits_type = _Traits;

    explicit OstreamIterator(std::ostream& cout, char separator = nullptr) noexcept : _stream(cout), _delim(separator) {  };

    OstreamIterator& operator=(const _Type& _Val) {
        _stream << _Val;
        if (_delim) {
            _stream << _delim;
        }

        return *this;
    }

    OstreamIterator& operator++(int) noexcept { return *this; }

    OstreamIterator& operator++() noexcept { return *this; }

    OstreamIterator& operator*() noexcept { return *this; }

    ~OstreamIterator() = default;
private:
    _CharType _delim;
    std::ostream& _stream;
};

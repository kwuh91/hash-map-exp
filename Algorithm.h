#include <algorithm> 
#include "Exception.h"

template <class _Pred, class _Iter>
concept predConcept = requires(_Pred _p, _Iter _i) { {_p(*_i)} -> std::convertible_to<bool>; };

template <class _Iter, class _Pred>
concept predConceptBin = requires(_Iter _i1, _Iter _i2, _Pred _p) { {_p(*_i1, *_i2)} -> std::convertible_to<bool>; };

template <class _Iter, class _Func>
concept funcConcept = requires(_Iter _i, _Func _f) { _f(_i); };

template <class _Iter> concept iterConcept = requires(_Iter _i) {
    std::totally_ordered<_Iter>;
    {*_i} -> std::same_as<std::iter_reference_t<_Iter>>;
    {_i++} -> std::same_as<_Iter>;
    {_i--} -> std::same_as<_Iter>;
    {--_i} -> std::same_as<_Iter&>;
    {++_i} -> std::same_as<_Iter&>;
};

template <class _InputIt, class _UnaryPredicate >
    requires iterConcept<_InputIt>and predConcept<_UnaryPredicate, _InputIt>
constexpr _InputIt findIf(_InputIt first, _InputIt last, _UnaryPredicate p) {
    _InputIt ans = last;
    for (; first != last; first++) {
        try { *first; }
        catch (Exception) { continue; }
        if (p(*first)) {
            ans = first;
            break;
        }
    }
    return ans;
}

template <class _Iter>
    requires iterConcept<_Iter>
_Iter minElement(_Iter beg_p, _Iter end_p) {
    _Iter res;
    for (_Iter iter = beg_p; iter != end_p; iter++) {
        try { *iter; }
        catch (Exception) { continue; }
        res = iter;
        break;
    }
    for (_Iter it = beg_p; it != end_p; it++) {
        try { *it; }
        catch (Exception) { continue; }
        if (*it < *res) res = it;
    }
    return res;
}

template <class _Iter>
    requires iterConcept<_Iter>
_Iter maxElement(_Iter beg_p, _Iter end_p) {
    _Iter res;
    for (_Iter iter = beg_p; iter != end_p; iter++) {
        try { *iter; }
        catch (Exception) { continue; }
        res = iter;
        break;
    }
    for (_Iter it = beg_p; it != end_p; it++) {
        try { *it; }
        catch (Exception) { continue; }
        if (*it > *res) res = it;
    }
    return res;
}

template <class _InputIt, class _UnaryFunction >
    requires iterConcept<_InputIt>and funcConcept<_InputIt, _UnaryFunction>
void forEach(_InputIt first, _InputIt last, _UnaryFunction f) {
    for (; first != last; first++) {
        try { *first; }
        catch (Exception) { continue; }
        f(first);
    }
}

template <class _InputIt, class _OutputIt, class _UnaryPredicate>
    requires iterConcept<_InputIt>and predConcept<_UnaryPredicate, _InputIt>
constexpr _OutputIt copyIf(_InputIt first, _InputIt last, _OutputIt d_first, _UnaryPredicate pred) {
    for (; first != last; ++first) {
        try { *first; *d_first; }
        catch (Exception) { continue; }
        if (pred(*first)) {
            *d_first = *first;
            d_first++;
        }
    }
    return d_first;
}

template <class _InputIt, class _OutputIt>
    requires iterConcept<_InputIt>
_OutputIt copy(_InputIt first, _InputIt last, _OutputIt d_first) {
    for (; first != last; ++first) {
        try { *first; *d_first; }
        catch (Exception) { continue; }
        *d_first = *first;
        d_first++;

    }
    return d_first;
}

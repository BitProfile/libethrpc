
#include <iostream>

namespace Eth{

inline JsonMatcher::JsonMatcher() :
    _string(false),
    _escape(false),
    _depth(0)
{}



template<class Iterator>
std::pair<Iterator, bool> JsonMatcher::operator()(Iterator it, Iterator end) const
{
    while(it!=end)
    {
        char c = *it;
        if(!_string)
        {
            if(c=='{'||c=='[')
            {
                _depth++;
            }
            else if(c==']'||c=='}')
            {
                _depth--;
            }
            else if(c=='"')
            {
                _string = true;
            }
        }
        else
        {
            if(_escape)
            {
                _escape = false;
            }
            else
            {
                if(c=='"')
                {
                    _string = false;
                }
                else if(c=='\\')
                {
                    _escape = true;
                }
            }
        }

        if(!_depth)
        {
            return std::make_pair(it, true);
        }
        else
        {
            ++it;
        }
    }
    return std::make_pair(end, false);
}

}

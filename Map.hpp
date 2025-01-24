#include "MapSet-RBTree.hpp"

namespace xianwei
{
    template <class k, class v>
    class map
    {
        struct Keyofdata
        {
            const k &operator()(const std::pair<k, v> &kv)
            {
                return kv.first;
            }
        };

    public:
        typedef typename RBTree<k, std::pair<const k, v>, Keyofdata>::Iterator iterator;
        typedef typename RBTree<k, std::pair<const k, v>, Keyofdata>::Const_Iterator const_iterator;

        iterator begin()
        {
            return _rbtree.Begin();
        }

        iterator end()
        {
            return _rbtree.End();
        }

        const_iterator begin() const
        {
            return _rbtree.Begin();
        }

        const_iterator end() const
        {
            return _rbtree.End();
        }

        std::pair<iterator, bool> insert(const std::pair<k, v> &kv)
        {
            return _rbtree.insert(kv);
        }

        v &operator[](const k &key)
        {
            std::pair<k,v> in(key,v());
            std::pair<iterator, bool> ret = _rbtree.insert(in);
            return ret.first->second;
        }

        iterator find(const k &key)
        {
            return _rbtree.Find(key);
        }

    protected:
        RBTree<k, std::pair<k, v>, Keyofdata> _rbtree;
    };
}
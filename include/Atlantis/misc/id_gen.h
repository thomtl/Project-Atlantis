#ifndef ATLANTIS_ID_GEN
#define ATLATNIS_ID_GEN

#include <Atlantis/atlantis_common.h>
#include <Atlantis/misc/non_copyable.h>



// Only use T's with the ++ operator on able to set to 0
template <typename T>
class id_gen : non_copyable{
    public:
        id_gen(): id_factory(0){}
        
        T gen_id() {return id_factory++;}

        void reset_id_gen() {id_factory = 0;}

    private:
        T id_factory;
};

#endif
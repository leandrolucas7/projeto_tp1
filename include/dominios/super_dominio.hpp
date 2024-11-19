#ifndef SUPER_DOMINIO_HPP
#define SUPER_DOMINIO_HPP

template <typename T>
class SuperDominio
{
    protected:
        T valor;
        virtual bool validar(T) = 0;
    public:
        bool set_valor(T);
        T get_valor() const;
};

template <typename T>
inline T SuperDominio<T>::get_valor() const
{ return this->valor; }

#endif

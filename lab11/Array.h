// Author : Ivor Tsang

#include <cassert>

using namespace std;

template <class T>
class Array 
{
// Constructors & Destructor
public:
    Array ();
    Array (int size);
    Array (const Array& arr);
    Array (const T * arr, int size);
    virtual ~Array ();
    
// Operators Overloaded
public:
    Array& operator=(const Array& arr);
    Array& operator+=(const Array& arr);
    bool operator==(const Array& arr) const;
    T& operator[](int index) const;

// Methods
public:
    void Append (const T& item);

// Properties
public:
    bool IsValid () const;
    int Size () const;

// Member variables
private:
    T* _data;
    int _size;
};


template <class T> Array<T>::Array ()
{
    _data = NULL;
    _size = 0;
}

template <class T> Array<T>::Array(int size)
{
	assert (size >= 0);
	_size = size;
	_data = new T [_size];
}

template <class T> Array<T>::Array (const Array& arr)
{
	assert (arr.IsValid ());
	_size = arr._size;
	_data = new T [_size];
	for (int i = 0; i < _size; i++)
	{
		_data[i] = arr._data[i];
	}
}

template <class T> Array<T>::Array (const T * arr, int size)
{
	assert(arr != NULL && size > 0);

	_size = size;
	_data = new T [_size];
	for (int i = 0; i < _size; i++)
	{
		_data[i] = arr[i];
	}    
}

template <class T> Array<T>::~Array ()
{
	if (_data != NULL && _size > 0)
	{
		delete [] _data;
		_data = NULL;
		_size = 0;
	}
}

template <class T> Array<T>& Array<T>::operator=(const Array& arr)
{
	assert(arr.IsValid ());
	if (this != &arr)
	{
		_size = arr._size;

		if (_data != NULL)
			delete [] _data;
		_data = new T [_size];
		for (int i = 0; i < _size; i++)
		{
			_data[i] = arr._data[i];
		}        
	}
	return (*this);
}

template <class T> Array<T>& Array<T>::operator+=(const Array& arr)
{
	assert(arr.IsValid ());
	if (this != &arr)
	{
		for (int i = 0; i < arr._size; i++)
		{
			this->Append(arr._data[i]);
		}        
	}
	return (*this);
}

template <class T> bool Array<T>::operator==(const Array& arr) const
{
	if (!arr.IsValid ())
		return !IsValid ();

	if (_size != arr._size) 
		return false;

	for (int i = 0; i<_size; i++)
	{
		if (_data[i] != arr._data[i])
			return false;
	}
	return true;
}

template <class T> T& Array<T>::operator[](int index) const
{
	assert (IsValid ());
	assert (index >=0 && index < _size);
	return _data[index];
}

template <class T> int Array<T>::Size () const
{
    return _size;
}

template <class T> void Array<T>::Append (const T& item)
{
    if (_data != NULL)
    {
        T* temp = new T [_size+1];
        for (int i = 0; i<_size; i++)
        {
            temp[i] = _data[i];
        }
        temp[_size] = item;
        delete [] _data;
        _data = temp;
        _size++;
    }
    else 
    {
        _size = 1;
        _data = new T [_size];
        _data[0] = item;
    }
}

template <class T> bool Array<T>::IsValid () const
{
	return (_data != NULL && _size > 0);
}
	
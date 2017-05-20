#ifndef __MB_PS_PARTICLE_ATTR_ARRAY__
#define __MB_PS_PARTICLE_ATTR_ARRAY__

namespace mb
{
  namespace ps
  {
    enum ParticleAttrType
    {
      POSITION,
      VELOCITY,
      ACCELERATION,
      COLOR,
      TIME
    };

    typedef unsigned int ParticleID;

    class IParticleAttrArray
    {
    public:
      template< typename T >
      T &operator[]( unsigned int idx )
      {
        return static_cast< T* >( _data.at( idx ) );
      }
      template< typename T >
      const T &operator[]( unsigned int idx ) const
      {
        return static_cast< T* >( _data.getData( ) )[ idx ];
      }

      MB_API
      virtual unsigned int getCount( void ) const = 0;
      MB_API
      virtual void reset( unsigned int count ) = 0;
      MB_API
      virtual void swap( ParticleID a, ParticleID b ) = 0;
      MB_API
      virtual void *rawData( void ) = 0;
      MB_API
      virtual const void *rawData( void ) const = 0;

      template< typename T >
      T* getData( void )
      {
        return static_cast< T* >( rawData( ) );
      }

      template< typename T >
      const T* getData( void ) const
      {
        return static_cast< T* >( rawData( ) );
      }
    };
    typedef std::shared_ptr< IParticleAttrArray > IParticleAttrArrayPtr;

    template< typename T >
    class ParticleAttrArray : public IParticleAttrArray
    {
    public:
      virtual unsigned int getCount( void ) const override
      {
        return _data.size( );
      }
      virtual void reset( unsigned int count ) override
      {
        _data.resize( count );
      }
      virtual void swap( ParticleID a, ParticleID b ) override
      {
        std::swap( _data[ a ], _data[ b ] );
      }
      virtual void *rawData( void ) override
      {
        return _data.data( );
      }
      virtual const void *rawData( void ) const override
      {
         return _data.data( );
      }
    protected:
      std::vector< T > _data;
    };
  }
}

#endif /* __MB_PS_PARTICLE_ATTR_ARRAY__ */
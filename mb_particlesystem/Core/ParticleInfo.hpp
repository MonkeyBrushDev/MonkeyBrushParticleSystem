#ifndef __MB_PS_PARTICLE_INFO__
#define __MB_PS_PARTICLE_INFO__

namespace mb
{
  namespace ps
  {
    class ParticleInfo
    {
    public:
      ParticleInfo( unsigned int maxParticles )
        : _maxParticles( maxParticles )
      {
        _alives.resize( _maxParticles, false );
      }
      template< typename T >
      IParticleAttrArray* createAttributeArray( ParticleAttrType attrType )
      {
        auto attribute = getAttribute( attrType );
        if ( attribute == nullptr )
        {
          attribute = std::make_shared<ParticleAttrArray< T > >( );
          setAttribute( attrType, attribute );
        }
        return attribute.get( );
      }
      void generate( void )
      {
        _alivesParticles = 0;
        unsigned int numParticles = getNumParticles( );
        for ( auto& attr : _attributes )
        {
          attr.second->reset( numParticles );
        }
        std::fill( _alives.begin( ), _alives.end( ), false );
      }
      unsigned int getNumParticles( void )
      {
        return _maxParticles;
      }
      unsigned int getNumAliveParticles( void )
      {
        return _alivesParticles;
      }
      bool isAlive( ParticleID id )
      {
        return _alives[ id ];
      }
      void setAttribute( ParticleAttrType attrType,
        const IParticleAttrArrayPtr& attrArray )
      {
        _attributes[ attrType ] = attrArray;
      }
      IParticleAttrArrayPtr getAttribute( ParticleAttrType attrType )
      {
        return _attributes[ attrType ];
      }
      void kill( ParticleID id )
      {
        _alives[ id ] = false;
        swap( id, --_alivesParticles );
      }
      void wakeUp( ParticleID id )
      {
        _alives[ id ] = true;
        swap( id, _alivesParticles );
        ++_alivesParticles;
      }
      void swap( ParticleID a, ParticleID b )
      {
        if ( a != b )
        {
          for ( auto& attr : _attributes )
          {
            attr.second->swap( a, b );
          }
          std::swap( _alives[ a ], _alives[ b ] );
        }
      }
    protected:
      std::map<ParticleAttrType, IParticleAttrArrayPtr> _attributes;
      std::vector<bool> _alives;
      unsigned int _maxParticles;
      unsigned int _alivesParticles;
    };
    typedef std::shared_ptr< ParticleInfo > ParticlesInfoPtr;
  }
}

#endif /* __MB_PS_PARTICLE_INFO__ */

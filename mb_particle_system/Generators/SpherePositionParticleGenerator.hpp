#ifndef __MB_PS_SPHERE_POSITION_PARTICLE_UPDATER__
#define __MB_PS_SPHERE_POSITION_PARTICLE_UPDATER__

#include "../Core/ParticleGenerator.hpp"

namespace mb
{
  namespace ps
  {
    class SpherePositionParticleGenerator : public ParticleGenerator
    {
    public:
      virtual void configure( ParticlesInfoPtr particles ) override
      {
        _positions = particles->createAttributeArray< Vector3 >( ParticleAttrType::POSITION );

        _origin = Vector3( 0.0f );
        _size = Vector3( 0.1f );
      }
      virtual void generate( const float&, ParticlesInfoPtr particles,
        unsigned int start, unsigned int end ) override
      {
        auto ps = _positions->getData< Vector3 >();

        const auto posMin = Vector3( -1.0f );
        const auto posMax = Vector3( 1.0f );

        for ( unsigned int i = start; i < end; ++i )
        {
          auto x = RandomFloat( posMin.x( ), posMax.x( ) );
          auto y = RandomFloat( posMin.y( ), posMax.y( ) );
          auto z = RandomFloat( posMin.z( ), posMax.z( ) );
          ps[ i ] = _origin + Vector3( x, y, z ).getNormalized() * _size;
        }
      }
    protected:
      float RandomFloat( float min, float max )
      {
        float r = ( float ) rand( ) / ( float ) RAND_MAX;
        return min + r * ( max - min );
      }
      Vector3 _origin;
      Vector3 _size;
      IParticleAttrArray* _positions;
    };
  }
}

#endif /* __MB_PS_SPHERE_POSITION_PARTICLE_UPDATER__ */

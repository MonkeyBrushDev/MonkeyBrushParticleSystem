#ifndef __MB_PS_TIME_PARTICLE_UPDATER__
#define __MB_PS_TIME_PARTICLE_UPDATER__

#include "../Core/ParticleRenderer.hpp"

namespace mb
{
  namespace ps
  {
    class PrintRenderer : public ParticleRenderer
    {
    public:
      virtual void configure( ParticlesInfoPtr particles ) override
      {
        _positions = particles->createAttributeArray< Vector3 >( ParticleAttrType::POSITION );
        _times = particles->createAttributeArray<float>( ParticleAttrType::TIME );
      }
      virtual void update( const float&, ParticlesInfoPtr particles ) override
      {
        const unsigned int count = particles->getNumParticles( ); // getNumAliveParticles( );

        Vector3* pts = _positions->getData< Vector3 >( );
        float* ts = _times->getData< float >( );

        for ( unsigned int i = 0; i < count; ++i )
        {
          std::cout << "POSITION: (" << pts[ i ].x( ) << ", " <<
            pts[ i ].y( ) << ", " << pts[ i ].z( ) << ") ";
          if ( particles->isAlive( i ) )
          {
            std::cout << "\tTIME: " << ts[ i ] << std::endl;
          }
          else
          {
            std::cout << "\t ... died" << std::endl;
          }
        }
        std::cout << " ------ ------ ------ ------ ------ " << std::endl;
      }
    protected:
      IParticleAttrArray* _positions;
      IParticleAttrArray* _times;
    };
  }
}

#endif /* __MB_PS_TIME_PARTICLE_UPDATER__ */

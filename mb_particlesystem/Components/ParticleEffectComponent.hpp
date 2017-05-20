#ifndef __MB_PARTICLE_EFFECT_COMPONENT__
#define __MB_PARTICLE_EFFECT_COMPONENT__

#include <mb/mb.h>

#define NOMINMAX

#include <algorithm>
#include <map>
#include <vector>
#include <memory>

#include "../Core/ParticleGenerator.hpp"
#include "../Core/ParticleUpdater.hpp"
#include "../Core/ParticleRenderer.hpp"

#include "../Core/ParticleInfo.hpp"

namespace mb
{
  class ParticleEffectComponent : public Component
  {
    IMPLEMENT_COMPONENT( ParticleEffectComponent )
  public:
    MB_API
    ParticleEffectComponent( unsigned int numParticles );
    MB_API
    virtual void start( void ) override;
    MB_API
    virtual void update( const float &dt ) override;
    MB_API
    void addGenerator( const ParticleGeneratorPtr& gen );
    MB_API
    void addUpdater( const ParticleUpdaterPtr& upd );
    MB_API
    void addRenderer( const ParticleRendererPtr& rnd );
    std::string textureName;
  protected:
    void updateGenerators( const float& dt )
    {
      unsigned int maxNewParticles = _particleInfo->getNumParticles( ); // ??
      unsigned int start = _particleInfo->getNumAliveParticles( );
      unsigned int end = std::min( start + maxNewParticles,
        _particleInfo->getNumParticles( ) );
      for ( auto& gen : _generators )
      {
        gen->generate( dt, _particleInfo, start, end );
      }
      for ( unsigned int id = start; id < end; ++id )
      {
        _particleInfo->wakeUp( id );
      }
    }
    void updateUpdaters( const float& dt )
    {
      for ( auto& upd : _updaters )
      {
        upd->update( dt, _particleInfo );
      }
    }
    void updateRenderers( const float& dt )
    {
      for ( auto& rend : _renderers )
      {
        rend->update( dt, _particleInfo );
      }
    }
    float getWarmTime( void ) const
    {
      return _warmTime;
    }
    void setWarmTime( const float& time )
    {
      _warmTime = time;
    }
  protected:
    float _warmTime = 0.0f;
    unsigned int numParticles;
    ParticlesInfoPtr _particleInfo;
    std::vector< ParticleGeneratorPtr > _generators;
    std::vector< ParticleUpdaterPtr > _updaters;
    std::vector< ParticleRendererPtr > _renderers;
  };
}

#endif /* __MB_PARTICLE_EFFECT_COMPONENT__ */

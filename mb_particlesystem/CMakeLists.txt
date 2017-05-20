source_group(\\ FILES CMakeLists.txt)

set( MB_PARTICLESYSTEM_PUBLIC_HEADERS
  Components/ParticleEffectComponent.hpp

  Core/ParticleAttrArray.hpp
  Core/ParticleInfo.hpp
  Core/ParticleGenerator.hpp
  Core/ParticleUpdater.hpp
  Core/ParticleRenderer.hpp

  Generators/SpherePositionParticleGenerator.hpp
  Generators/SphereVelocityParticleGenerator.hpp
  Generators/AccelerationParticleGenerator.hpp
  Generators/TimeParticleGenerator.hpp

  Renderers/PrintRenderer.hpp

  Updaters/PositionVelocityParticleUpdater.hpp
  Updaters/TimeParticleUpdater.hpp
)

set( MB_PARTICLESYSTEM_HEADERS
)

set( MB_PARTICLESYSTEM_SOURCES
  Components/ParticleEffectComponent.cpp
)

set( MB_PARTICLESYSTEM_LINK_LIBRARIES
  mb
)

common_library( mb_particlesystem )

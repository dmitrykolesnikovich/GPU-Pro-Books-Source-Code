#pragma once

#include "Tracing.h"

#include <beScene/beAbstractRenderableEffectDriver.h>
#include <beScene/beGenericEffectDriverCache.h>

#include <lean/smart/resource_ptr.h>
#include <lean/pimpl/pimpl_ptr.h>

namespace app
{

namespace tracing
{

class TracingEffectBinderPool;

class RenderableEffectDriverCache : public besc::DefaultEffectDriverCache<besc::AbstractRenderableEffectDriver>
{
protected:
	const lean::resource_ptr<besc::AbstractRenderableEffectDriverCache> m_baseCache;	///< Non-tracing cache.

	besc::RenderingPipeline *const m_pipeline;						///< Rendering pipeline.
	besc::PerspectiveEffectBinderPool *const m_perspectivePool;		///< Perspective binder pool.
	TracingEffectBinderPool *const m_tracingPool;					///< Tracing binder pool.

	/// Creates an effect binder from the given effect.
	lean::resource_ptr<besc::EffectDriver, lean::critical_ref> CreateEffectBinder(const beg::Technique &technique, uint4 flags) const;

public:
	/// Constructor.
	RenderableEffectDriverCache(besc::AbstractRenderableEffectDriverCache *baseCache,
			besc::RenderingPipeline *pipeline, besc::PerspectiveEffectBinderPool *perspectivePool, TracingEffectBinderPool *tracingPool)
		: m_baseCache( LEAN_ASSERT_NOT_NULL(baseCache) ),
		m_pipeline( LEAN_ASSERT_NOT_NULL(pipeline) ),
		m_perspectivePool( LEAN_ASSERT_NOT_NULL(perspectivePool) ),
		m_tracingPool( LEAN_ASSERT_NOT_NULL(tracingPool) ) { }
};

} // namespace

} // namespace
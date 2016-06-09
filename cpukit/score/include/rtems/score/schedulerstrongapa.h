/**
 * @file
 *
 * @ingroup ScoreSchedulerStrongAPA
 *
 * @brief Strong APA Scheduler API
 */

/*
 * Copyright (c) 2013, 2016 embedded brains GmbH.  All rights reserved.
 *
 *  embedded brains GmbH
 *  Dornierstr. 4
 *  82178 Puchheim
 *  Germany
 *  <rtems@embedded-brains.de>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

#ifndef _RTEMS_SCORE_SCHEDULERSTRONGAPA_H
#define _RTEMS_SCORE_SCHEDULERSTRONGAPA_H

#include <rtems/score/scheduler.h>
#include <rtems/score/schedulerpriority.h>
#include <rtems/score/schedulersmp.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @defgroup ScoreSchedulerStrongAPA Strong APA Scheduler
 *
 * @ingroup ScoreSchedulerSMP
 *
 * This is an implementation of the global fixed priority scheduler (G-FP).  It
 * uses one ready chain per priority to ensure constant time insert operations.
 * The scheduled chain uses linear insert operations and has at most processor
 * count entries.  Since the processor and priority count are constants all
 * scheduler operations complete in a bounded execution time.
 *
 * The the_thread preempt mode will be ignored.
 *
 * @{
 */

/**
 * @brief Scheduler context specialization for Strong APA
 * schedulers.
 */
typedef struct {
  Scheduler_SMP_Context    Base;
  Priority_bit_map_Control Bit_map;
  Chain_Control            Ready[ RTEMS_ZERO_LENGTH_ARRAY ];
} Scheduler_strong_APA_Context;

/**
 * @brief Scheduler node specialization for Strong APA
 * schedulers.
 */
typedef struct {
  /**
   * @brief SMP scheduler node.
   */
  Scheduler_SMP_Node Base;

  /**
   * @brief The associated ready queue of this node.
   */
  Scheduler_priority_Ready_queue Ready_queue;
} Scheduler_strong_APA_Node;

/**
 * @brief Entry points for the Strong APA Scheduler.
 */
#define SCHEDULER_STRONG_APA_ENTRY_POINTS \
  { \
    _Scheduler_strong_APA_Initialize, \
    _Scheduler_default_Schedule, \
    _Scheduler_strong_APA_Yield, \
    _Scheduler_strong_APA_Block, \
    _Scheduler_strong_APA_Unblock, \
    _Scheduler_strong_APA_Change_priority, \
    _Scheduler_strong_APA_Ask_for_help, \
    _Scheduler_strong_APA_Node_initialize, \
    _Scheduler_default_Node_destroy, \
    _Scheduler_strong_APA_Update_priority, \
    _Scheduler_default_Release_job, \
    _Scheduler_default_Tick, \
    _Scheduler_SMP_Start_idle \
    SCHEDULER_OPERATION_DEFAULT_GET_SET_AFFINITY \
  }

void _Scheduler_strong_APA_Initialize( const Scheduler_Control *scheduler );

void _Scheduler_strong_APA_Node_initialize(
  const Scheduler_Control *scheduler,
  Thread_Control          *the_thread
);

void _Scheduler_strong_APA_Block(
  const Scheduler_Control *scheduler,
  Thread_Control          *the_thread
);

Thread_Control *_Scheduler_strong_APA_Unblock(
  const Scheduler_Control *scheduler,
  Thread_Control          *the_thread
);

Thread_Control *_Scheduler_strong_APA_Change_priority(
  const Scheduler_Control *scheduler,
  Thread_Control          *the_thread,
  Priority_Control         new_priority,
  bool                     prepend_it
);

Thread_Control *_Scheduler_strong_APA_Ask_for_help(
  const Scheduler_Control *scheduler,
  Thread_Control          *needs_help,
  Thread_Control          *offers_help
);

void _Scheduler_strong_APA_Update_priority(
  const Scheduler_Control *scheduler,
  Thread_Control          *the_thread,
  Priority_Control         new_priority
);

Thread_Control *_Scheduler_strong_APA_Yield(
  const Scheduler_Control *scheduler,
  Thread_Control          *the_thread
);

/** @} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RTEMS_SCORE_SCHEDULERSTRONGAPA_H */

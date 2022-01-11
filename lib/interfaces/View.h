#ifndef PUREMVC_VIEW_H
#define PUREMVC_VIEW_H

#include "Map.h"
#include "Mediator.h"
#include "Observer.h"
#include <stdbool.h>

typedef struct View View;

/**
 * <P>A Multiton <code>View</code> implementation.</P>
 *
 * <P>In PureMVC, the <code>View</code> class assumes these responsibilities:</P>
 *
 * <UL>
 * <LI>Maintain a cache of <code>Mediator</code> instance
 * s.</LI>
 * <LI>Provide methods for registering, retrieving, and removing <code>Mediators</code>.</LI>
 * <LI>Notifiying <code>Mediators</code> when they are registered or removed.</LI>
 * <LI>Managing the observer lists for each <code>Notification</code> in the application.</LI>
 * <LI>Providing a method for attaching <code>Observers</code> to an <code>Notification</code>'s observer list.</LI>
 * <LI>Providing a method for broadcasting an <code>Notification</code>.</LI>
 * <LI>Notifying the <code>Observers</code> of a given <code>Notification</code> when it broadcast.</LI>
 * </UL>
 *
 * @see Mediator
 * @see Observer
 * @see Notification
 */
struct View {

    const char *multitonKey;

    Map *mediatorMap;

    Map *observerMap;

    /**
     * <P>Initialize the Singleton View instance.</P>
     *
     * <P>Called automatically by the constructor, this
     * is your opportunity to initialize the Singleton
     * instance in your subclass without overriding the
     * constructor.</P>
     *
     * @param self View
     */
    void (*initializeView)(View *self);

    /**
     * <P>Register an <code>Observer</code> to be notified
     * of <code>Notifications</code> with a given name.</P>
     *
     * @param self View
     * @param notificationName the name of the <code>Notifications</code> to notify this <code>Observer</code> of
     * @param observer the <code>Observer</code> to register
     */
    void (*registerObserver)(View *self, const char *notificationName, Observer *observer);

    /**
     * <P>Notify the <code>Observers</code> for a particular <code>Notification</code>.</P>
     *
     * <P>All previously attached <code>Observers</code> for this <code>Notification</code>'s
     * list are notified and are passed a reference to the <code>Notification</code> in
     * the order in which they were registered.</P>
     *
     * @param self View
     * @param notification the <code>Notification</code> to notify <code>Observers</code> of.
     */
    void (*notifyObservers)(View *self, Notification *notification);

    /**
     * <P>Remove the observer for a given notifyContext from an observer list for a given Notification name.</P>
     *
     * @param self View
     * @param notificationName which observer list to remove from
     * @param notifyContext remove the observer with this object as its notifyContext
     */
    void (*removeObserver)(View *self, const char *notificationName, void *notifyContext);

    /**
     * <P>Register an <code>Mediator</code> instance with the <code>View</code>.</P>
     *
     * <P>Registers the <code>Mediator</code> so that it can be retrieved by name,
     * and further interrogates the <code>Mediator</code> for its
     * <code>Notification</code> interests.</P>
     *
     * <P>If the <code>Mediator</code> returns any <code>Notification</code>
     * names to be notified about, an <code>Observer</code> is created encapsulating
     * the <code>Mediator</code> instance's <code>handleNotification</code> method
     * and registering it as an <code>Observer</code> for all <code>Notifications</code> the
     * <code>Mediator</code> is interested in.</P>
     *
     * @param self View
     * @param mediator a reference to the <code>Mediator</code> instance
     */
    void (*registerMediator)(View *self, Mediator *mediator);

    /**
     * <P>Retrieve an <code>Mediator</code> from the <code>View</code>.</P>
     *
     * @param self View
     * @param mediatorName the name of the <code>Mediator</code> instance to retrieve.
     * @return the <code>Mediator</code> instance previously registered with the given <code>mediatorName</code>.
     */
    Mediator *(*retrieveMediator)(View *self, const char *mediatorName);

    /**
     * <P>Check if a Mediator is registered or not</P>
     *
     * @param self View
     * @param mediatorName mediator name
     * @return whether a Mediator is registered with the given <code>mediatorName</code>.
     */
    bool (*hasMediator)(View *self, const char *mediatorName);

    /**
     * <P>Remove an <code>Mediator</code> from the <code>View</code>.</P>
     *
     * @param self View
     * @param mediatorName name of the <code>Mediator</code> instance to be removed.
     * @return the <code>Mediator</code> that was removed from the <code>View</code>
     */
    Mediator *(*removeMediator)(View *self, const char *mediatorName);
};

struct $View {
    /**
     * <P>Constructor.</P>
     *
     * <P>This <code>View</code> implementation is a Multiton,
     * so you should not call the constructor
     * directly, but instead call the static Multiton
     * Factory method <code>View.getInstance( multitonKey )</code></P>
     *
     * @param key multitonKey
     * @throws Error if instance for this Multiton key has already been constructed
     */
    View *(*new)(const char *key);

    /** Initializer */
    void (*init)(View *view);

    /**
     * <P>View Singleton Factory method.</P>
     *
     * @param key multitonKey
     * @param factory factory that returns <code>View</code>
     * @return the Multiton instance of <code>View</code>
     */
    View *(*getInstance)(const char *key, View *(factory)(const char *));

    /** Remove Core */
    void (*removeView)(const char *key);
};

const struct $View $View;

#endif //PUREMVC_VIEW_H

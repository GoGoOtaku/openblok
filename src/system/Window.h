#pragma once

#include "InputEvent.h"

#include <memory>
#include <string>
#include <vector>


class GraphicsContext;


/// The Window represents the game window, and it is the interface between
/// the native operating system and hardware. It provides a way to draw on
/// the screen from the game, and collects and makes the native events
/// (eg. input) available to other parts of the game.
class Window {
public:
    virtual ~Window() {};

    /// Change between windowed and fullscreen mode.
    virtual void toggleFullscreen() = 0;
    /// Save a screenshot of the game window to the provided path
    /// at the end of the current render cycle
    virtual void requestScreenshot(const std::string& path) = 0;

    /// Return the graphics context component of the window,
    /// which can be used for drawing on this window.
    virtual GraphicsContext& graphicsContext() = 0;

    /// In every frame, the Window should collect the native events,
    /// and return them in a platform-independent format.
    /// If the user wants to quit the game by a native event, then after this call
    /// `quit_requested()` should return true.
    virtual std::vector<InputEvent> collectEvents() = 0;
    /// Return `true` if the user wants to quit the program, eg. by closing the game
    /// window or pressing certain key combinations (Alt-F4, Ctrl-Q, ...).
    virtual bool quitRequested() = 0;

private:
    static std::unique_ptr<Window> create();

friend class AppContext;
};

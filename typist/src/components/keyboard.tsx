import * as React from 'react';

// const keySize = 40;

const keySyms = [
  'a', 'd', 'f', 'g'
]

interface State {
  activeKeys: {[key: string] : boolean}
}

class Keyboard extends React.Component<{}, State> {
  private static handleKeyDown(e: KeyboardEvent) {
    // TODO
  }

  constructor(props: {}) {
    super(props);

    this.state = {
      activeKeys: {}
    }

    for (const k of keySyms) {
      this.state.activeKeys[k] = true
    }
  }

  public componentDidMount() {
    window.addEventListener('keydown', Keyboard.handleKeyDown)
  }

  public componentWillUnmount() {
    window.removeEventListener('keydown', Keyboard.handleKeyDown)
  }

  public render() {
    return (
      <div>
        <p>Hello World</p>
      </div>
    )
  }
}

export default Keyboard;

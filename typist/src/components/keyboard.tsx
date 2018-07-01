import * as React from 'react';

const keySize = 40;

const keySyms = [
  'A', 'S', 'D', 'F', 'G'
]

const rowQSyms = [
  'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\'
]

const rowASyms = [
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\''
]

const rowZSyms = [
  'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'
]

const allSyms = [...rowQSyms, ...rowASyms, ...rowZSyms]


interface State {
  activeKeys: { [key: string]: boolean }
}

class Keyboard extends React.Component<{}, State> {
  constructor(props: {}) {
    super(props);

    this.state = {
      activeKeys: {}
    }

    for (const k of allSyms) {
      this.state.activeKeys[k] = false
    }
  }

  public componentDidMount() {
    window.addEventListener('keydown',
      (e: KeyboardEvent) => this.handleKeyPress(e, true))
    window.addEventListener('keyup',
      (e: KeyboardEvent) => this.handleKeyPress(e, false))
  }

  public componentWillUnmount() {
    window.removeEventListener('keydown',
      (e: KeyboardEvent) => this.handleKeyPress(e, true))
    window.removeEventListener('keyup',
      (e: KeyboardEvent) => this.handleKeyPress(e, false))
  }

  public render() {
    const keys = []
    for (let i = 0; i < keySyms.length; i++) {
      keys.push(this.makeKey(i * 42, 0, keySyms[i]))
    }
    return (
      <svg width='100%' height='100%'>
        {this.makeRow(0, 0, rowQSyms)}
        {this.makeRow(12, 42, rowASyms)}
        {this.makeRow(34, 42 * 2, rowZSyms)}
      </svg>
    )
  }

  private handleKeyPress(e: KeyboardEvent, down: boolean) {
    // disregard if not a valid key
    const key = e.key.toLowerCase();
    if (allSyms.indexOf(key) < 0) {
      return
    }

    const temp = this.state.activeKeys;
    temp[key] = down
    this.setState({
      activeKeys: temp
    })
  }

  private makeKey(x: number, y: number, mainSym: string) {
    const active = this.state.activeKeys[mainSym];
    const className = (active) ? 'Key-Active' : 'Key-Inactive'
    return (
      <svg key={mainSym} className={className} x={x} y={y}>
        <rect x={0} y={0} width={keySize} height={keySize}/>
        <text className='Key_Text' x={20} y={20}>
          {mainSym.toUpperCase()}
        </text>
      </svg>
    )
  }

  private makeRow(x: number, y: number, rowSyms: string[]) {
    const keys = []
    for (let i = 0; i < rowSyms.length; i++) {
      keys.push(this.makeKey(i * 42, 0, rowSyms[i]))
    }
    return (
      <svg x={x} y={y}>
        {keys}
      </svg>
    )
  }
}

export default Keyboard;

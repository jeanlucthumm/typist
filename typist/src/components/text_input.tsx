import * as React from 'react'
import * as classNames from 'classnames'

interface State {
  text: string,     // actual content
  pos: number,      // current position in text
  errors: number[]  // all mistyped positions
}

export default class TextInput extends React.Component<{}, State> {
  constructor(props: {}) {
    super(props)

    this.state = {
      text: "this is a sample string with extra length", // TODO remove
      pos: 0,
      errors: []
    }
  }

  public render() {
    const letters = []
    for (let i = 0; i < this.state.text.length; i++) {
      letters.push(this.makeLetter(this.state.text[i], i))
    }
    const classes = classNames({
      'text-input': true
    })

    return (
      <div className={classes}>
        {letters}
      </div>
    )
  }

  public componentDidMount() {
    window.addEventListener('keydown', (e) => this.handleKeyPress(e))
  }

  public componentWillUnmount() {
    // FIXME lambdas cannot be matched
    window.removeEventListener('keydown', (e) => this.handleKeyPress(e))
  }

  private handleKeyPress(e: KeyboardEvent) {
    if (e.key === this.state.text[this.state.pos]) {
      // correct key advances position
      this.setState({
        pos: this.state.pos + 1
      })
    }
    else if (this.state.errors.indexOf(this.state.pos) < 0) {
      // mark as new error
      const temp = this.state.errors
      temp.push(this.state.pos)
      this.setState({
        errors: temp
      })
    }
  }

  private makeLetter(c: string, pos: number) {
    const classes = classNames({
      'letter': true,
      'error': this.state.errors.indexOf(pos) > -1,
      'complete': pos < this.state.pos
    })

    return (
      <span key={pos} className={classes}>
        {c}
      </span>
    )
  }
}

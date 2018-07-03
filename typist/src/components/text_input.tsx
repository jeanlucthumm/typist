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

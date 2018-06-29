import * as React from 'react';

interface ISquareState {
  active: boolean
}

export default class Square extends React.Component<{}, ISquareState> {
  public readonly state: ISquareState = {
    active: false
  };

  constructor(props: {}) {
    super(props);

    this.activate = this.activate.bind(this);
    this.deactivate = this.deactivate.bind(this);
  }

  public render() {
    const stateClass = (this.state.active) ? 'Square-Active' : 'Square-Inactive';
    return (
      <svg>
        <rect className={stateClass} x='0' y='0' width='100' height='100'
              onMouseEnter={this.activate}
              onMouseLeave={this.deactivate}
        />
      </svg>
    );
  }

  private activate() {
    this.setState({active: true});
  }

  private deactivate() {
    this.setState({active: false});
  }
}

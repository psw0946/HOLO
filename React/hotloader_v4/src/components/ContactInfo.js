import React from 'react';
import { hot } from 'react-hot-loader';

class ContactInfo extends React.Component {
  render() {
    return (
      <div onClick={this.props.onClick}>{this.props.contact.name}</div>
    );
  }
}

export default hot(module)(ContactInfo)

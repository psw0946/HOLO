import React from 'react';
import { hot } from 'react-hot-loader';

class ContactInfo extends React.Component {
  render() {
    return (
      <div>{this.props.contact.name} {this.props.contact.phone}</div>
    );
  }
}

export default hot(module)(ContactInfo)

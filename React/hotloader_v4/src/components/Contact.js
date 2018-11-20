import React from 'react';
import ContactInfo from './ContactInfo'
import ContactDetails from './ContactDetails';
import { hot } from 'react-hot-loader';

class Contact extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      selectedKey: -1,
      keyword: '',
      contactData: [{
        name: 'Abet',
        phone: '010-0000-0001'
      }, {
        name: 'Betty',
        phone: '010-0000-0002'
      }, {
        name: 'Charlie',
        phone: '010-0000-0003'
      }, {
        name: 'David',
        phone: '010-0000-0004'
      }]
    };

    this.handleChange = this.handleChange.bind(this);
    this.handleClick = this.handleClick.bind(this);
  }

  handleChange(e) {
    this.setState({
      keyword: e.target.value
    });
  }

  handleClick(key) {
    this.setState({
      selectedKey: key
    });

    console.log(key, 'is selected');
  }

  render() {
    const mapToComponents = (data) => {
      data.sort((a, b) => { return a.name > b.name; });
      data = data.filter((contact) => {
        return contact.name.toLowerCase().indexOf(this.state.keyword.toLowerCase()) > -1;
      });
      return data.map((contact, i) => {
        return (<ContactInfo contact={contact} key={i} onClick={() => this.handleClick(i)} />);
        // ContactInfo와 같은 자체 제작 componenent는 onClick 메소드가 따로 없어서 props로 전달됨.
        // 받는 태그 쪽에서 onClick 메소드를 props로 전달된 onClick으로 설정해줘야 함.
      });
    };

    return (
      <div>
        <h1>Contacts</h1>
        <input type="text" name="keyword" placeholder="Search" value={this.state.keyword}
          onChange={this.handleChange}/>
        <div>{mapToComponents(this.state.contactData)}</div>
        <ContactDetails isSelected={this.state.selectedKey !== -1}
          contact={this.state.contactData[this.state.selectedKey]}/>
      </div>
    );
  }
}

export default hot(module)(Contact);

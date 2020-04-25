import React, { Component } from 'react';
import { Route, NavLink, Switch } from 'react-router-dom';

import './Blog.css';
import Posts from './Posts/Posts';
import NewPost from './NewPost/NewPost';
import FullPost from './FullPost/FullPost';

class Blog extends Component {
  render () {
    return (
      <div className="Blog">
        <header>
          <nav>
            <ul>
              <li><NavLink
                to="/"
                exact
                activeClassName="my-active"
                activeStyle={{
                  color: '#fa923f',
                  textDecoration: 'underline'
                }}
              >
                Home
              </NavLink></li>
              <li><NavLink to={{
                pathname: '/new-post',
                hash: '#submit', // id 가 submit 인 곳으로 이동
                search: '?quick-submit=true' // query param
              }}>New Post</NavLink></li>
            </ul>
          </nav>
        </header>
        {/*<Route path="/" exact render={() => <h1>Home</h1>} />*/}
        {/*<Route path="/" render={() => <h1>Home 2</h1>} />*/}
        <Route path="/" exact component={Posts} />
        <Switch> {/* 하나 해당되면 거기서 멈추고 더 이상 탐색하지 않음. */}
          <Route path="/new-post" component={NewPost} />
          <Route path="/:id" exact component={FullPost} />
        </Switch>
      </div>
    );
  }
}

export default Blog;

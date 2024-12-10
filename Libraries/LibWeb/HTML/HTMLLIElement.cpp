/*
 * Copyright (c) 2020, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/HTMLLIElementPrototype.h>
#include <LibWeb/HTML/HTMLLIElement.h>
#include <LibWeb/HTML/Numbers.h>
#include <LibWeb/HTML/Window.h>

namespace Web::HTML {

GC_DEFINE_ALLOCATOR(HTMLLIElement);

HTMLLIElement::HTMLLIElement(DOM::Document& document, DOM::QualifiedName qualified_name)
    : HTMLElement(document, move(qualified_name))
{
}

HTMLLIElement::~HTMLLIElement() = default;

void HTMLLIElement::initialize(JS::Realm& realm)
{
    Base::initialize(realm);
    WEB_SET_PROTOTYPE_FOR_INTERFACE(HTMLLIElement);
}

// https://html.spec.whatwg.org/multipage/grouping-content.html#dom-li-value
WebIDL::Long HTMLLIElement::value()
{
    // The value IDL attribute must reflect the value of the value content attribute.
    // NOTE: This is equivalent to the code that would be generated by the IDL generator if we used [Reflect] on the value attribute.
    //       We don't do that in this case, since this method is used elsewhere.
    auto content_attribute_value = get_attribute(AttributeNames::value).value_or("0"_string);
    if (auto maybe_number = HTML::parse_integer(content_attribute_value); maybe_number.has_value())
        return *maybe_number;
    return 0;
}

}
